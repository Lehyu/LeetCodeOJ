/*
  Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? 
  Find all unique quadruplets in the array which gives the sum of target.
  Note: The solution set must not contain duplicate quadruplets.
  For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.
  A solution set is:
  [
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
  ]
*/

class Solution {
public:
  vector<vector<int>> fourSum(vector<int> &nums, int target){
    vector<vector<int>> res;
    int len = nums.size();
    if(len < 4) return res;
    sort(nums.begin(), nums.end());
    for(int i = 0; i < len-3; i++){
      if(i > 0 && nums[i] == nums[i-1]) continue;
      if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3] > target) break;
      if(nums[i]+nums[len-1]+nums[len-2]+nums[len-3] < target) continue;
      for(int j = i+1; j < len-2; j++){
	if(j > i+1 && nums[j]==nums[j-1]) continue;
	if(nums[i]+nums[j]+nums[j+1]+nums[j+2] > target) break;
	if(nums[i]+nums[j]+nums[len-1]+nums[len-2] < target) continue;
	int low = j+1, high = len -1;
	while(low < high){
	  int sum = nums[i]+nums[j]+nums[low]+nums[high];
	  if(sum < target) do{low++;}while(low<high && nums[low] == nums[low-1]);
	  else if(sum > target) do{high--;}while(low<high && nums[high] == nums[high+1]) ;
	  else{
	    res.push_back(vector<int>{nums[i], nums[j], nums[low], nums[high]});
	    do{low++;}while(low<high && nums[low] == nums[low-1]);
	    do{high--;}while(low<high && nums[high] == nums[high+1]) ;
	  }
	}
      }
    }
    return res;
  }
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    int len = nums.size();
    for(int i = 0; i < len; i++){
      for(int j = i+1; j < len; j++){
	int low = j+1, high = len -1;
	int remain = target-nums[i]-nums[j];
	while(low < high){
	  int sum = nums[low] + nums[high];
	  if(sum < remain){
	    low++;
	    while(low < high && nums[low]==nums[low-1]) low++;
	  }
	  else if(sum > remain){
	    high--;
	    while(low < high && nums[high] == nums[high+1]) high--;
	  }
	  else{
	    vector<int> idx(4, 0);
	    idx[0] = nums[i];
	    idx[1] = nums[j];
	    idx[2] = nums[low];
	    idx[3] = nums[high];
	    res.push_back(idx);
	    while(low < high && nums[low] == idx[2]) low++;
	    while(low < high && nums[high] == idx[3]) high--;
	  }
	  while(j+1 < len && nums[j+1] == nums[j]) j++;
	}
	while(i+1 < len && nums[i+1] == nums[i]) i++;
      }
    }
    return res;
  }
};
