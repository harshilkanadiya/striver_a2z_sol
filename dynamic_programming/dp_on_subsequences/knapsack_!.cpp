#include <bits/stdc++.h>
using namespace std;
#define fr(i,a,b) for(int i=a;i<b;++i)

int main(){
    int N,W; cin>>N>>W;
    vector <int> w(N);
    vector<long long>v(N);

    fr(i,0,N){
        cin>>w[i]>>v[i];
        
    }

    

   vector<long long> dp(W + 1, 0);
   fr(i,0,N){
    for (int j=W; j>=w[i]; --j){
         dp[j] = max(dp[j], dp[j-w[i]]+v[i]);
    }
   }
   cout<<dp[W];

}