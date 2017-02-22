/*
  Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

  (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

  You are given a target value to search. If found in the array return its index, otherwise return -1.

  You may assume no duplicate exists in the array.
*/

class Solution {
public:
  int search(vector<int>& nums, int target) {
    int lo = 0, hi = int(nums.size()) - 1;
    while (lo < hi) {
      int mid = (lo + hi) / 2;
      if ((nums[0] > target) ^ (nums[0] > nums[mid]) ^ (target > nums[mid]))
	lo = mid + 1;
      else
	hi = mid;
    }
    return lo == hi && nums[lo] == target ? lo : -1;
  }
  int search(vector<int>& nums, int target) {
    int low = 0, high=nums.size()-1;
    int mid = (low+high) >> 1;
    while(low <= high){
      if(nums[mid] == target) return mid;
      if(nums[low] == target) return low;
      if(nums[high] == target) return high;
      if(nums[low] <= nums[high]){
	//sorted
	if(nums[mid] < target) low = mid+1;
	else high = mid-1;
	mid = (low+high) >> 1;
      }else{
	//not sorted
	if(nums[low] <= nums[mid]){
	  // low..mid sorted, mid...high unsorted
	  if(target < nums[low]) low = mid+1;
	  else if(target < nums[mid]) high = mid-1;
	  else low = mid+1;
	  mid = (low+high) >> 1;
	}else{
	  // low..mid unsorted, mid..high sorted
	  if(target < nums[mid]) high = mid-1;
	  else if(target < nums[high]) low = mid+1;
	  else high = mid-1;
	  mid = (low+high) >> 1;
	}
      }
    }
    return -1;
  }
};
