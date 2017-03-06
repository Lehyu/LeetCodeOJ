/*
  Given a m x n grid filled with non-negative numbers, 
  find a path from top left to bottom right which minimizes the sum of all numbers along its path.
*/
class Solution {
public:
  // good solution
  int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<int> cur(m, grid[0][0]);
    for (int i = 1; i < m; i++)
      cur[i] = cur[i - 1] + grid[i][0]; 
    for (int j = 1; j < n; j++) {
      cur[0] += grid[0][j]; 
      for (int i = 1; i < m; i++)
	cur[i] = min(cur[i - 1], cur[i]) + grid[i][j];
    }
    return cur[m - 1];
  }
  int minPathSum(vector<vector<int>>& grid) {
    if(grid.empty()) return 0;
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> path(m, vector<int>(n, 0));
    path[0][0] = grid[0][0];
    for(int row = 1; row < m; row++) path[row][0] = path[row-1][0]+grid[row][0];
    for(int col = 1; col < n; col++) path[0][col] = path[0][col-1]+grid[0][col];
    for(int row = 1; row < m; row++){
      for(int col = 1; col < n; col++){
	path[row][col] = grid[row][col]+min(path[row-1][col], path[row][col-1]);
      }
    }
    return path[m-1][n-1];    
  }
};
