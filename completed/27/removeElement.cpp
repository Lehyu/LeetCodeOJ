int removeElement(vector<int> & nums, int val){
  if(nums.empty()) return 0;
  int low = 0, high = nums.size()-1;
  while(low < high){
    while(low < high && nums[high] == val) high--;
    while(low < high && nums[low] != val) low++;
    if(low >= high)  break;
    nums[low] = nums[high];
    high--;
  }
  return low;
}
