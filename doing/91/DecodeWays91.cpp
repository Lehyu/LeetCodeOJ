#include<string>
#include<iostream>
#include<vector>
using std::string;
using std::vector;
class Solution{
public:
  //a0a1a2...an
  //D[j] = max{D[j-1], D[j-2]+{1 or 2}}
  int numDecodings(string s){
    vector<int> dp(s.length()+1,1);     // s[i] maps to dp[i+1];
    if(!s.length() || s[0]=='0') return 0;
        
    for(int i=1;i<s.length();i++){
      int num=(s[i-1]-'0')*10+(s[i]-'0');
      if(s[i]=='0'){
	if(s[i-1]!='1' && s[i-1]!='2') return 0;
	else dp[i+1]=dp[i-1];
      }
      else if(10<num && num<27) dp[i+1]=dp[i-1]+dp[i];
      else dp[i+1]=dp[i];
    }
    return dp[s.length()];
  }
};

int main(){
  Solution *s = new Solution;
  std::cout<<s->numDecodings("611")<<std::endl;
}
