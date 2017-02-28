/*
Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/
class Solution {
public:
  void swap(vector<int> &nums, int i, int j){
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
  }
  vector<vector<int>> permute(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    res.push_back(nums);
    while(nextPermutation(nums)) res.push_back(nums);
    return res;
  }
  /* 1.find the index i which nums[i] < nums[i+1]
     2.find the index j which nums[i] < nums[j] 
     3.swap nums[i] and nums[j]
     4.reverse [i+1,...,len-1]
   */
  bool nextPermutation(vector<int> &nums){
    int i = nums.size()-2;
    while(i >= 0 && nums[i] > nums[i+1]) i--;
    if(i < 0) false;
    int j = nums.size()-1;
    while(j >= 0 && nums[i] > nums[j]) j--;
    swap(nums, i, j);
    reverse(nums.begin()+i+1, nums.end()); //9ms
    /*int low = i+1, high = nums.size()-1; //19ms
    while(low <= high) swap(nums, low++, high--);
    */
    return true;
  }
};


