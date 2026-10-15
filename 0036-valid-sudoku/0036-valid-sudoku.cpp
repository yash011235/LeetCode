
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>>rows(9);
        vector<unordered_set<char>>cols(9);
        vector<unordered_set<char>>boxes(9);

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.'){
                    continue;
                }

                char ch = board[i][j];
                int key = (i / 3) * 3 + (j / 3);
                if(rows[i].count(ch) || cols[j].count(ch) || boxes[key].count(ch)){
                    return false;
                }
                rows[i].insert(ch);
                cols[j].insert(ch);
                boxes[key].insert(ch);
            }
        }
        return true;
    }
};
