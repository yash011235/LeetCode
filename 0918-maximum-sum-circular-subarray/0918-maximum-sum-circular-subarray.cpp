class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        long long maxsum = nums[0];
        long long currsum = nums[0];
        for(int i = 1; i < n; i++){
            currsum = max(1LL* nums[i], currsum + 1LL * nums[i]);
            maxsum = max(maxsum, currsum);
        }
        long long minsum = nums[0];
        long long currsum1 = nums[0];
        for(int i = 1; i < n; i++){
            currsum1 = min(1LL * nums[i], currsum1 + 1LL*nums[i]);
            minsum = min(minsum, currsum1);
        }
        int ele = *max_element(nums.begin(), nums.end());
        if(ele < 0){
            return ele;
        }
        int ans = max(maxsum, sum - minsum);
        return ans;
    }
};