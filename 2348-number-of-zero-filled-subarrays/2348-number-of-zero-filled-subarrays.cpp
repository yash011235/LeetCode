class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long n = nums.size();
        long long l = 0;
        long long r = 0;
        long long cnt = 0;
        while(r < n){
            if(nums[r] != 0){
                l = r + 1;
            }
            else{
                cnt += (r - l + 1);
            }
            r++;
        }
        return cnt;
    }
};