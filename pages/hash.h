#include <openssl/evp.h>
#include <openssl/sha.h>

void hash_password(char password[], unsigned char *output) {
    
    // Initialize the context
    // This structure is used to maintain the state of the hashing operation
    
    EVP_MD_CTX *mdctx;
    mdctx = EVP_MD_CTX_new();

    // Use SHA-256 as the hashing algorithm
    const EVP_MD *md = EVP_sha256();

    // Initialize the digest
    EVP_DigestInit_ex(mdctx, md, NULL);

    // Provide the password to be hashed
    EVP_DigestUpdate(mdctx, password, strlen(password));

    // Finalize the digest and retrieve the output
    unsigned int output_length;
    EVP_DigestFinal_ex(mdctx, output, &output_length);

    // Clean up
    EVP_MD_CTX_free(mdctx);
}

void hash(char password[]) 
{   
    unsigned char hash_output[1200];

    // Hash the password
    hash_password(password, hash_output);

    // Print the hashed password as a hexadecimal string
    printf("Hashed password: ");
    for(int i = 0; i < 16; i++) {
        printf("%02x", hash_output[i]);
    }
    printf("\n");
}

