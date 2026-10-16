class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int>canreach(n, INT_MAX);
        canreach[n - 1] = 0;
        for(int i = n - 2; i >= 0; i--){
            for(int j = i; j <= min(n - 1, i + nums[i]); j++){
                if(canreach[j] != INT_MAX){
                    canreach[i] = min(canreach[i], canreach[j] + 1);
                }
            }
        }
        return canreach[0];
    }
};