#include "unity.h"
#include "unity_fixture.h"

#include "payment.h"
#include <string.h>


TEST_GROUP(Payment);

TEST_SETUP(Payment)
{
}

TEST_TEAR_DOWN(Payment)
{
}

TEST(Payment, TestPayment1)
{
    float v = 100.00;
    char status[20] = "estudante";
    TEST_ASSERT_EQUAL(0, payment(v,status));
    v = 101.00;
    TEST_ASSERT_EQUAL(0, payment(v,status));
}

TEST(Payment, TestPayment2)
{
    float v = 0.0001;
    char status[20] = "regular";
    TEST_ASSERT_EQUAL(1, payment(v,status));
    v = -0.01;
    strcpy(status,"aposentado");
    TEST_ASSERT_EQUAL(1, payment(v,status));
}

TEST(Payment, TestPayment3)
{
    float v = 100.00;
    char status[20] = "abcdef";
    TEST_ASSERT_EQUAL(2, payment(v,status));
    v = 101.00;
    strcpy(status,"vip");
    TEST_ASSERT_EQUAL(2, payment(v,status));
}

TEST(Payment, TestPayment4)
{
    float v = 0.001;
    char status[20] = "abcdef";
    TEST_ASSERT_EQUAL(1, payment(v,status));
}

TEST(Payment, TestPayment5)
{
    float v = 0.01;
    char status[20] = "VIP";
    TEST_ASSERT_EQUAL(0, payment(v,status));
    strcpy(status,"vip");
    TEST_ASSERT_EQUAL(2, payment(v,status));
}

TEST(Payment, TestPayment6)
{
    float v = 99999.00;
    char status[20] = "aposentado";
    TEST_ASSERT_EQUAL(0, payment(v,status));
    v = 99999.01;
    TEST_ASSERT_EQUAL(1, payment(v,status));
}

TEST(Payment, TestPayment7)
{
    float v = 0.009;
    char status[20] = "VIP";
    TEST_ASSERT_EQUAL(1, payment(v,status));
}

TEST(Payment, TestPayment8)
{
    float v = 99999.01;
    char status[20] = "regular";
    TEST_ASSERT_EQUAL(1, payment(v,status));
    v = 0.01;
    strcpy(status,"regula");
    TEST_ASSERT_EQUAL(2, payment(v,status));
}

