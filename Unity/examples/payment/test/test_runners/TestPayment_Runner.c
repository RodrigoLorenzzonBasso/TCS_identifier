#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP_RUNNER(Payment)
{
  RUN_TEST_CASE(Payment, TestPayment1);
  RUN_TEST_CASE(Payment, TestPayment2);
  RUN_TEST_CASE(Payment, TestPayment3);
  RUN_TEST_CASE(Payment, TestPayment4);
  RUN_TEST_CASE(Payment, TestPayment5);
  RUN_TEST_CASE(Payment, TestPayment6);
  RUN_TEST_CASE(Payment, TestPayment7);
  RUN_TEST_CASE(Payment, TestPayment8);
}
