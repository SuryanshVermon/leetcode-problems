#include <vector>
#include <algorithm>
#include <numeric>
#include <cstring>

class Solution {
public:
    int dp[101][101]; // Use a dp table for memoization

    int stoneGameII(std::vector<int>& A) {
        int N = A.size();
        
        // Compute suffix sums
        for (int i = N - 2; i >= 0; --i) {
            A[i] += A[i + 1];
        }
        
        // Initialize the dp table with -1 to indicate uncomputed states
        std::memset(dp, -1, sizeof(dp));
        
        // Start the recursion
        return helper(A, 0, 1, N);
    }
    
    int helper(std::vector<int>& A, int i, int m, int N) {
        // Base case
        if (i + 2 * m >= N) return A[i];
        
        // Return the cached value if it has been computed
        if (dp[i][m] != -1) return dp[i][m];
        
        int min_opponent_score = INT_MAX;
        for (int x = 1; x <= 2 * m; ++x) {
            min_opponent_score = std::min(min_opponent_score, helper(A, i + x, std::max(m, x), N));
        }
        
        // The result for this state
        dp[i][m] = A[i] - min_opponent_score;
        return dp[i][m];
    }
};
