class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closest_sum = 1e9;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i < n - 2; i++){
            int l = i + 1;
            int r = n - 1;
            while(l < r){
                int sum = nums[i] + nums[l] + nums[r];
                if(abs(sum - target) < abs(closest_sum - target)){
                    closest_sum = sum;
                }
                if(sum == target){
                    return target;
                }
                else if(sum < target){
                    l++;
                }
                else{
                    r--;
                }
            }
        }
        return closest_sum;
    }
};