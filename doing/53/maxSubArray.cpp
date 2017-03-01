/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.
*/
class Solution {
public:
  void backtrack(vector<int> &nums, int &maxSofar, int &maxSub, int k){
    if(k >= nums.size()){
      maxSofar = max(maxSofar, maxSub);
      return;
    }
    for(int i = k+1; i < nums.size(); i++){
      if(maxSub+nums[i] < nums[i]){
	maxSub = nums[i];
	maxSofar = max(maxSub, maxSofar);
	backtrack(nums, maxSofar, maxSub, k+1);
	break;
      }
      maxSub += nums[i];
      maxSofar = max(maxSub, maxSofar);
    }
  }
  int maxSubArray(vector<int>& nums) {
    int maxSofar = nums[0], maxSub = nums[0];
    for(int i = 1; i < nums.size(); i++){
      maxSub = max(maxSub+nums[i], nums[i]);
      maxSofar = max(maxSub, maxSofar);
    }
    return maxSofar;
  }
};
