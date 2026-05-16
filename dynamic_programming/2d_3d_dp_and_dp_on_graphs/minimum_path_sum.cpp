#include <bits/stdc++.h>
using namespace std;
#define fr(i,a,b) for(int i=a;i<b;++i)
#define rfr(i,a,b) for(int i=a;i>=b;--i)
#define ll long long

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        // we will use dp and take minimum from all the options we can take from

        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(i==0 && j==0) continue;
                else if(i==0) grid[i][j] += grid[i][j-1];
                else if(j==0) grid[i][j] += grid[i-1][j];
                else grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
            }
        }

        return grid[m-1][n-1];
    }
};

int main(){
    int m, n; 
    cin >> m >> n;
    
    vector<vector<int>> grid(m, vector<int>(n));
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }
    
    Solution solve;
    cout << solve.minPathSum(grid) << "\n";
    
    return 0;
}