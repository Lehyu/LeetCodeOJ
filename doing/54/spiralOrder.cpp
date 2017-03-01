class Solution{
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    if(matrix.size() == 0) return vector<int>();
    int mlo = 0, mhi = matrix.size()-1, nlo = 0, nhi = matrix[0].size()-1;
    vector<int> res;
    while(mlo <= mhi && nlo <= nhi) {
      for(int col = nlo; col <= nhi; col++) res.push_back(matrix[mlo][col]);
      if(++mlo > mhi) break;
      for(int row = mlo; row <= mhi; row++) res.push_back(matrix[row][nhi]);
      if(--nhi < nlo) break;
      for(int col = nhi; col >= nlo; col--) res.push_back(matrix[mhi][col]);
      if(--mhi < mlo) break;
      for(int row = mhi; row >= mlo; row--) res.psuh_back(matrix[row][nlo]);
      if(++nlo > nhi) break;
    }
    return res;
  }
};
