minimum path sum->

sol:-

class Solution {
public:
//     int solve(int n,int m,vector<vector<int>>& grid,vector<vector<int>> &dp){
//         if(n==0 && m==0)return grid[n][m];
       
//          if(n<0 || m<0){
//             return INT_MAX;
//         }
        
//         if(dp[n][m]!=-1)return dp[n][m];
//         int left =solve(n-1,m,grid,dp);
//         int right=solve(n,m-1,grid,dp);
//         return dp[n][m]=min(left,right)+grid[n][m];
        
//     }
    
      int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n));
        for(int i =0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i == 0 && j == 0)
                    dp[i][j] = grid[i][j];
                else
                {
                    int left = INT_MAX;
                    int up = INT_MAX;
                    if(i > 0)
                        up = dp[i-1][j];
                    if(j > 0)
                        left = dp[i][j-1];
                    dp[i][j] = grid[i][j] + min(up, left);
                }
            }
        }
        return dp[m-1][n-1];
    }
};
