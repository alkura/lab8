#include "pch.h"
#include "CppUnitTest.h"
#include <iostream>
#include "../ConsoleApplication1/ConsoleApplication1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests {

    TEST_CLASS(TestAlgorithms) {
public:
    // Тести для findMinPositive
    TEST_METHOD(TestFindMinPositive_Valid) {
        std::vector<int> arr = { 3, 5, 1, 7 };
        Assert::AreEqual(1, Algorithms::findMinPositive(arr));
    }

    TEST_METHOD(TestFindMinPositive_NoPositives) {
        std::vector<int> arr = { -3, -5, -7 };
        auto func = [&]() { Algorithms::findMinPositive(arr); };
        Assert::ExpectException<std::invalid_argument>(func);
    }

    // Тести для sumNegative
    TEST_METHOD(TestSumNegative_Valid) {
        std::vector<int> arr = { -1, -2, -3 };
        Assert::AreEqual(-6, Algorithms::sumNegative(arr));
    }

    TEST_METHOD(TestSumNegative_InvalidArray) {
        std::vector<int> arr = { -1, -2, 3 };
        auto func = [&]() { Algorithms::sumNegative(arr); };
        Assert::ExpectException<std::invalid_argument>(func);
    }

    // Тести для fibonacci
    TEST_METHOD(TestFibonacci_Valid) {
        Assert::AreEqual(5, Algorithms::fibonacci(5));
    }

    TEST_METHOD(TestFibonacci_NegativeInput) {
        auto func = [&]() { Algorithms::fibonacci(-1); };
        Assert::ExpectException<std::invalid_argument>(func);
    }

    // Тести для calculateCurrent
    TEST_METHOD(TestCalculateCurrent_Valid) {
        Assert::AreEqual(2.0, Algorithms::calculateCurrent(10, 5), 0.001);
    }

    TEST_METHOD(TestCalculateCurrent_InvalidResistance) {
        auto func = [&]() { Algorithms::calculateCurrent(10, 0); };
        Assert::ExpectException<std::invalid_argument>(func);
    }
    };

}