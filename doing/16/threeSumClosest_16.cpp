#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
class Solution {
public:
  void swap(vector<int>&nums,int i, int j) {
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
  }
  void sort(vector<int> &nums){
    for(int i = 0; i < nums.size(); i++){
      int min = i;
      for(int j = i+1; j < nums.size(); j++){
	if(nums[min] > nums[j]){
	  min = j;
	}
      }
      if(i != min){
	swap(nums, i, min);
      }
    }
  }

  int threeSumClosest(vector<int>&nums, int target) {
    sort(nums);
    for(int i=0; i<nums.size(); i++){
      cout<<nums[i]<<" ";
    }
    cout<<endl;
    int ans = nums[0]+nums[1]+nums[2];
    int sum = 999999;
    for (int ld = 0; ld < nums.size()-2; ld++){
      int rd = nums.size()-1;
      int md = ld+1;
      while(md < rd){
	sum = nums[ld]+nums[md]+nums[rd];
	cout<<ld<<" "<<md<<" "<<rd<<" "<<ans<<endl;
	if (fabs(sum-target) < fabs(ans - target)){
	  ans = sum;
	  if(sum == target) return sum;
	}
	sum>target?rd--:md++;
      }
    }
    return ans;
  }
};

int main(){
  Solution *sl = new Solution;
  vector<int> nums = {1,1,1,0};
  cout<<sl->threeSumClosest(nums,-100);
}
