/**
 * Fibonacci memoization
 */
#include <iostream>
#include <unordered_map>
using namespace std;


unordered_map<int, long> memo;

/**
 * fibonacci memoized complexity:
 * -> O(n) time
 * -> O(n) space
 * otherwise:
 * -> O(2^n) time
 * -> O(n) space
 */
int fibonacci(int n) {
    auto fib = memo.find(n);
    if (fib == memo.end()) {
        if (n <= 2)
            memo[n] = 1;
        else
            memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
    }

    return memo[n];
}

int main() {
    cout << fibonacci(6) << endl;
    cout << fibonacci(7) << endl;
    cout << fibonacci(8) << endl;
    cout << fibonacci(46) << endl;

    return 0;
}