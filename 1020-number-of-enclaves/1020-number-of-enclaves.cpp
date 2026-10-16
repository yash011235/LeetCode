class Solution {
public:
    int m, n;
    void bfs(int i, int j, vector<vector<int>>&grid, vector<vector<bool>>&visi){
        queue<pair<int, int>>q;
        q.push({i, j});
        visi[i][j] = true;
        vector<int>dr = {-1, 1, 0, 0};
        vector<int>dc = {0, 0, -1, 1};
        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();

            for(int k = 0; k < 4; k++){
                int nr = r + dr[k];
                int nc = c + dc[k];
                if(nr >= 0 && nc >= 0 && nr < m && nc < n && !visi[nr][nc] && grid[nr][nc] == 1){
                    q.push({nr, nc});
                    visi[nr][nc] = true;
                }
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<bool>>visi(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if((i == 0 || j == 0 || i == m - 1 || j == n - 1) && !visi[i][j] && grid[i][j] == 1){
                    bfs(i, j, grid, visi);
                }
            }
        }
        int cnt = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1 && !visi[i][j]){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};