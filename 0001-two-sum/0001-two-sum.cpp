class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int>idx;
        for(int i = 0; i < n; i++){
            int need = target - nums[i];
            if(idx.count(need)){
                return {idx[need], i};
            }
            idx[nums[i]] = i;
        }
        return {-1, -1};
    }
};