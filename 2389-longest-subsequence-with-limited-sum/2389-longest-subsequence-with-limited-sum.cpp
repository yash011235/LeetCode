class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end()); //nlogn
        int n = nums.size();
        vector<int>prefixSum(n + 1);
        prefixSum[0] = 0;
        for(int i = 1; i <= n; i++){ //n
            prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
        }
        //0 1 3 7 12
        vector<int>ans;
        for(int q : queries){
            int idx = upper_bound(prefixSum.begin(), prefixSum.end(), q) - prefixSum.begin(); //qlogn
            idx--;
            ans.push_back(idx);
        }
        return ans;
    }
};