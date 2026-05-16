#include <bits/stdc++.h>
using namespace std;
#define fr(i,a,b) for(int i=a;i<b;++i)
#define rfr(i,a,b) for(int i=a;i>=b;--i)
#define ll long long

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // if we encounter any obstacle we will deal it as non takable option 
        
        int m=obstacleGrid.size(),n=obstacleGrid[0].size();

        if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) {
            return 0;
        }

        vector <vector<int>> dp(m,vector<int>(n,0));
        dp[0][0] = 1;

        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(obstacleGrid[i][j]==1){
                    dp[i][j]=0;
                }else{
                    if(i > 0) dp[i][j] += dp[i-1][j];
                    if(j > 0) dp[i][j] += dp[i][j-1];
                }
            }
        }

        return dp[m-1][n-1];
    }
};

int main(){
    int n,m; cin>>n>>m;

    vector<vector<int>> obstacleGrid(m, vector<int>(n));
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> obstacleGrid[i][j];
        }
    }

    Solution solve;
    cout << solve.uniquePathsWithObstacles(obstacleGrid);
}