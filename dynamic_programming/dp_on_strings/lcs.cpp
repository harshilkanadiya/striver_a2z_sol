#include <bits/stdc++.h>
using namespace std;

int main(){
    string s1,s2; 
    cin>>s1>>s2;

    if(s1.size()<s2.size()){
        swap(s1,s2);
    }
    int n=s1.size(),m=s2.size();

    vector <char> ans;
    
    // so i need to find lcs and print it 
    vector <string> curr(m+1,""),prev(m+1,"");

    for(int i=1;i<=n;++i){
       for(int j=1;j<=m;++j){
        if(s1[i-1]==s2[j-1]){
          curr[j] = prev[j - 1] + s1[i - 1];
        }else{
            if(prev[j].length() > curr[j - 1].length()) {
                    curr[j] = prev[j];
                } else {
                    curr[j] = curr[j - 1];
                }
        }

       }
       prev=curr;
    }

    cout<<prev[m]<<endl;

}
