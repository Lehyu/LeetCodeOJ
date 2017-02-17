#include<iostream>
#include<string>
using namespace std;
class Solution{
public:
  //LeetCode 67. Add Binary
  string addBinary(string a, string b){
    int m = a.size();
    int n = b.size();
    int len = m>n?m:n;
    int *number = new int[len];
    for(int i = 0; i < len; i++){
      number[i] = 0;
    }
    string numS = "";
    int carry = 0, sum = 0;
    int i = m-1, j = n-1;
    string rNum;
    int r;
    for(; i >= 0 && j>=0; i--,j--){
      int x = a[i] - '0';
      int y = b[j] - '0';
      sum = x + y + carry;
      int remainder = sum %2;
      carry = sum/2;
      numS = std::to_string(remainder)+ numS;
    }
    if(i < 0){
      r = j;
      rNum = b;
    }else{
      r = i;
      rNum = a;
    }
    while(r >= 0){
      int x = rNum[r] - '0';
      sum = x + carry;
      int remainder = sum % 2;
      carry = sum/2;
      numS = std::to_string(remainder)+ numS;
      r--;
    }
    if(carry > 0){
      numS = std::to_string(carry)+ numS;
    }
    return numS;
  }
};

int main(){
  Solution *s = new Solution;
  cout<<s->addBinary("11", "1");
}
