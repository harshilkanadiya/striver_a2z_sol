#include <bits/stdc++.h>
using namespace std;
#define fr(i,a,b) for(int i=a;i<b;++i)
#define rfr(i,a,b) for(int i=a;i>=b;--i)
#define ll long long

class Solution {
public:
    int uniquePaths(int m, int n) {

        vector <int> curr(n,1);
       
       // for current state i need either c-1 or r-1 
       for(int j=1;j<m;++j){
          for(int i=1;i<n;++i){
             curr[i]=curr[i-1]+curr[i];
          }
       }
       return curr[n-1];
    }
};

int main(){
    int n,m; cin>>n>>m;
    Solution solve;
    cout<<solve.uniquePaths(m,n);
}