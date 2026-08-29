class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
           set<char> rset,cset, b1, b2, b3;

           for (int i=0;i<9;i++){
            if (i % 3 == 0){
                b1.clear();
                b2.clear();
                b3.clear();
            }
            for (int j=0;j<9;j++){
                if (board[i][j] == '.') continue;
                auto res = rset.insert(board[i][j]);
                if (!res.second) return false;

                if ( j < 3){
                    auto res = b1.insert(board[i][j]);
                    if (!res.second) return false;
                }
                else if ( j >= 3 && j<6){
                    auto res = b2.insert(board[i][j]);
                    if (!res.second) return false;
                }
                else {
                    auto res = b3.insert(board[i][j]);
                    if (!res.second) return false;
                }
            }
            rset.clear();
           }

           for (int i=0;i<9;i++){
            for (int j=0;j<9;j++){
                if (board[j][i] == '.') continue;
                auto res = cset.insert(board[j][i]);
                if (!res.second) return false;
            }
            cset.clear();
           }
           return true;
    }
};
