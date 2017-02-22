class Solution{
public:
  int removeDuplicates(vector<int> &nums){
    if(nums.empty()) return 0;
    int id = 0;
    for(int i = 1; i < nums.size(); i++){
      if(nums[i] != nums[id]) nums[++id] = nums[i];
    }
    return id+1;
  }
  //53ms
  int removeDuplicates(vector<int> &nums){
    for(auto it = nums.begin(); it != nums.end(); it++){
      for(auto it2 = it+1; (*it2) == *it && it2 != nums.end(); )
	nums.erase(it2);
    }
    return nums.size();
  }
};
