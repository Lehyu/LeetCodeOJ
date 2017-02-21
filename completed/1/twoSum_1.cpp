
/*
  Given an array of integers, return indices of the two numbers such that they add up to a specific target.
  You may assume that each input would have exactly one solution, and you may not use the same element twice.
  Example:
  Given nums = [2, 7, 11, 15], target = 9,
  Because nums[0] + nums[1] = 2 + 7 = 9,
  return [0, 1].

  ## Solution one: brute-force search
  ## Solution three: trade space for time using map
*/

class Solution{
public:
  vector<int> twoSum(vector<int> &nums, int target){
    return trade_space_for_time_map(nums, target);
  }

  vector<int> trade_space_for_time_map(vector<int> &nums, int target){
    unordered_map<int, int> hash;
    vector<int> indices;
    for(int i = 0; i < nums.size(); i++){
      int res = target-nums[i];
      if(hash.find(res) != hash.end()){	
	indices.push_back(hash[res]);
	indices.push_back(i);
	return indices;
      }
      hash[nums[i]] = i;
    }
    return indices;
  }
  

  vector<int> brute_force_search(vector<int> &nums, int target){
    vector<int> indices;
    int len = nums.size();
    for(int i = 0; i < len; i++){
      for(int j = i+1; j < len; j++){
	if(nums[i]+nums[j] == target){
	  indices.push_back(i);
	  indices.push_back(j);
	  return indices;
	}
      }
    }
    return indices;
  }
};
