/*
  Given an array of non-negative integers, you are initially positioned at the first index of the array.

  Each element in the array represents your maximum jump length at that position.

  Your goal is to reach the last index in the minimum number of jumps.

  For example:
  Given array A = [2,3,1,1,4]

  The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
*/
/*
DP:
index i:max, j in [i+1,..,i+max] w[j] = min(w[i]+1, w[j])
*/
class Solution {
public:
  //BFS
  int jump(vector<int> &nums){
    if(nums.size() < 2) return 0;
    int i = 0, _max = 0, _next = 0, level = 0;
    while(_max-i+1 > 0){
      level++;
      for(; i < _max; i++){
	_next = max(_next, nums[i]+i);
	if(_next>=nums.size()-1) return level;
      }
      _max = _next;
    }
    return 0;
  }
  int jump(vector<int>& nums) {
    int len = nums.size();
    vector<int> c(len, len+1);
    c[0] = 0;
    for(int i = 0; i < nums.size(); i++){
      for(int j = i+1; j <= j+nums[i]; j++){
	c[j] = min(c[j], c[i]+1);
      }      
    }
    return c[len-1];
  }
};
