class Solution{
public:
  // 13ms good solution
  bool canJump(vector<int> &nums){
    int i = 0;
    for(int reach = 0; i < nums.size() && i <= reach; i++)
      reach = max(i+nums[i], reach);
    return i == nums.size();
  }
  // 13ms
  bool canJump(vector<int> &nums){
    int i = 1;
    int max_step = nums[0];
    while(i < nums.size()){
      if(max_step >= nums.size()-1) return true;
      int cur = 0;
      for(; i <= max_step; i++){
	cur = max(cur, i+nums[i]);
      }
      if(cur <= max_step) return false;
      max_step = cur;
    }
    return true;
  }
  // time limit
  void backtrack(vector<int> &nums, bool &flag, int k){
    if(k >= nums.size() -1){
      flag = true;
      return;
    }
    for(int i = 1; i <= nums[k]; i++){
      backtrack(nums, flag, k+i);
    }
  }
  bool canJump(vector<int> &nums){
    if(nums.size() < 2) return true;
    bool flag = false;
    backtrack(nums, flag, 0);
    return flag;
  }
};
