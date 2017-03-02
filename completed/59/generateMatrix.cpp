/*
  Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

  For example,
  Given n = 3,

  You should return the following matrix:
  [
  [ 1, 2, 3 ],
  [ 8, 9, 4 ],
  [ 7, 6, 5 ]
  ]
*/
class Solution {
public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> matrix(n, vector<int>(n, -1));
    int mlo = 0, mhi = n-1, nlo = 0, nhi = n-1, val=1;
    while(mlo <= mhi && nlo <= nhi){
      for(int col = nlo; col <= nhi; col++) matrix[mlo][col] = val++;
      if(++mlo > mhi) break;
      for(int row = mlo; row <= mhi; row++) matrix[row][nhi] = val++;
      if(--nhi < nlo) break;
      for(int col = nhi; col >= nlo; col--) matrix[mhi][col] = val++;
      if(--mhi < mlo) break;
      for(int row = mhi; row >= mlo; row--) matrix[row][nlo] = val++;
      if(++nlo > nhi) break;
    }
    return matrix;
  }
};
