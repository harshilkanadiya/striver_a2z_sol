class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
         int n=stones.size(),sum=0;
         for(int i=0;i<n;++i){
           sum+=stones[i];
         }

         int target=sum/2;
         vector <bool> dp(target+1,false);
         dp[0]=true;

         for(int i=0;i<n;++i){
            for(int j=target;j>=stones[i];--j){
                dp[j]=dp[j]||dp[j-stones[i]];
            }
         }
        int s1=0;
         for(int j=target;j>=0;--j){
                if(dp[j]){
                    s1=j;
                    break;
                }
            }
        int sol=sum-2*s1;
        return sol;
    }
};