class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        queue<int>q;
        vector<bool>visi(n, false);
        q.push(start);
        visi[start] = true;
        while(!q.empty()){
            int curr = q.front();
            q.pop();

            if(arr[curr] == 0){
                return true;
            }
            int op1 = curr - arr[curr];
            int op2 = curr + arr[curr];
            if(op1 >= 0 && op1 < n && !visi[op1]){
                q.push(op1);
                visi[op1] = true;
            }
            if(op2 >= 0 && op2 < n && !visi[op2]){
                q.push(op2);
                visi[op2] = true;
            }
        }
        return false;
    }
};