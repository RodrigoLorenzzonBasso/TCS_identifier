#include "unity.h"
#include "unity_fixture.h"

#include "../identifier.h"
#include <string.h>

char id[20];

TEST_GROUP(Identifier);

TEST_SETUP(Identifier)
{
}

TEST_TEAR_DOWN(Identifier)
{
}

TEST(Identifier, TestIdentifier1)
{
    strcpy(id,"abc123");
    TEST_ASSERT_EQUAL(0, identifier(id));
}

TEST(Identifier, TestIdentifier2)
{
	strcpy(id,"1abc");
	TEST_ASSERT_EQUAL(1, identifier(id));
}

TEST(Identifier, TestIdentifier3)
{
	strcpy(id,"abcdefg");
	TEST_ASSERT_EQUAL(1, identifier(id));
}

TEST(Identifier, TestIdentifier4)
{
	strcpy(id,"abcd&fg");
	TEST_ASSERT_EQUAL(1, identifier(id));
}
TEST(Identifier, TestIdentifier5)
{
	strcpy(id,"a");
	TEST_ASSERT_EQUAL(0, identifier(id));
}
TEST(Identifier, TestIdentifier6)
{
	strcpy(id,"uvwxyz");
	TEST_ASSERT_EQUAL(0, identifier(id));
}
TEST(Identifier, TestIdentifier7)
{
	strcpy(id,"");
	TEST_ASSERT_EQUAL(1, identifier(id));
}
TEST(Identifier, TestIdentifier8)
{
	strcpy(id,"1abcde");
	TEST_ASSERT_EQUAL(1, identifier(id));
}
TEST(Identifier, TestIdentifier9)
{
	strcpy(id,"a12345");
	TEST_ASSERT_EQUAL(0, identifier(id));
}
TEST(Identifier, TestIdentifier10)
{
	strcpy(id,"%");
	TEST_ASSERT_EQUAL(1, identifier(id));
}
TEST(Identifier, TestIdentifier11)
{
	strcpy(id,"%%%%%%");
	TEST_ASSERT_EQUAL(1, identifier(id));
}
TEST(Identifier, TestIdentifier12)
{
	strcpy(id,"%%%%%%%");
	TEST_ASSERT_EQUAL(1, identifier(id));
}
