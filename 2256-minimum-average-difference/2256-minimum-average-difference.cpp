class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        long long total = accumulate(nums.begin(), nums.end(), 0LL);
        long long curr = 0;
        int ans = -1;
        int mn = INT_MAX;
        for(int i = 0; i < n - 1; i++){
            curr += 1LL*nums[i];
            if(abs((curr / (i + 1)) - ((total - curr)/(n - i - 1))) < mn){
                mn = abs((curr / (i + 1)) - ((total - curr)/(n - i - 1)));
                ans = i;
            }
        }
        if(mn > (total / n)){
            ans = n - 1;
        }
        return ans;
    }
};