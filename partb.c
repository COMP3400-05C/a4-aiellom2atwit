#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>


/**
 * @brief Takes any number of arguments and prints the middle one or two words
 * 
 * @param argc Count of arguments
 * @param argv Char array of user arguments
 * @return int Return 1 for failure, 0 for success
 */
int main(int argc, const char* argv[]) {
    //checks for invalid argument count
    if (argc < 2) {
        printf("ERROR: No arguments\n");
        //print 1 for failure
        return 1;
    }
    
    if ((argc - 1) % 2 == 0) {
        //even arg count, print 2 words
        int middleNum1 = (argc - 1)/2;
        int middleNum2 = (argc - 1)/2 + 1;
        printf("%s %s", argv[middleNum1], argv[middleNum2]);
    } else {
        //odd arg count, print 1 word
        int middleNum = (argc - 1)/2 + 1;
        printf("%s", argv[middleNum]);
    }
    //return success
    return 0;
}
