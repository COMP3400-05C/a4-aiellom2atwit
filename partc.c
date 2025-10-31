#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


/**
 * @brief Takes a file name and search word from the user and determines if the word can be found in a valid file
 * 
 * @param argc Number of arguments
 * @param argv Char array arguments containing search word and file name
 * @return int Returs 1 if incorrect arguments, 2 if the file doesn't exist, 0 if successful
 */
int main(int argc, const char* argv[]) {
    //checks for invalid argument count
    if (argc != 3) {
        printf("ERROR: No arguments\n");
        //print 1 for failure
        return 1;
    }

    //defines the searchword and filename from args
    const char *word = argv[1];
    const char *filename = argv[2];

    //opens file from filename
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        //file doesn't exist, return error
        printf("ERROR: %s doesn't exist\n", filename);
        return 2; // special code for missing file
    }

    //initialize temp char variable and found boolean variable to search
    bool found = false;
    char temp[100];

    //read file
    while (fscanf(file, "%99s", temp) == 1) {
        //determine if word is found
        if (strstr(temp, word) != NULL) {
            found = true;
            break;
        }
    }

    //print whether word was found or not
    if (found) {
        printf("FOUND: %s\n", word);
    } else {
        printf("NOT FOUND: %s\n", word);
    }

    //return success
    return 0;
}
