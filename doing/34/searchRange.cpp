/*
  Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.

  Your algorithm's runtime complexity must be in the order of O(log n).

  If the target is not found in the array, return [-1, -1].

  For example,
  Given [5, 7, 7, 8, 8, 10] and target value 8,
  return [3, 4]. 
*/

class Solution {
public:
  vector<int> searchRange(vector<int>& nums, int target) {
    auto bounds = equal_range(nums.begin(), nums.end(), target);
    if (bounds.first == bounds.second)
      return {-1, -1};
    return {bounds.first - nums.begin(), bounds.second - nums.begin() - 1};
  }
  vector<int> searchRange(vector<int>& nums, int target) {
    int lo = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    if (lo == nums.size() || nums[lo] != target)
      return {-1, -1};
    int hi = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
    return {lo, hi};
  }
  vector<int> searchRange(vector<int>& nums, int target) {
    int low = 0, high = nums.size()-1, mid;
    while(low <= high){
      mid = (low+high) >> 1;
      if(nums[mid] == target) break;
      else if(nums[mid] < target) low = mid+1;
      else high = mid-1;
    }
    if(nums[mid] != target) return vector<int>({-1,-1});
    for(low = mid; low >= 0 && nums[low] == target; )low--;
    for(high = mid; high < nums.size() && nums[high] == target;) high++;
    return vector<int>({low+1, high-1});
  }
};
