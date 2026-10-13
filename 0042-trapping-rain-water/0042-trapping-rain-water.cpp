class Solution {
public:
    int trap(vector<int>& nums) {
        int n = nums.size();
        vector<int>nextgreatest(n);
        vector<int>prevgreatest(n);
        stack<int>st;
        st.push(0);
        prevgreatest[0] = nums[0];
        for(int i = 1; i < n; i++){
            while(!st.empty() && nums[st.top()] < nums[i]){
                st.pop();
            }
            if(st.empty()){
                st.push(i);
            }
            prevgreatest[i] = nums[st.top()];
        }
        stack<int>stack;
        nextgreatest[n - 1] = nums[n - 1];
        stack.push(n - 1);
        for(int i = n - 2; i >= 0; i--){
            while(!stack.empty() && nums[stack.top()] < nums[i]){
                stack.pop();
            }
            if(stack.empty()){
                stack.push(i);
            }
            nextgreatest[i] = nums[stack.top()];
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans += max(0, min(nextgreatest[i], prevgreatest[i]) - nums[i]);
        }
        return ans;
    }
};