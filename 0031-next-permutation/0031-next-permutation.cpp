class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int index = -1;
        for(int i = n - 1; i >= 0; i--){
            int mn = -1;
            for(int j = i + 1; j < n; j++){
                if(nums[j] > nums[i] && (mn == -1 || nums[mn] > nums[j])){
                    mn = j;
                }
            }
            if(mn != -1){
                swap(nums[i], nums[mn]);
                index = i;
                break;
            }
        }
        if(index == -1){
            sort(nums.begin(), nums.end());
        }
        else{
            sort(nums.begin() + index + 1, nums.end());
        }
        return;
    }
};