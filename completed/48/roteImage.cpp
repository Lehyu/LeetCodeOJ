/*
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?
*/
class Solution {
public:
  /*
    1 2 3    7 8 9     7 4 1
    4 5 6 => 4 5 6  => 8 5 2
    7 8 9    1 2 3     9 6 3
   */
  void rotate(vector<vector<int>> &matrix){
    reverse(matrix.begin(), matrix.end());
    for(int i = 0; i < matrix.size(); i++)
      for(int j = 0; j < i; j++)
	swap(matrix[i][j], matrix[j][i]);
  }
  // wrong answer
  void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();    
    for(int i = 0; i <= n/2; i++){
      for(int j = 0; j <= n/2; j++){
	int start_i = i, start_j = j;
	int last=matrix[i][j], cur;
	do{
	  int next_i = j, next_j = len-i;
	  cur = matrix[next_i][next_j];
	  matrix[next_i][next_j] = last;
	  last = cur;
	  i = next_i;
	  j = next_j;
	}while(start_i != next_i && next_j != start_j);
      }
    }
  }
};
