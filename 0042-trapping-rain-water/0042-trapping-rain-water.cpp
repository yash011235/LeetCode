class Solution {
public:
    int trap(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        int lmax = 0;
        int rmax = 0;
        int ans = 0;
        while(l < r){
            if(nums[l] < nums[r]){
                if(nums[l] > lmax){
                    lmax = nums[l];
                }
                else{
                    ans += lmax - nums[l];
                }
                l++;
            }
            else{
                if(nums[r] > rmax){
                    rmax = nums[r];
                }
                else{
                    ans += rmax - nums[r];
                }
                r--;
            }
        }
        return ans;
    }
};