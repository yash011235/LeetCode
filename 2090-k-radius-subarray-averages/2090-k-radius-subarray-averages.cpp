class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long>prefix(n + 1);
        prefix[0] = 0;
        vector<int>ans(n, -1);
        for(int i = 1; i <= n; i++){
            prefix[i] = prefix[i - 1] + 1LL * nums[i - 1];
        }
        for(int i = 0; i < min(n, k); i++){
            ans[i] = -1;
        }
        for(int i = n - 1; i >= max(0, n - k); i--){
            ans[i] = -1;
        }

        for(int i = min(n, k); i <= max(n - k - 1, 0); i++){
            long long sum = prefix[i + k + 1] - prefix[i - k];
            ans[i] = sum / (2*k + 1);
        }
        return ans;
    }
};