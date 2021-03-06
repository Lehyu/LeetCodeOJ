/*
  Given a set of distinct integers, nums, return all possible subsets.

  Note: The solution set must not contain duplicate subsets.

  For example,
  If nums = [1,2,3], a solution is:

  [
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
  ]
*/
class Solution {
public:
  //good idea
  vector<vector<int> > subsets(vector<int> &S) {
    sort (S.begin(), S.end());
    int elem_num = S.size();
    int subset_num = pow (2, elem_num);
    vector<vector<int> > subset_set (subset_num, vector<int>());
    for (int i = 0; i < elem_num; i++)
      for (int j = 0; j < subset_num; j++)
	if ((j >> i) & 1)
	  subset_set[j].push_back (S[i]);
    return subset_set;
  }


  

  // common idea
  void backtrack(vector<vector<int>> &ans, vector<int> &nums, vector<int> &temp, int position, int k){
    if(k == 0){
      ans.push_back(temp);
      return;
    }
    for(int i = position; i < nums.size(); i++){
      temp.push_back(nums[i]);
      backtrack(ans, nums, temp, i+1, k-1);
      temp.pop_back();
    }
  }
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    for(int k = 0; k <= nums.size(); k++){
      vector<int> temp;
      backtrack(ans, nums, temp, 0, k);
    }
    return ans;
  }

  // same backtrack but more elegant
  vector<vector<int>> subsets(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> subs;
    vector<int> sub;  
    genSubsets(nums, 0, sub, subs);
    return subs; 
  }
  void genSubsets(vector<int>& nums, int start, vector<int>& sub, vector<vector<int>>& subs) {
    subs.push_back(sub);
    for (int i = start; i < nums.size(); i++) {
      sub.push_back(nums[i]);
      genSubsets(nums, i + 1, sub, subs);
      sub.pop_back();
    }
  }
};
