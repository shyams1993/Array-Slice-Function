/* C Implementation of Array Slicing */

#include <stdio.h>
#include <stdlib.h>

/* Function prototype declaration */
/* The Slice function is supposed to return a character pointer to a string */

char *slice(char *string, int start, int stop, int steps);

/* Takes an input string, start index, stop index & the number of steps as arguments from the main function */

int main(void)
{
    char *string = "Shyam Salil";
    char *slicedWord = slice(string, 0, 7, 1);
    printf("%s\n", slicedWord);
    free(slicedWord);
}

/* The input string, start index, stop index and number of steps are passed as arguments to the slice function definition by the main function */
/* Simply, creates a variable that will hold the sliced string (a pointer to the first character) */
/* This is done by allocating memory || Note: Allocate 1 byte of extra memory so that the null character can be stored */

char *slice(char *string, int start, int stop, int steps)
{
    int length = (stop - start) + 1;
    char *result = malloc(sizeof(char) * length);
    int counter = 0, i = start;
    while (i != stop)
    {
        result[counter] = string[i];
        counter++;
        i += steps;
    }
    result[counter] = '\0';
    return result;
}

/* Important: Whenever you create a string, always leave one byte space to hold the null character to mark the termination of string. 
Otherwise there are chances you may receive a garbage value */
/* Note: Free the memory via the main function */
