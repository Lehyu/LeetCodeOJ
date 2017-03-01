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
  void backtrack(vector<vector<string>> &res, vector<int> &board,int k, int n) {
    if(k >= n) {
      string s = "";
      for(int i = 0; i < n; i++) s += ".";
      vector<string> ans(n, s);
      for(int i = 0; i < board.size(); i++) {
	ans[i][board[i]] = 'Q';
      }
      res.push_back(ans);
      return;
    }
    for(int i = 0; i < n; i++) {
      board[k] = i;
      if(place(board, k))
	backtrack(res, board, k+1, n);
    }
  }
  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> res;
    vector<int> board(n, -1);
    backtrack(res, board, 0, n);
    return res;
  }
};
