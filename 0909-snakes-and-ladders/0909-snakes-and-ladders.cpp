
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> arr(n * n + 1);
        int idx = 1;
        bool leftToRight = true;

        for (int r = n - 1; r >= 0; r--) {
            if (leftToRight) {
                for (int c = 0; c < n; c++) {
                    arr[idx++] = board[r][c];
                }
            } else {
                for (int c = n - 1; c >= 0; c--) {
                    arr[idx++] = board[r][c];
                }
            }
            leftToRight = !leftToRight;
        }

        queue<int> q;
        vector<int> dist(n * n + 1, -1);

        q.push(1);
        dist[1] = 0;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            if (curr == n * n) {
                return dist[curr];
            }

            for (int dice = 1; dice <= 6 && curr + dice <= n * n; dice++) {
                int next = curr + dice;

                if (arr[next] != -1) {
                    next = arr[next];
                }

                if (dist[next] == -1) {
                    dist[next] = dist[curr] + 1;
                    q.push(next);
                }
            }
        }

        return -1;
    }
};
