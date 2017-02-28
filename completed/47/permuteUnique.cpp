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
void swap(vector<int> &nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}
bool nextPermutation(vector<int> &nums) {
    int i = nums.size()-2;
    while(i >= 0 && nums[i] >= nums[i+1]) i--;
    if(i < 0) return false;
    int j = nums.size()-1;
    while(j >= 0 && nums[i] >= nums[j]) j--;
    swap(nums, i, j);
    reverse(nums.begin()+i+1, nums.end());
    return true;
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    res.push_back(nums);
    while(nextPermutation(nums)) {
            res.push_back(nums);
    }
    return res;
}
};


