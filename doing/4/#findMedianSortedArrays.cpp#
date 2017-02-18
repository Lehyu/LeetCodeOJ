/*
  There are two sorted arrays nums1 and nums2 of size m and n respectively.
  Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
  Example 1:
  nums1 = [1, 3]
  nums2 = [2]
  The median is 2.0
*/

class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int>& nums2){
    
  }
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      vector<int> nums;
      int mid;
      int i,j;
      for(i = 0, j = 0; !nums2.empty()&&!nums1.empty()&&i < nums1.size()&& j < nums2.size();){
	bool flag = nums1[i] >= nums2[j];
	flag?nums.push_back(nums1[i]):nums.push_back(nums2[j]);
	flag?i++:j++;
      }
      bool flag = i < nums1.size() || nums2.empty();
      int k = 0;
      vector<int> tmp;
      flag?tmp = nums1: tmp = nums2;
      flag?k = i: k = j;
      while(k < tmp.size()){
	nums.push_back(tmp[k]);
	k++;
      }
      mid = nums.size()/2;
      return nums.size()%2 != 0?nums[mid]:(nums[mid]+nums[mid+1])/2.0; // double
    }
};
