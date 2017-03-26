class Solution{
public:

  
  // time limit
  bool backtrack(vector<vector<char>> &board, string word, int i, int j, int position){
    if(position >= word.size()) return true;
    if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[position]) return false;
    char curC = board[i][j];
    bool res = false;
    board[i][j] = '*';
    res = backtrack(board, word, i+1, j, position+1);
    if(!res) res = backtrack(board, word, i, j-1, position+1);
    if(!res) res = backtrack(board, word, i-1, j, position+1);
    if(!res) res = backtrack(board, word, i, j+1, position+1);
    board[i][j] = curC;
    return res;
  }
  bool exist(vector<vector<char>> &board, string word){
    if(board.empty()) return false;
    int m = board.size(), n = board[0].size();
    if(n == 0) return false;
    for(int i = 0; i < m; i++){
      for(int j = 0; j < n; j++){
	if(backtrack(board, word, i, j, 0)) return true;
      }
    }
    return false;
  }
};
