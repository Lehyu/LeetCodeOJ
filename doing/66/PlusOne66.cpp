#include<iostream>
#include<string>
#include<vector>
using std::vector;
using namespace std;
class Solution{
public:
  //LeetCode 66.Plus One
  vector<int> plusOne(vector<int> &digits){
    int len = digits.size();
    int *result = new int[len];
    int carry = 1;
    bool isFirst = false;
    vector<int> numV;
    if(len == 1 && digits[len-1] == 0){
      numV.push_back(1);
      return numV;
    }
    for(int i = len-1; i >= 0; i--){
      if(!isFirst){
	int sum = carry+digits[i];
	int remainder = sum%10;
	carry = sum/10;
	result[i] = remainder;
	if(carry == 0){
	  isFirst = true;
	}
      }else{
	result[i] = digits[i];
      }
    }

    if(!isFirst){
      numV.push_back(carry);
    }
    for(int i = 0; i < len; i++){
      numV.push_back(result[i]);
    }

    return numV;
  }
};

int main(){
  Solution *s = new Solution;
  vector<int> digits = {9,9,9};
  vector<int> numV = s->plusOne(digits);
  for(int i = 0; i < numV.size(); i++)
    cout<<numV[i];
}
