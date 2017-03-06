class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

    if(obstacleGrid.empty() || obstacleGrid[0][0] == 1) return 0;
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    vector<vector<int>> path(m, vector<int>(n, 0));
    //or we can use the obstacleGrid as path
    path[0][0] = 1;
    for(int row = 1; row < m; row++){
      if(obstacleGrid[row][0] != 1)
	path[row][0] = path[row-1][0];
    }
    for(int col = 1; col < n; col++){
      if(obstacleGrid[0][col] != 1)
	path[0][col] = path[0][col-1];
    }
    for(int row = 1; row < m; row++){
      for(int col = 1; col < n; col++){
	path[row][col] = (obstacleGrid[row][col] == 1? 0: (path[row-1][col]+path[row][col-1]));
      }
    }
    return path[m-1][n-1];
  }
  //math
  int uniquePaths(int m, int n){
    if(--m == 0|| --n == 0) return 1;
    long paths = 1, i = (m>n?m:n)+1;
    for(int j = 1; i <= m+n; i++, j++){
      paths *= i;
      paths/=j;
    }
    return (int)paths;
  }
  //dp
  int uniquePaths(int m, int n){
    vector<vector<int>> p(m, vector<int>(n, 1));
    for(int i = 1; i < m; i++){
      for(int j = 1; j < n; j++){
	p[i][j] = p[i-1][j]+p[i][j-1];
      }
    }
    return p[m-1][n-1];
  }
  
  int uniquePaths(int m, int n) {
    if(m == 1 || n == 1) return 1;
    return uniquePaths(m-1,n)+uniquePaths(m, n-1);
  }
  //time limit
  void backtrack(int &path, int m, int n, int i, int j ){
    if(i == m && j == n){
      path++;
      return;
    }
    if(i < m) backtrack(path, m, n, i+1, j);
    if(j < n) backtrack(path, m, n, i, j+1);
  }
  int uniquePaths(int m, int n) {
    int path = 0;
    backtrack(path, m, n, 1, 1);
    return path;
  }
};
