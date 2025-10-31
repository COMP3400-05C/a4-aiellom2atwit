#include <stdbool.h>
#include <stddef.h>
#include <ctype.h>
#include <stdio.h>

/**
 * @brief Takes user arguments and prints them capitalized with commas in between
 * 
 * @param argc The integer count of arguments
 * @param argv A 2D character array containing all user's inputs
 * @return int Returns 1 if unsuccessful, 0 if successful
 */
int main(int argc, const char* argv[]) {

    //checks for invalid argument count
    if (argc < 2) {
        printf("ERROR: No arguments\n");
        //print 1 for failure
        return 1;
    }

    //loop through first dimension of arguments
    for (int i = 1; i < argc; i++) {
        //loop through each letter in word until end of word
        for (int j = 0; argv[i][j] != '\0'; j++) {
            //print the uppercase letter
            putchar(toupper(argv[i][j]));
        }

        //between argument words, print a comma
        if (i < argc -1) {
            putchar(',');
        }
    }
    //enter a new line and return 0 for success
    putchar('\n');
    return 0;
}
