class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum1=0;
        for(int i=0;i<n;++i){
           sum1+=nums[i];
        }
        if(sum1%2!=0) return false;
       int target =sum1/2;
       vector <bool> dp(target+1,false);
       dp[0]=true;

       for(int num: nums){
        for(int j=target;j>=num;--j){
            dp[j]=dp[j]||dp[j-num];
        }
       }

       return dp[target];

    }
};