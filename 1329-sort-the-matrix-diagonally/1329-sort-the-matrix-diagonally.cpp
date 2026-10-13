class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int total = m + n - 1;
        for(int i = m - 1; i >= 0; i--){
            vector<int>temp;
            int r = i;
            int c = 0;
            while(r < m && c < n){
                temp.push_back(mat[r][c]);
                r++;
                c++;
            }
            sort(temp.begin(), temp.end());
            r = i;
            c = 0;
            int idx = 0;
            while(idx < temp.size()){
                mat[r][c] = temp[idx];
                idx++;
                r++;
                c++;
            }
        }

        for(int j = 0; j < n - 1; j++){
            vector<int>temp;
            int r = 0;
            int c = j;
            while(r < m && c < n){
                temp.push_back(mat[r][c]);
                r++;
                c++;
            }
            sort(temp.begin(), temp.end());
            r = 0;
            c = j;
            int idx = 0;
            while(idx < temp.size()){
                mat[r][c] = temp[idx];
                idx++;
                r++;
                c++;
            }
        }
        return mat;
    }
};