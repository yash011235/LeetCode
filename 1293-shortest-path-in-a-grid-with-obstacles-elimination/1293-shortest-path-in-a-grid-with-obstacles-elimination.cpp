class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<bool>>>visi(m, vector<vector<bool>>(n, vector<bool>(k + 1, false)));
        queue<vector<int>>q;
        visi[0][0][k] = true;
        vector<int>dr = {-1, 1, 0, 0};
        vector<int>dc = {0, 0, -1, 1};
        q.push({0, 0, k, 0});
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            int r = curr[0];
            int c = curr[1];
            int rem_k = curr[2]; 
            int steps = curr[3];
            if(r == m - 1 && c == n - 1){
                return steps;
            }
            for(int i = 0; i < 4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr >= 0 && nc >= 0 && nr < m && nc < n){
                    int new_k = rem_k - grid[nr][nc];
                    if(new_k >= 0 && !visi[nr][nc][new_k]){
                        q.push({nr, nc, new_k, steps + 1});
                        visi[nr][nc][new_k] = true;
                    }
                }
            }
        }
        return -1;
    }
};