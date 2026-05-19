class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 1) return matrix[0][0];

        vector<int> dp(n);
        dp = matrix[n-1];
        
        for(int i = n - 2; i >= 0; --i){
            vector<int> currRow(n); 
            
            for(int j = 0; j < n; ++j){
                if(j == 0){
                    currRow[j]=matrix[i][j]+min(dp[j], dp[j+1]);
                } else if(j == n - 1){
                    currRow[j]=matrix[i][j]+min(dp[j], dp[j-1]);
                } else {
                    currRow[j]=matrix[i][j]+min({dp[j], dp[j-1], dp[j+1]}); 
                }
            }
            dp = currRow; 
        }
        
        int a = INT_MAX;
        for(int i = 0; i < n; ++i){
            a = min(a, dp[i]);
        }
        return a;
    }
};