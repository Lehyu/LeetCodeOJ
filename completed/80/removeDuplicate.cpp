class Solutin{
public:
  int removeDuplicates(vector<int> &nums){
    if(nums.empty()) return nums;
    int curnum = nums[0], count = 1, last = 0, n = nums.size()-1;
    for(int i = 1; i <= n; i++ ){
      if(nums[i] == curnum && count == 2){
	for(last = i+1; last <= n && nums[last] == curnum; last++);
	for(int k = last; k <= n; k++) nums[i+k-last] = nums[k];
	n -= (last-i);
	curnum = nums[i];
	count = 0;
      }else if(nums[i] != curnum){
	curnum = nums[i];
	count = 0;
      }
      count++;
    }
    return n;
  }
};
