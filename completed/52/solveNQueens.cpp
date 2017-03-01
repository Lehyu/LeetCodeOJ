/*

 */
class Solution {
public:
  bool place(vector<int> &board, int k) {
    for(int i = 0; i < k; i++) {
      if(board[i] == board[k] ||(abs(board[i]-board[k])) ==(abs(i-k)))
	return false;
    }
    return true;
  }
  void backtrack(int &num, vector<int> &board,int k, int n) {
    if(k >= n) {
      num++;
      return;
    }
    for(int i = 0; i < n; i++) {
      board[k] = i;
      if(place(board, k))
	backtrack(num, board, k+1, n);
    }
  }
  int totalNQueens(int n) {
    int num = 0;
    vector<int> board(n, -1);
    backtrack(num, board, 0, n);
    return num;
  }
};
