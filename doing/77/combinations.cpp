class Solution {
public:
  void backtrack(vector<vector<int>> &res, vector<int> temp, int n, int position, int k){
    if(k == 0){
      res.push_back(temp);
      return;
    }
    for(int i = position; i <= n; i++){
      temp.push_back(i);
      backtrack(res, temp, n,i+1, k-1);
      temp.pop_back();
    }
  }
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> res;
    vector<int> temp;
    backtrack(res, temp, n, 1, k);
    return res;
  }
};
