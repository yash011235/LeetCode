class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> ans(n, INT_MAX);
        for (int idx = 0; idx < n; idx++) {
            int r = 0;
            int c = idx;
            while (r != m){
                if (c >= 1 && grid[r][c] == -1 && grid[r][c - 1] == 1) {
                    ans[idx] = -1;
                    r = m;
                } else if (c + 1 < n && grid[r][c] == 1 &&
                        grid[r][c + 1] == -1) {
                    ans[idx] = -1;
                    r = m;
                } else if (grid[r][c] == -1 && c == 0) {
                    ans[idx] = -1;
                    r = m;
                } else if (grid[r][c] == 1 && c == n - 1) {
                    ans[idx] = -1;
                    r = m;
                } else if (grid[r][c] == 1) {
                    r++;
                    c++;
                } else {
                    r++;
                    c--;
                }
            }
            if(ans[idx] != -1){
                ans[idx] = c;
            }
        }
        return ans;
    }
};