#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>
#include "tests.h"

// Write a function that takes as an input an array of integer numbers (both positive and negative numbers and returns the value of the triplet with the maximum product, as well as the elements that form this triplet (in increasing order). 
// Use pass by pointer/address to return the elements that form that triplet. 
// Think about the appropriate data type for the result. If the size of the array is less than 3, you should return the minimum
// representable value of the data type and the elements that form the triplet should be set to 0.
int minn(int a,int b)
{
    if (a < b)
        return a;
    return b;
    
}
int maxx(int a, int b)
{
    if (a > b)
        return a;
    return b;

}
long long computeMaxTriplet(int arr[],unsigned int sz, int* t1, int* t2, int* t3){
    int  i, j, k,h;
    long long maxi = LLONG_MIN,f,g,r;
    if (sz < 3)
    {
        *t1 = 0;
            * t2 = 0;
            *t3 = 0;
    }
    else
    {
        for (i = 0;i <= sz-3 ;i++)
            for (j = i + 1;j <= sz-2 ;j++)
                for (k = j + 1;k <= sz-1 ;k++)
                {
                    f = arr[i];
                    g = arr[j];
                    r = arr[k];

                    if (maxi < f * g * r)
                    {
                        maxi = f * g * r;
                        *t1 = minn(arr[i], minn(arr[j], arr[k]));
                        h = maxx(minn(arr[i], arr[j]), minn(arr[j], arr[k]));
                        *t2 = maxx(minn(arr[i], arr[k]), h);
                        *t3 = maxx(arr[i], maxx(arr[j], arr[k]));
                    }
                }
    }

    // TODO your code here
    return maxi;
}

int main()
{
    int   i, t1=0, t2=0, t3=0;
    unsigned int sz;
    printf("size=");
    scanf("%u", &sz);
    int arr[101];
    for(i=0;i<=sz-1;i++)
    {
        printf("arr[");
        printf("%d", i);
        printf("]=");
        scanf("%d", &arr[i]);
    }
    long long  a=0;
    a = computeMaxTriplet(arr, sz, &t1, &t2, &t3);
    if (sz < 3)
    {
        printf("The array has less than 3 elements. Application will now stop.");
        printf("%lld", a);
    }
    else
    {
        printf("The maximum triplet is (");
        printf("%d", t1);
        printf(",");
        printf("%d", t2);
        printf(",");
        printf("%d", t3);
        printf(")");
        printf(" with a product of ");
        printf("%lld", t1*t2*t3);
        printf("\n");
    }

#if ENABLE_TESTS > 0
    run_tests(true);
#endif
    
    return 0;
}
