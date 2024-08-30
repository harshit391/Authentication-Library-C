#include <mongoc/mongoc.h>
#include <stdio.h>

int main()
{
	mongoc_client_t *client;
	mongoc_database_t *database;

	mongoc_collection_t *collection;

	bson_t *command, reply;

	bson_error_t error;

	char *str;

	mongoc_init();

	client = mongoc_client_new("mongodb://127.0.0.1:27017");

	if (!client)
	{
		fprintf(stderr, "Failed to connect\n");

		return 1;
	}
	
	printf("Connected\n");
}
