class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
          int n=nums.size(),sum=0;
          for(int i=0;i<n;++i){
            sum+=nums[i];
          }

          if((target+sum)%2!=0 || abs(target)>sum) return 0;
          int t=(target+sum)/2;

          vector<int> dp(t+1, 0);
          dp[0]= 1;

          for (int num : nums) {
            for (int j= t; j >= num; j--) {
                dp[j]= dp[j] + dp[j - num];
            }
        }
        
        return dp[t];

    }
};