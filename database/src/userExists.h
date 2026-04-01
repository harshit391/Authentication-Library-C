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

void getDataFromFile(char arr1[], char arr2[]);

void setup(char email[])
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

bool userExists(char email[]) 
{
    // Initialize the MongoDB driver and setup the connection
    setup(email);

    // Process the result if email exists in the database
    bool found = mongoc_cursor_next(cursor, &result) ? true : false;

    // Clean up
    mongoc_cursor_destroy(cursor);
    bson_destroy(query);
    mongoc_collection_destroy(collection);
    mongoc_client_destroy(client);
    mongoc_uri_destroy(uri);
    mongoc_cleanup();

    return found;
}

void getPassword(char email[], char password[], size_t password_size)
{
    setup(email);

    // Advance the cursor to get the result document
    if (mongoc_cursor_next(cursor, &result))
    {
        // Process the result if email exists in the database
        bson_iter_t iter;

        if (bson_iter_init_find(&iter, result, "password"))
        {
            if (BSON_ITER_HOLDS_UTF8(&iter))
            {
                const char *db_password = bson_iter_utf8(&iter, NULL);

                // Use the provided size to safely copy the password
                strncpy(password, db_password, password_size - 1);

                password[password_size - 1] = '\0'; // Null-terminate the string
            }
        }
    }

    // Clean up
    mongoc_cursor_destroy(cursor);
    bson_destroy(query);
    mongoc_collection_destroy(collection);
    mongoc_client_destroy(client);
    mongoc_uri_destroy(uri);
    mongoc_cleanup();
}

