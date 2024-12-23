#include <iostream>
using namespace std;

class Solution {
public:
    int findTheWinner(int n, int k) {
        int winner = 0; // Start with the base case for 1 friend
        for (int i = 2; i <= n; ++i) {
            winner = (winner + k) % i; // Update winner index for i friends
        }
        return winner + 1; // Convert 0-based index to 1-based index
    }
};

int main() {
    Solution solution;

    // Example test case
    int n = 5; // Number of friends
    int k = 2; // Steps to count
    cout << "The winner is friend: " << solution.findTheWinner(n, k) << endl;

    return 0;
}
