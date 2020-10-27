#include "unity.h"
#include "unity_fixture.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

int comp(const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}

int comp_char( const void *a, const void *b)
{
    return *(char*)a - *(char*)b;
}

int comp_string(const void *arg1, const void *arg2)                                
{                                                                                                              
    return(strcmp(*(char **)arg1, *(char **)arg2));                   
}

TEST_GROUP(Sort);

TEST_SETUP(Sort)
{
}

TEST_TEAR_DOWN(Sort)
{
}

TEST(Sort, TestSort1)
{
    int ar[] = {4, 3, 2, 1, 0};
    qsort(ar, 6, sizeof(int), comp);
    for(int i=0; i < 6; i++)
    {
        TEST_ASSERT_EQUAL(ar[i],i);
    }
}

TEST(Sort, TestSort2)
{
    int ar[] = {};
    qsort(ar, 0, sizeof(int), comp);
}

TEST(Sort, TestSort3)
{
    int ar[] = {1};
    qsort(ar, 1, sizeof(int), comp);
    TEST_ASSERT_EQUAL(ar[0], 1);
}

TEST(Sort, TestSort4)
{
    int ar[] = {1, 2};
    qsort(ar, 2, sizeof(int), comp);
    TEST_ASSERT_EQUAL(ar[0],1);
    TEST_ASSERT_EQUAL(ar[1],2);

    int ar2[] = {2, 1};
    qsort(ar2, 2, sizeof(int), comp);
    TEST_ASSERT_EQUAL(ar[0],1);
    TEST_ASSERT_EQUAL(ar[1],2);
}

TEST(Sort, TestSort5)
{
    char ar[] = {'b', 'a'};
    qsort(ar, 2, sizeof(char), comp_char);
    TEST_ASSERT_EQUAL(ar[0],'a');
    TEST_ASSERT_EQUAL(ar[1],'b');
}

TEST(Sort, TestSort6)
{
    char str1[] = "ba";
    char str2[] = "ab";
    char *ar[] = {str1, str2};
    qsort(ar, 2, sizeof(char*), comp_string);
    TEST_ASSERT_EQUAL(strcmp("ab",ar[0]), 0);
    TEST_ASSERT_EQUAL(strcmp("ba",ar[1]), 0);
}
