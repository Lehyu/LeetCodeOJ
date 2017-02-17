#include<string>
#include<iostream>
#include<sstream>
#include<vector>
using namespace std;
class Solution{
public:
  vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k){
    string maxNum = "0";
    for(int len = 0; len <= k && len <= nums1.size() && k-len <= nums2.size(); len++){
      vector<int> maxV1 = maxNumber(nums1,  len);
      vector<int> maxV2 = maxNumber(nums2, k-len);
      string curNum = "";
      int i = 0, j = 0;
      for(; i < maxV1.size() && j < maxV2.size(); ){
	stringstream ss;
	if(maxV1[i] < maxV2[j]){
	  ss<<maxV2[j];
	  curNum += ss.str();
	  j++;
	}else{
	  ss<<maxV1[i];
	  curNum += ss.str();
	  i++;
	}
      }
      vector<int> tmp ;
      int tmpIndex;
      if(i >= maxV1.size()){
	tmp = maxV2;
	tmpIndex = j;
      }else{
	tmp = maxV1;
	tmpIndex = i;
      }

      for(; tmpIndex < tmp.size(); tmpIndex++){
	stringstream ss;
	ss<<tmp[tmpIndex];
	curNum += ss.str();
      }
      cout<<len<<endl;
      cout<<maxNum<<endl;
      cout<<curNum<<endl;
      if(curNum > maxNum){
	maxNum = curNum;
      }
    }
    vector<int> maxVector;
    for(auto c: maxNum){
      maxVector.push_back(c-'0');
    }


    return maxVector;
    
  }

  //how to find max number whose len's k in a single number

  vector<int> maxNumber(vector<int> &nums, int k){
    vector<int> maxV;
    int count[10]{0};
    for(int i = 0; i < nums.size(); i++){
      count[nums[i]]++;
    }
    int total = 0;
    int min = -1;
    int skip = 0;

    for(int i = 9; i >= 0; i--){
      if(total + count[i] >= k){
	min = i;
	skip = count[i] - (k-total);
	break;
      }
      total += count[i];
    }

 
    for(int i = 0; i < nums.size(); i++){
      if(nums[i] > min){
	maxV.push_back(nums[i]);
      }else if(nums[i] == min){
	if(skip > 0){
	  skip --;
	}else{
	  maxV.push_back(nums[i]);
	}
      }
    }
    return maxV;
  }
};

int main(){
  Solution *sl = new Solution;
  vector<int> nums1 = {3,4,6,5}, nums2 = {9,1,2,5,8,3};
  vector<int> max = sl->maxNumber(nums1, nums2, 5);
  for(int i = 0; i < max.size(); i++){
    std::cout<<max[i]<<std::endl;
  }
  return 0;
}
