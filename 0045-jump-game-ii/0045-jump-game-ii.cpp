class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1){
            return 0;
        }
        int jumps = 1;
        int i = 1;
        int steps = nums[0];
        int maxreach = nums[0];
        while(i < n){
            if(i == (n - 1)){
                return jumps;
            }
            steps--;
            maxreach = max(maxreach, i + nums[i]);
            if(steps == 0){
                jumps++;
                if(maxreach == i){
                    return -1;
                }
                steps = maxreach - i;
            }
            i++;
        }
        return jumps;
    }
};