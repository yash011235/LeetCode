class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = 0;
        int mindiff = INT_MAX;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                for(int k = j + 1; k < n; k++){
                    int curr = nums[i] + nums[j] + nums[k];
                    if(abs(curr - target) < mindiff){
                        mindiff = abs(curr - target);
                        ans = curr;
                    }
                }
            }
        }
        return ans;
    }
};