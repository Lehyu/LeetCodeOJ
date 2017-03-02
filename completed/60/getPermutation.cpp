class Solution {
public:
  string getPermutation(int n, int k){
    string s(n, '0');
    int f = 1;
    for(int i = 1; i <= n; i++){
      f*=i;
      s[i-1]+=i;
    }
    for(int i = 0, k--; i < n; i++){
      f/=(n-i);
      int j = i+k/f;
      k%=f;
      char c = s[j];
      for(; j > i; j--)
	s[j] = s[j-1];
      s[i] = c;
    }
    return s;
  }
  /* find i that nums[i] < nums[i+1]
     find j that nums[i] < nums[j]
     swap(i,j) reverse(i+1,len)
   */
  bool nextPermutation(vector<int> &nums){
    int i = nums.size()-2;
    for(; i >= 0 && nums[i] > nums[i+1]; i--);
    if(i < 0){
      reverse(nums.begin(), nums.end());
      return false;
    }
    int j = nums.size()-1;
    for(; j >= i && nums[i] > nums[j]; j--);
    swap(nums[i], nums[j]);
    reverse(nums.begin()+i+1, nums.end());
    return true;
  }
  string getPermutation(int n, int k) {
    vector<int> nums(n,-1);
    for(int i = 0; i < n; i++) nums[i] = i+1;
    for(int i = 2; i <= k; i++) nextPermutation(nums);
    string s = "";
    for(auto c : nums) s+= to_string(c);
    return s;
  }
};
