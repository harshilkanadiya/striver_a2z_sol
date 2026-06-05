class Solution {
public:
    int minDistance(string text1, string text2) {
        if(text1.size()<text2.size()){
            swap(text1,text2);
        }

        int n=text1.size(),m=text2.size();

            vector<int> prev(m+1,0),curr(m+1,0);

            for(int i=1;i<=n;++i){
                for(int j=1;j<=m;++j){
                if(text1[i-1]==text2[j-1]){
                        curr[j]=1+prev[j-1];
                }else{
                    curr[j]=max(prev[j],curr[j-1]);
                }
                }
                prev=curr;
            }
            
            return n+m-2*prev[m];
    }
};