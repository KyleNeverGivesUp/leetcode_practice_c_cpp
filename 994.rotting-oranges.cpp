/*
 * @lc app=leetcode id=994 lang=cpp
 *
 * [994] Rotting Oranges
 */

// @lc code=start
class Solution {
public:
    int row=0;
    int col=0;
    int minutes=-1;
    int fresh=0;
    queue<pair<int, int>> q;
    int orangesRotting(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();
        for (int i=0; i<row; ++i){
            for (int j=0; j<col; ++j){
                if (grid[i][j] == 1){
                    fresh++;
                }
                if (grid[i][j] == 2){
                    q.push({i, j});
                }
            }
        }

        if (fresh == 0) return 0;

        while(q.size()!=0){
            int rotten_number = q.size();
            minutes++;
            while(rotten_number--){
                auto p = q.front();
                q.pop();
                int x = p.first;
                int y = p.second;
                if (x+1 < row && grid[x+1][y] == 1 ){
                    grid[x+1][y] =2;
                    fresh--;
                    q.push({x+1, y});
                }
                if (x-1>=0 && grid[x-1][y] == 1){
                    grid[x-1][y] =2;
                    fresh--;
                    q.push({x-1, y});
                }
                if (y+1<col && grid[x][y+1] == 1){
                    grid[x][y+1] =2;
                    fresh--;
                    q.push({x, y+1});
                }
                if (y-1>=0 && grid[x][y-1] == 1){
                    grid[x][y-1] =2;
                    fresh--;
                    q.push({x, y-1});
                }
            }
        }
        return fresh>0?-1:minutes;
    }
};
// @lc code=end

