class Solution {
public:
    int n;
    unordered_set<int>visi;
    bool solve(vector<int>&arr, int idx){
        if(idx < 0 || idx >= n){
            return false;
        }
        if(arr[idx] == 0){
            return true;
        }
        if(visi.count(idx)){
            return false;
        }
        visi.insert(idx);
        
        bool op1 = solve(arr, idx - arr[idx]);
        bool op2 = solve(arr, idx + arr[idx]);
        return op1 || op2;
    }

    bool canReach(vector<int>& arr, int start) {
        n = arr.size();
        return solve(arr, start);
    }
};