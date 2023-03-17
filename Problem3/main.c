#include <stdio.h>
#include <limits.h>
#include "tests.h"
#include <stdlib.h>
#include<string.h>

// Using the function that you wrote for problem 2, write a function that computesand returns an array with all the positions of the occurrences of a character in a string.
const char* my_strchr(const char* s, char character) {
    // TODO your code here
    char* a = s;
    char* b = &character;
    int i = 0;
    char c;
    c = *(a + 0);
    if (c == character)
        return a + i;
    while (c != character && c != NULL)
    {
        i++;
        c = *(a + i);
    }
    if (c == NULL)
        return NULL;
    return a + i;
}
void find_all( const char * str, char character, int*  positions, unsigned int cap, unsigned int * l){
    int i,j=0;
    //int* position;
    //position = (int*) malloc (cap * sizeof(int));
    //if (!position) {
        //printf("Error! Failed to allocate memory!");
       // exit(-1);
   // }

    l = 0;
    for (i = 0;i <= cap - 1;i++)
    {
        positions[i] = -1;
        printf("%d", positions[i]);
    }
    
    i = 0;
    int n = strlen(str);
    while (i < n && j < cap) 
    {
        char* res = my_strchr(str + i, character);
        if (res == NULL) break;

        // ind = 2 -> dupa caut de la 3
        ++l;
        int ind = res - str;
        positions[j++] = ind;
        
        i = ind + 1;
    }
 }

int main()
{
#if  ENABLE_TESTS > 0
    run_tests(true);
#endif 

    return 0;
}
