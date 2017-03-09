class Solution{
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target){
    if(matrix.empty() || matrix[0].empty()) return false;
    int m = matrix.size(), n = matrix[0].size();
    int lo = 0, hi = m*n-1;
    while(lo <= hi){
      int mid = (lo+hi)>>1;
      if(matrix[mid/n][mid%n] < target){
	lo = mid+1;
      }else{
	hi = mid;
      }
    }
    return matrix[hi/n][hi%n] == target;
  }
  bool searchMatrix(vector<vector<int>> &matrix, int target){
    if(matrix.empty()) return false;
    int rlo = 0, rhi = matrix.size()-1, clo = 0, chi = matrix[0].size()-1;
    if(matrix[rhi][chi] < target || matrix[0][0] > target) return false;
    int row = 0;
    for(row; row+1 <= rhi && matrix[row+1][0] <= target; row++);
    while(clo <= chi){
      int mid = (clo+chi) >> 1;
      if(matrix[row][mid] > target){
	chi = mid-1;
      }else if(matrix[row][mid] == target){
	return true;
      }else{
	clo = mid+1;
      }
    }
    return false;
  }
};
