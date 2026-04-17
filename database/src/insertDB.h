bool connectDB(char email[])
{
    getDataFromFile(uri_string, "database/files/mongouri.txt", sizeof(uri_string));

    // Create a MongoDB URI object with options
    uri = mongoc_uri_new_with_error(uri_string, &error);

    // Check for errors in URI creation
    if (!uri) {
        fprintf(stderr, "Failed to parse URI: %s\n", error.message);
        return false;
    }

    // Set additional connection options
    mongoc_uri_set_option_as_int32(uri, "serverSelectionTimeoutMS", 5000);

    // Create a new client instance
    client = mongoc_client_new_from_uri(uri);

    // Check for errors in client creation
    if (!client)
    {
        fprintf(stderr, "Failed to create client\n");
        mongoc_uri_destroy(uri);
        return false;
    }

    // Get a handle on the database "testdb" and collection "testcollection"
    collection = mongoc_client_get_collection(client, "testdb", "testcollection");

    // Create query document for matching the user by email
    query = BCON_NEW("email", BCON_UTF8(email));

    return true;
}


void insertUser(char name[], char password[], char email[])
{
    if (!connectDB(email))
    {
        fprintf(stderr, "Sign Up Failed: Database connection error\n");
        return;
    }

    // Create a new document to insert
    doc = BCON_NEW(
        "name", BCON_UTF8(name),
        "email", BCON_UTF8(email),
        "password", BCON_UTF8(password)
    );

    printf("Adding New User...\n");

    // Insert the document
    if (!mongoc_collection_insert_one(collection, doc, NULL, NULL, &error))
    {
        fprintf(stderr, "Sign Up Failed: %s\n", error.message);
    }
    else
    {
        printf("Sign Up Successful.\n");
    }

    // Clean up the document
    bson_destroy(doc);

    // Clean up
    bson_destroy(query);
    mongoc_collection_destroy(collection);
    mongoc_client_destroy(client);
    mongoc_uri_destroy(uri);
}

void updateUser(char email[], char newPass[])
{
    if (!connectDB(email))
    {
        fprintf(stderr, "Password Reset Failed: Database connection error\n");
        return;
    }

    printf("Resetting the Password...\n");

    bson_t *update = BCON_NEW("$set", "{", "password", BCON_UTF8(newPass),"}");

    // Updating the User with New Password
    if (!mongoc_collection_update_one(collection, query, update, NULL, NULL, &error))
    {
        fprintf(stderr, "Database update failed: %s\n", error.message);
    }
    else
    {
        printf("Password Reset Success\n");
    }

    // Clean up the update document
    bson_destroy(update);

    // Clean up
    bson_destroy(query);
    mongoc_collection_destroy(collection);
    mongoc_client_destroy(client);
    mongoc_uri_destroy(uri);
}
