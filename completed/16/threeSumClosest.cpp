/*
  Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. 
  Return the sum of the three integers. You may assume that each input would have exactly one solution.

  For example, given array S = {-1 2 1 -4}, and target = 1.
  The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

class Solution {
public:
  int threeSumClosest(vector<int>&nums, int target) {
    sort(nums.begin(), nums.end());
    int res = INT_MAX, last = INT_MAX;
    for(int i = 0; i < nums.size(); i++){
      int low = i+1, high = nums.size()-1;
      while(low < high){
	int sum = nums[i]+nums[low]+nums[high];
	if(sum == target) return target;
	int cur = sum - target;
	if(abs(cur) < res){
	  res = abs(cur);
	  last = sum;
	}else if(cur < 0) low++;
	else high--;
      }
      while(i+1 < nums.size() && nums[i+1] == nums[i]) i++;
    }
    return last;
  }
};
