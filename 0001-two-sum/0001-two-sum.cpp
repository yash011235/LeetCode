class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int>idx;
        for(int i = 0; i < n; i++){
            if(target == (2 * nums[i])){
                if(idx.count(nums[i])){
                    return {idx[nums[i]], i};
                }
            }
            idx[nums[i]] = i;
        }
        sort(nums.begin(), nums.end());
        int i = 0;
        int j = n - 1;
        while(i < j){
            int sum = nums[i] + nums[j];
            if(sum == target){
                return {idx[nums[i]], idx[nums[j]]};
            }
            else if(sum > target){
                j--;
            }
            else{
                i++;
            }
        }
        return {-1, -1};
    }
};