class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        unordered_map<int, int>mp;
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int key = i - j;
                if(mp.count(key) && mp[key] != matrix[i][j]){
                    return false;
                }
                else{
                    mp[key] = matrix[i][j];
                }
            }
        }
        return true;
    }
};