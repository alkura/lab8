#include <vector>
#include <iostream>
#include <stdexcept>
#include <climits>

class Algorithms {
public:
    // 1. Пошук мінімального елементу масиву позитивних чисел
    static int findMinPositive(const std::vector<int>& arr) {
        int min = INT_MAX;
        for (int num : arr) {
            if (num > 0 && num < min) {
                min = num;
            }
        }
        if (min == INT_MAX) {
            throw std::invalid_argument("No positive numbers in the array");
        }
        return min;
    }

    // 2. Розрахунок суми елементів масиву, який може складатися лише з від'ємних чисел
    static int sumNegative(const std::vector<int>& arr) {
        int sum = 0;
        for (int num : arr) {
            if (num < 0) {
                sum += num;
            }
            else {
                throw std::invalid_argument("Array contains non-negative numbers");
            }
        }
        return sum;
    }

    // 3. Алгоритм розрахунку N-го елементу послідовності Фібоначчі
    static int fibonacci(int n) {
        if (n < 0) {
            throw std::invalid_argument("N must be non-negative");
        }
        if (n == 0) return 0;
        if (n == 1) return 1;

        int a = 0, b = 1;
        for (int i = 2; i <= n; ++i) {
            int temp = b;
            b = a + b;
            a = temp;
        }
        return b;
    }

    // 4. Алгоритм розрахунку сили струму на ділянці кола: I = U / R
    static double calculateCurrent(double voltage, double resistance) {
        if (resistance <= 0) {
            throw std::invalid_argument("Resistance must be greater than zero");
        }
        return voltage / resistance;
    }
};