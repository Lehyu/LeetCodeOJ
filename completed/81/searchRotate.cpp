class Solution{
public:

  bool search(vector<int> &nums, int target){
    int lo = 0, hi = nums.size()-1;
    while(lo < hi){
      int m = (lo+hi) >> 1;
      if(nums[m] == target) return true;
      else if(nums[m] > nums[hi]){
	if(nums[lo] <= target && target < nums[m]) hi = m;
	else lo = m+1;
      }else if(nums[m] < nums[hi]){
	if(nums[m] < target && target <= nums[hi]) lo = m+1;
	else hi = m;
      }else{
	hi --;
      }
    }
    return nums[lo] == target;
  }
  
  //bad solution
  bool search(vector<int> & nums, int target){
    if(nums.empty()) return false;
    for(int i = 1; i < nums.size(); i++){
      if(nums[i] > nums[i-1]) continue;
      else{
	int j=i, temp = nums[i];
	for(; j-1 >= 0 && nums[j-1] >temp; j--)
	  nums[j] = nums[j-1];
	nums[j] = temp;
      }
    }
    int lo = 0, hi = nums.size()-1;
    while(lo < hi){
      int m = (lo+hi+1)>> 1;
      if(nums[m] < target){
	lo = m+1;
      }else{
	hi = m;
      }
    }
    return nums[hi] == target;
  }
    
};
