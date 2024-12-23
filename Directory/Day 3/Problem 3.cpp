#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Base case: When the range contains only one element
        for (int i = 0; i < n; ++i) {
            dp[i][i] = nums[i];
        }

        // Fill DP table for ranges of increasing length
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                // Player 1 chooses the best score they can get between nums[i] or nums[j]
                dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
            }
        }

        // dp[0][n-1] contains the maximum score difference Player 1 can achieve
        return dp[0][n - 1] >= 0;
    }
};

int main() {
    Solution solution;

    // Example test case
    vector<int> nums = {1, 5, 2};
    if (solution.PredictTheWinner(nums)) {
        cout << "Player 1 can win the game." << endl;
    } else {
        cout << "Player 1 cannot win the game." << endl;
    }

    return 0;
}
