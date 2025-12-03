/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int count = 0;
        for (int i=0; i<row; ++i){
            for (int j=0; j<col; ++j){
                if (grid[i][j] == '1'){
                    dfs(grid, i, j, row, col);
                    count++;
                }
            }
        }
    return count;
    }
    void dfs(vector<vector<char>>& grid, int x, int y, int r, int c){
        if(x < 0 || x>=r || y<0 || y>=c || grid[x][y]!='0') return;
        grid[x][y] = '0';
        dfs(grid, x+1, y, r, c);
        dfs(grid, x-1, y, r, c);
        dfs(grid, x, y+1, r, c);
        dfs(grid, x, y-1, r, c);

    }
};
// @lc code=end

