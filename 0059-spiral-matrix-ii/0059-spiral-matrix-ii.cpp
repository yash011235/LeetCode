class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int idx = 1;
        int row = n;
        int col = n;
        int top = 0;
        vector<vector<int>>board(row, vector<int>(col, 0));
        int bottom = row - 1;
        int left = 0;
        int right = col - 1;
        while(idx <= (n * n)){
            for(int i = left; i <= right; i++){
                board[top][i] = idx;
                if(idx > (n * n)){
                    return board;
                }
                idx++;
            }
            top++;
            for(int j = top; j <= bottom; j++){
                board[j][right] = idx;
                if(idx > (n * n)){
                    return board;
                }
                idx++;
            }
            right--;
            for(int i = right; i >= left; i--){
                board[bottom][i] = idx;
                if(idx > (n * n)){
                    return board;
                }
                idx++;
            }
            bottom--;
            for(int j = bottom; j >= top; j--){
                board[j][left] = idx;
                if(idx > (n * n)){
                    return board;
                }
                idx++;
            }
            left++;
        }
        return board;
    }
};