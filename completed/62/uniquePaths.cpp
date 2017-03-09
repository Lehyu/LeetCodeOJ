class Solution {
public:
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
