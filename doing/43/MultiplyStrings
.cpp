#include<iostream>
#include<string>
using namespace std;
class Solution{
public:
  //LeetCode 43. Multiply Strings
  string multiply(string num1, string num2){
    int m = num1.size();
    int n = num2.size();
    if((m==1 && num1[m-1]-'0' == 0)
       ||(n==1 && num2[n-1]-'0' == 0)){
      return "0";
    }
    int len = m+n;
    int *number = new int[len];
    for(int i = 0; i < len; i++){
      number[i] = 0;
    }
    string numS = "";
    for(int i = m-1; i >= 0; i--){
      for(int j = n-1; j >= 0; j--){
	int low = i+j+1, high = i+j;
	int a = num1[i] - '0';
	int b = num2[j] - '0';
	int multiplier = a*b;
	number[low] += multiplier;
	number[high] += number[low]/10;
	number[low] %= 10;
      }
    }
    bool flag = false;
    for(int i = 0; i < len; i++){
      if(!flag && number[i] != 0){
	flag = true;
	numS += std::to_string(number[i]);
      }else if(flag){
	numS += std::to_string(number[i]);
      }else{
	continue;
      }
    }
    return numS;
  }
};

int main(){
  Solution *s = new Solution;
  cout<<s->addBinary("11", "1");
}
