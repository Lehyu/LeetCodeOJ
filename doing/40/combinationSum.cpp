class Solution {
public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    sort(candidates.begin(), candidates.end());
    vector<int> combination;
    search(candidates, res, combination, 0, target);
    return res;
  }

  void search(vector<int> &candidates, vector<vector<int>> &res, vector<int> &combination, int begin, int target){
    if(!target){
      res.push_back(combination);
      return;
    }
    for(int i = begin; i < candidates.size() && candidates[i] <= target; i++){
      combination.push_back(candidates[i]);
      search(candidates, res, combination, i+1, target-candidates[i]);
      combination.pop_back();
      while(i+1 < candidates.size() && candidates[i] == candidates[i+1]) i++;
    }
  }

};
