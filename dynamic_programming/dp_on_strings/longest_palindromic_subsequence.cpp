class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string s_rev = s;
        reverse(s_rev.begin(), s_rev.end());

        int n=s.size(),m=s.size();
      vector<int> prev(m+1,0),curr(m+1,0);

        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
               if(s[i-1]==s_rev[j-1]){
                    curr[j]=1+prev[j-1];
               }else{
                curr[j]=max(prev[j],curr[j-1]);
               }
            }
            prev=curr;
        }
        
        return prev[m];   
    }
};