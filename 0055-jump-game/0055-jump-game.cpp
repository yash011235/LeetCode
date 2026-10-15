class Solution {
public:
    int n;
    bool canJump(vector<int>& nums) {
        n = nums.size();
        vector<int>dp(n + 1, false);
        dp[n - 1] = true;
        for(int i = n - 2; i >= 0; i--){
            for(int j = i; j < n && j <= i + nums[i]; j++){
                if(dp[j]){
                    dp[i] = true;
                    j = i + nums[i];
                }
            }
        }
        return dp[0];
    }
};