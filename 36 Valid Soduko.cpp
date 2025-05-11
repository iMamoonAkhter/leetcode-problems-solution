class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool seenCol[10]; // seen column
        bool seenRow[10]; //see row
        // check each column
        for(int j=0;j<9;++j){
            for(int k=0;k<=9;++k) {
                seenCol[k] = false;
                seenRow[k] = false;
            }
            for(int i=0;i<9;++i){
                char numCol = board[i][j];
                char numRow = board[j][i];
                if(numCol!='.'){
                    int digit = numCol - '0';
                    if(digit<0||digit>9||seenCol[digit]){
                        return false;
                    }
                    seenCol[digit] = true;
                }
                if(numRow!='.'){
                    int digit = numRow - '0';
                    if(digit<0||digit>9||seenRow[digit]){
                        return false;
                    }
                    seenRow[digit] = true;
                }
            }
        }
        // check each 3x3 sub-box
        for(int box=0;box<9;++box){
            bool seen[10] = {false}; // Track digits 1-9
            int startRow = (box/3)*3;
            int startCol = (box%3)*3;

            for(int i=startRow; i<startRow+3;++i){
                for(int j=startCol; j<startCol+3;++j){
                    char num = board[i][j];
                    if(num!='.'){
                        int digit = num - '0';
                        if(digit < 1 || digit > 9 || seen[digit]){
                            return false;
                        }
                        seen[digit] = true;
                    }
                }
            }
        }

        return true;
    }
};