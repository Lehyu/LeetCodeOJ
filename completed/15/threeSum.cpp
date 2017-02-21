/*
  Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
  Note: The solution set must not contain duplicate triplets.
  For example, given array S = [-1, 0, 1, 2, -1, -4],
  A solution set is:
  [
  [-1, 0, 1],
  [-1, -1, 2]
  ]
*/

class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> results;
    sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size(); i++){
      int sum = -nums[i];
      int low = i+1, high = nums.size()-1;
      while(low < high){
	int target = nums[low] + nums[high];
	if(target == sum){
	  vector<int> idx(3,0);
	  idx[0] = nums[i];
	  idx[1] = nums[low];
	  idx[2] = nums[high];
	  results.push_back(idx);
	  while(low < high && nums[low] == idx[1]) low++;
	  while(low < high && nums[high] == idx[2]) high--;
	}else if(target < sum) low++;
	else high--;
      }
      while(i+1 < nums.size() && nums[i+1] == nums[i]) i++;
    }
    return results;
  }

  vector<vector<int>> brute_search(vector<int> & nums){
    vector<vector<int>> solutions;
    for(int i = 0; i < nums.size(); i++){
      for(int j = i+1; j < nums.size(); j++){
	for(int k = j+1; k < nums.size(); k++){
	  if(nums[i]+nums[j]+nums[k] == 0){
	    vector<int> idx;
	    idx.push_back(nums[i]);
	    idx.push_back(nums[j]);
	    idx.push_back(nums[k]);
	    sort(idx.begin(), idx.end());
	    bool flag = true;
	    for(int i = 0; !solutions.empty() && i < solutions.size(); i++){
	      if(idx[0] == solutions[i][0] && idx[1] == solutions[i][1] && idx[2] == solutions[i][2]){
		flag = false;
		break;
	      }
	    }
	    if(!flag) solutions.push_back(idx);
	  }
	}
      }
    }
    return solutions;
  }
};


