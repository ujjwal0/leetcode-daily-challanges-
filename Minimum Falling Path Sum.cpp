Minimum Falling Path Sum->

sol-

class Solution {
public:
    int solve(vector<vector<int>> &mat, int i, int j, int m, vector<vector<int>> &dp) {
        if (j < 0 || j >= m) return 1e9; // out of bound
        if (i == 0) return mat[i][j]; // end point - 0th row
        if (dp[i][j] != -1) return dp[i][j]; // Memoization
        int top = mat[i][j] + solve(mat, i - 1, j, m, dp);
        int top_left = mat[i][j] + solve(mat, i - 1, j - 1, m, dp);
        int top_right = mat[i][j] + solve(mat, i - 1, j + 1, m, dp);
        return dp[i][j] = min(top, min(top_left, top_right));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int min_path_sum = 1e9;
        for (int j = 0; j < m; j++) {
            min_path_sum = min(min_path_sum, solve(matrix, n - 1, j, m, dp));
        }
        return min_path_sum;
    }
};
