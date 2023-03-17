#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>
#include "tests.h"


// The strchr function is used to locate a character in a string. 
// More specifically, it returns a pointer to the first occurrence of the character in the string and NULL otherwise. 
// Write a function my_strchr, with the same parametersand return value as strchr.
const char* my_strchr(const char* s, char character) {
    // TODO your code here
    char* a = s;
    char* b = &character;
    int i=0;
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
    return a+i;
}
int main()
{
    
#if ENABLE_TESTS > 0
    run_tests(true);
#endif

    return 0;
}
