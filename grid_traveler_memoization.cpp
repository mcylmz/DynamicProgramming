#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;


/**
 * Brute force:
 * O(2^(n + m)) : time
 * O(n + m) : space
 * 
 * Memoized:
 * O(m * n) : time
 * O(m + n) : space
 */
unordered_map<string, long> memo;

long gridTraveler(int m, int n) {
    if (m == 1 && n == 1) return 1;
    if (m == 0 || n == 0) return 0;
    
    string key = to_string(m) + "," + to_string(n);
    auto itr = memo.find(key);
    if (itr == memo.end())
        memo[key] = gridTraveler(m - 1, n) + gridTraveler(m, n - 1);

    return memo[key];
}

int main() {
    cout << gridTraveler(1, 1) << endl; // 1
    cout << gridTraveler(2, 3) << endl; // 3
    cout << gridTraveler(3, 2) << endl; // 3
    cout << gridTraveler(3, 3) << endl; // 6
    cout << gridTraveler(18, 18) << endl; // 2333606202

    return 0;
}