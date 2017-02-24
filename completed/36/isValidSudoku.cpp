class Solution {
public:
  bool isValidSudoku(vector<vector<char>>& board) {
    vector<vector<int>> rows(9, vector<int>(9, 0)), cols(9, vector<int>(9,0));
    vector<vector<int>> fileds(9,  vector<int>(9,0));
    //vector<vector<vector<int>>> fileds(3, vector<vector<int>>(3, vector<int>(9,0)));
    for(int row = 0; row < 9; row++) {
      for(int  col = 0; col < 9; col++) {
	if(board[row][col] == '.') continue;
	else if(board[row][col] < '1' ||board[row][col] > '9') return false;
	int num = board[row][col] - '1', k = row/3*3+col/3;
	if(rows[row][num]||cols[col][num]||fileds[k][num]) return false;
	rows[row][num]=cols[col][num]=fileds[k][num]=1;
	/*
	rows[row][num]++;
	if(rows[row][num] > 1) return false;
	cols[col][num]++;
	if(cols[col][num] > 1) return false;
	fileds[row/3][col/3][num]++;
	if(fileds[row/3][col/3][num] > 1) return false;
	*/
      }
    }
    return true;
  }
};
