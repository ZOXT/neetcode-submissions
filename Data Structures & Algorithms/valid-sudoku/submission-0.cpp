class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> seen;

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char curr = board[i][j];
                
                if (curr != '.') {
                    string row_tag = string(1, curr) + " in row " + to_string(i);
                    string col_tag = string(1, curr) + " in col " + to_string(j);
                    string box_tag = string(1, curr) + " in box " + to_string(i / 3) + "-" + to_string(j / 3);
                    
                    if (seen.count(row_tag) || seen.count(col_tag) || seen.count(box_tag)) {
                        return false;
                    }
                    
                    seen.insert(row_tag);
                    seen.insert(col_tag);
                    seen.insert(box_tag);
                }
            }
        }
        return true;
    }
};
