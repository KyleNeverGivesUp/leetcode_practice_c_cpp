/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
class Solution {
public:
    int row;
    int col;
    bool exist(vector<vector<char>>& board, string word) {
        row = board.size();
        col = board[0].size();
        for (int i=0; i<row; ++i){
            for (int j=0; j<col; ++j){
                if (dfs(board, i, j, word, 0))
                    {return true;}
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, int x, int y, string& word, int index){
        if (word.size() == index) return true;
        if ( x<0 || x>= row || y<0 || y>=col || board[x][y] != word[index]) return false;
        char temp = board[x][y];
        board[x][y] = '#';
        bool found = dfs(board, x+1, y, word, index+1) ||
                     dfs(board, x-1, y, word, index+1) ||
                     dfs(board, x, y+1, word, index+1) ||
                     dfs(board, x, y-1, word, index+1);
        board[x][y] = temp;
        return found;
    }
};
// @lc code=end

