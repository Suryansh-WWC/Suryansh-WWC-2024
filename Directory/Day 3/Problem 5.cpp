#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;

    long long modExp(long long base, long long exp, long long mod) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }

    int minNonZeroProduct(int p) {
        long long maxNum = (1LL << p) - 1; // The largest number in the range [1, 2^p - 1]
        long long product = maxNum % MOD; // Start with the largest number
        long long multiplier = maxNum - 1; // The second largest number
        long long count = (1LL << (p - 1)) - 1; // Number of pairs

        // Compute the product: (multiplier^(count)) * maxNum
        product = (product * modExp(multiplier, count, MOD)) % MOD;

        return product;
    }
};

int main() {
    Solution solution;

    // Example test case
    int p = 3;
    cout << "Minimum non-zero product: " << solution.minNonZeroProduct(p) << endl;

    return 0;
}

