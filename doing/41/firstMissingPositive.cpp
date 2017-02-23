class Solution {
public:
  void swap(vector<int> &nums, int i , int j){
    nums[i] ^= nums[j];
    nums[j] ^= nums[i];
    nums[i] ^= nums[j];
  }
  // first missing 0.....x....len so x must be smaller than len
  int firstMissingPositive(vector<int> &nums){
    for(int i = 0; i < nums.size(); i++){
      while(nums[i] > 0 && nums[i] <= nums.size() && nums[nums[i] - 1] != nums[i])
	swap(nums, i, nums[i]-1);
    }

    for(int i = 0; i < nums.size(); i++)
      if(nums[i] != i+1) return i+1;
    return nums.size()+1;
  }
  // error constant space
  int firstMissingPositive(vector<int>& nums) {
    int len = 0;
    for(int i = 0; i < nums.size(); i++){
      if(nums[i] <= 0) continue;
      len = nums[i] > len?nums[i]:len;
    }
    len += 2;
    vector<int> aux(len, -1);
    for(int i = 0; i < nums.size(); i++){
      if(nums[i] <= 0) continue;
      aux[nums[i]] = 1;
    }
    for(int i = 1; i < len; i++){
      if(aux[i] >= 1) continue;
      return i;
    }
    return 1;
  }
};
