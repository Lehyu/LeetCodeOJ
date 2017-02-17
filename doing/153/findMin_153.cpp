#include<vector>
#include<iostream>
using namespace std;


class Solution {
public:
  int findMin(vector<int> &nums) {
    int ld = 0, rd = nums.size()-1;
    while(ld < rd){
      int mid = (ld+rd)/2;
      if(nums[ld] > nums[rd]){
	if(nums[mid] > nums[rd]){
	  ld = mid+1;
	}else{
	  rd = mid;
	}
      }else {
	rd = mid;
      }
    }
    return nums[ld];
  }
  int findMin2(vector<int> &nums) {
    int ld = 0, rd = nums.size()-1;
    while(ld < rd){
      int mid = (ld+rd)/2;
      nums[mid] > nums[rd]?ld=mid+1:rd=mid;
    }
    return nums[ld];
  }
};

int main(){
  Solution* sl = new Solution;
  vector<int> nums = {0,1,2,4,5,6,7};
  cout<<sl->findMin(nums);
}

  
