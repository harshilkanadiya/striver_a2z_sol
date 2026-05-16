#include <bits/stdc++.h>
using namespace std;
#define fr(i,a,b) for(int i=a;i<b;++i)
#define rfr(i,a,b) for(int i=a;i>=b;--i)
#define ll long long

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // we will move upwards with this one 
        int n = triangle.size();
        vector<int> dp = triangle[n-1];
        
        for (int i = n - 2; i >= 0; --i) {
            for (int j = 0; j <= i; ++j) {
                dp[j] = triangle[i][j] + min(dp[j], dp[j+1]);
            }
        }

        return dp[0];
    }
};

int main() {
    int n; 
    cin >> n;
    
    vector<vector<int>> triangle(n);
    for(int i = 0; i < n; ++i) {
        triangle[i].resize(i + 1);
        for(int j = 0; j <= i; ++j) {
            cin >> triangle[i][j];
        }
    }
    
    Solution solve;
    cout << solve.minimumTotal(triangle) << "\n";
    
    return 0;
}