/*
 * This File contains the Implementation for Singla Hashing Algorithm :)
 */

/* Header Files */
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>

/* Lookup  */
int sc[] = {94, 99, 47, 103, 72, 121, 36, 123, 93, 98, 115, 41, 106, 111, 113, 75, 40, 60, 71, 124, 62, 107, 64, 45, 43, 96, 118, 95, 34, 112, 69, 74, 70, 67, 120, 68, 73, 117, 59, 33, 125, 42, 37, 108, 102, 92, 39, 105, 63, 110, 58, 38, 91, 35, 46, 104, 126, 116, 97, 100, 114, 61, 44, 65, 119, 66, 122, 101, 109};

/* Reverse Lookup */
int revsc[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 39, 28, 53, 6, 42, 51, 46, 16, 11, 41, 24, 62, 23, 54, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 50, 38, 17, 61, 20, 48, 22, 63, 65, 33, 35, 30, 32, 18, 4, 36, 31, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 52, 45, 8, 0, 27, 25, 58, 9, 1, 59, 67, 44, 3, 55, 47, 12, 21, 43, 68, 49, 13, 29, 14, 60, 10, 57, 37, 26, 64, 34, 5, 66, 7, 19, 40, 56};

/* Secret Key */
char secret[] = "sajneet";

/* 2nd Secret Key  */
int arr2[] = {19, 1, 10, 14, 5, 5, 20};

/* Function Declarations */
void decode(char arr1[], char arr2[]);
bool compare(char arr1[], char arr2[]);
void encode(char arr1[], char arr2[]);
void enterAndHashPassword(char arr[]);