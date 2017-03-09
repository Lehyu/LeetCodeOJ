/*

*/
class Solution{
public:
  void setZeroes(vector<vector<int>> &matrix){
    int rows = matrix.size(), cols = matrix[0].size(), col0 = 1;
    for(int i = 0; i < rows; i++){
      if(matrix[i][0] == 0) col0 = 0;
      for(int j = 1; j < cols; j++){
	if(matrix[i][j] == 0){
	  matrix[i][0] = matrix[0][j] = 0;
	}
      }
    }
    for(int i = rows-1; i >= 0; i--){
      for(int j = cols-1; j >= 1; j--){
	if(matrix[i][0] == 0 || matrix[0][j] == 0){
	  matrix[i][j] = 0;
	}
      }
      if(col0 == 0) matrix[i][0] = 0;
    }
  }
  // memory limit 
  void setZeroes(vector<vector<int>> &matrix){
    if(matrix.empty()) return;
    unordered_set<int> col, row;
    for(int i = 0; i < matrix.size(); i++){
      for(int j = 0; j < matrix[1].size(); j++){
	if(matrix[i][j] == 0){
	  col.insert(j);
	  row.insert(i);
	}
      }
    }
    for(auto it = row.begin(); it != row.end(); it++){
      for(int j = 0; j < matrix[1].size(); j++)
	matrix[*it][j] = 0;
    }
    for(auto it = col.begin(); it != col.end(); it++){
      for(int i = 0; i < matrix.size(); i++)
	matrix[i][*it] = 0;
    }
  }
};
