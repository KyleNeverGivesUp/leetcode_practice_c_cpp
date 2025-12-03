/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 */

// @lc code=start
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area=0;
        int row = grid.size();
        int col = grid[0].size();
        for (int i=0; i<row; ++i){
            for (int j=0; j<col; ++j){
                if (grid[i][j] == 1){
                    // int area = dfs(grid, i, j, row, col);
                    // if (area>max_area) max_area = area;
                    max_area = max(max_area, dfs(grid, i, j, row, col));
                }
            }
        }
        return max_area;
    }

    int dfs(vector<vector<int>>& grid, int x, int y, int r, int c){
        
        if (x<0 || x>=r || y<0 || y>=c || grid[x][y]==0) return 0;
        grid[x][y]=0;
        int area=1;
        area += dfs(grid, x+1, y, r, c);
        area += dfs(grid, x-1, y, r, c);
        area += dfs(grid, x, y+1, r, c);
        area += dfs(grid, x, y-1, r, c);
        return area;
    }
};
// @lc code=end

