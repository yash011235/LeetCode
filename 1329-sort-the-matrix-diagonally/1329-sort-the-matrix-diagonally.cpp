class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        unordered_map<int, vector<int>> mp;

        // Store elements according to their diagonal
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                mp[r - c].push_back(mat[r][c]);
            }
        }

        // Sort every diagonal
        for (auto &[key, v] : mp) {
            sort(v.rbegin(), v.rend());
        }

        // Put sorted elements back
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                mat[r][c] = mp[r - c].back();
                mp[r - c].pop_back();
            }
        }

        return mat;
    }
};