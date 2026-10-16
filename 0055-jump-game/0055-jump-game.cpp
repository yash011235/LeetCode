class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool>canreach(n, false);
        canreach[n - 1] = true;
        for(int i = n - 2; i >= 0; i--){
            for(int j = i; j < n && j <= nums[i] + i; j++){
                if(canreach[j]){
                    canreach[i] = true;
                    j = i + nums[i];
                }
            }
        }
        return canreach[0];
    }
};