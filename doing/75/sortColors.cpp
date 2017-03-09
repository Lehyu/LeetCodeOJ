class Solution {
public:
  void sortColors(vector<int> &nums){
    int second = nums.size()-1, zero = 0;
    for(int i = 0; i < nums.size(); i++){
      while(nums[i] == 2 && second > i) swap(nums[i], nums[second--]);
      while(nums[i] == 0 && zero < i) swap(nums[i], nums[zero++]);
    }
  }

  void sortColors(vector<int> &nums){
    int num0 = 0, num1 = 0;
    for(int i = 0; i < nums.size(); i++){
      if(nums[i] == 0) num0++;
      else num 1 += (nums[i] == 1?1:0);
    }
    for(int i = 0; i < num0; i++) nums[i] = 0;
    for(int i = num0; i < num0+num1; i++) nums[i] = 1;
    for(int i = num0+num1; i < nums.size(); i++) nums[i] = 2;
  }
  //insert sort not good enough and other sort algorithm
  void sortColors(vector<int>& nums) {
    for(int i = 1; i < nums.size(); i++){
      int temp = nums[i], j;
      for(j = i; j-1 >= 0 && nums[j-1] > temp; j--){
	nums[j] = nums[j-1];
      }
      nums[j] = temp;
    }
  }
};
