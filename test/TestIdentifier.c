#include "unity.h"
#include "unity_fixture.h"

#include "../identifier.h"
#include <string.h>


TEST_GROUP(Identifier);

TEST_SETUP(Identifier)
{
}

TEST_TEAR_DOWN(Identifier)
{
}

TEST(Identifier, TestIdentifier1)
{
    char id[20] = "abc";
    TEST_ASSERT_EQUAL(0, identifier(id));
    //char id2[20] = "1abc";
    //TEST_ASSERT_EQUAL(1, identifier(id2));
    
}

