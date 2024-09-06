// Main Client    
mongoc_client_t *client;

// Collection handle
mongoc_collection_t *collection;

// MongoDB URI
mongoc_uri_t *uri;

// Error handling
bson_error_t error;

// Query and document objects for MongoDB operations 
bson_t *query, *doc;

// Cursor for MongoDB operations like Iterator in Data Structures 
mongoc_cursor_t *cursor;

// Result object for MongoDB operations
const bson_t *result;

// Iterator object for MongoDB operations
bson_iter_t iter;

// Connection string from MongoDB Atlas
char uri_string[130];

void insertDB(char email[]) 
{
    // Initialize the MongoDB driver
    mongoc_init();

    getDataFromFile(uri_string, "database/files/mongouri.txt");

    // Create a MongoDB URI object with options
    uri = mongoc_uri_new_with_error(uri_string, &error);
    
    // Check for errors in URI creation 
    if (!uri) {
        fprintf(stderr, "Failed to parse URI: %s\n", error.message);
        return;
    }

    // Set additional connection options
    mongoc_uri_set_option_as_int32(uri, "serverSelectionTimeoutMS", 5000);
    mongoc_uri_set_option_as_bool(uri, "tlsInsecure", true);  // Only use this for testing!

    // Create a new client instance
    client = mongoc_client_new_from_uri(uri);
    
    // Check for errors in client creation
    if (!client) 
    {
        fprintf(stderr, "Failed to create client\n");
        mongoc_uri_destroy(uri);
        return;
    }

    // Get a handle on the database "testdb" and collection "testcollection"
    collection = mongoc_client_get_collection(client, "testdb", "testcollection");

    // Create query document
    query = BCON_NEW("email", BCON_UTF8(email));

    // Execute find operation
    cursor = mongoc_collection_find_with_opts(collection, query, NULL, NULL);
}


void insertUser(char name[], char password[], char email[])
{
    insertDB(email);
    
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
        printf("Sign Up SuccessFull.\n");
    }

    // Clean up the document
    bson_destroy(doc);

    // Clean up
    mongoc_cursor_destroy(cursor);
    bson_destroy(query);
    mongoc_collection_destroy(collection);
    mongoc_client_destroy(client);
    mongoc_uri_destroy(uri);
    mongoc_cleanup();
}

void updateUser(char email[], char newPass[])
{
    insertDB(email);

    printf("Reseting the Password...\n");
    
    bson_t *update = BCON_NEW("$set", "{", "password", BCON_UTF8(newPass),"}");

    // Updating the User with New Password
    if (!mongoc_collection_update_one(collection, query, update, NULL, NULL, &error))
    {
        fprintf(stderr, "Updation in DB Failed ;- %s\n", error.message);
    }
    else
    {
        printf("Password Reset Success\n");
    }

    // Clean up the document
    bson_destroy(doc);

    // Clean up
    mongoc_cursor_destroy(cursor);
    bson_destroy(query);
    mongoc_collection_destroy(collection);
    mongoc_client_destroy(client);
    mongoc_uri_destroy(uri);
    mongoc_cleanup();
}