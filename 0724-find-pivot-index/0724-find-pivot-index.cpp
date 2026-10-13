class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        long long sum = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            sum += 1LL * nums[i];
        }
        long long curr = 0;
        for(int i = 0; i < n; i++){
            if(curr == sum - nums[i] - curr){
                return i;
            }
            curr += nums[i];
        }
        return -1;
    }
};