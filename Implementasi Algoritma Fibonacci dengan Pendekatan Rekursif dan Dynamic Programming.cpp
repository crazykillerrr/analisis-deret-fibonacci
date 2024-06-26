#include <iostream>
#include <chrono>
#include <vector>
#include <iomanip>

using namespace std;
using namespace std::chrono;

// Pendekatan Rekursif
unsigned long long fibonacci_recursive(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

// Pendekatan Dynamic Programming
unsigned long long fibonacci_dynamic(int n) {
    if (n <= 1) {
        return n;
    }
    vector<unsigned long long> fib(n + 1, 0);
    fib[1] = 1;
    for (int i = 2; i <= n; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    return fib[n];
}

void measure_time(int n) {
    auto start = high_resolution_clock::now();
    auto result_recursive = fibonacci_recursive(n);
    auto stop = high_resolution_clock::now();
    auto duration_recursive = duration_cast<microseconds>(stop - start);


    start = high_resolution_clock::now();
    auto result_dynamic = fibonacci_dynamic(n);
    stop = high_resolution_clock::now();
    auto duration_dynamic = duration_cast<microseconds>(stop - start);

    
    cout << "n = " << setw(2) << n
         << " | Rekursif: " << setw(12) << duration_recursive.count() << " microseconds"
         << " | Dynamic: " << setw(12) << duration_dynamic.count() << " microseconds"
         << " | Hasil: " << result_dynamic << endl;
}

int main() {
    vector<int> test_values = {10, 25, 30, 40, 50};

    cout << "Perbandingan Waktu Eksekusi Fibonacci\n";
    cout << "------------------------------------\n";
    for (int n : test_values) {
        measure_time(n);
    }

    return 0;
}
