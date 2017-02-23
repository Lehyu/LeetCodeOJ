/*
  Given a sorted array and a target value, return the index if the target is found. 
  If not, return the index where it would be if it were inserted in order.

  You may assume no duplicates in the array.

  Here are few examples.
  [1,3,5,6], 5 → 2
  [1,3,5,6], 2 → 1
  [1,3,5,6], 7 → 4
  [1,3,5,6], 0 → 0 
*/

class Solution {
public:
  int searchInsert(vector<int>& nums, int target) {
    if(nums.empty()) return 0;
    int low = 0, high = nums.size()-1, mid;
    while(low <= high){
      mid = (low+high) >> 1;
      if(nums[mid] == target) return mid;
      else if(nums[mid] < target) low = mid+1;
      else high = mid-1;
    }
    if(low == nums.size()) return nums.size();
    return nums[low] > target?low+1:low;
  }
};
