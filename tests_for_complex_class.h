#ifndef COMPLEX_TESTS_FOR_COMPLEXH
#define COMPLEX_TESTS_FOR_COMPLEXH

#include "framework_for_unit_tests.h"
#include "complex.h"
#include <iostream>

void TestBinArithOperations() {
    Complex complex1(1, 2);
    Complex complex2(2, 3);
    Complex complex3(2, 2);
    Complex complex4(3, 5);
    ASSERT_EQUAL(complex1 + complex2, complex4);
    ASSERT_EQUAL(complex4 - complex1, complex2);
    ASSERT_EQUAL(complex1 + 1, complex3);
    ASSERT_EQUAL(complex3 - 1, complex1);
    ASSERT_EQUAL(1 + complex1, complex3);
    ASSERT_EQUAL((1 -  complex3) * (-1), complex1);
}

void TestComparisonOperators() {
    Complex complex1(1, 2);
    Complex complex2(1, 2);
    Complex complex3(2, 2);
    ASSERT(complex1 == complex2);
    ASSERT(complex1 != complex3);
}

void TestAbs() {
    Complex complex(3, 4);
    ASSERT_EQUAL(complex.Abs(), 5);
}

void TestAssignment() {
    Complex complex1(1, 2);
    Complex complex2 = complex1;
    ASSERT_EQUAL(complex1, complex2);
}

void TestComplexClass() {
    TestBinArithOperations();
    TestComparisonOperators();
    TestAbs();
    TestAssignment();
    std::cerr << "Все тесты завершены корректно"s << std::endl;
}

#endif