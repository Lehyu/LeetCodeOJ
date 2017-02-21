#include<iostream>
#include<string>
#include<vector>
using std::string;
using std::vector;
using namespace std;
class Solution{
public:
  //LeetCode 10.Regular Expression Matching
  //Method: DP
  //Important
  bool isMatch(string s, string p){
    int m = p.size();
    int n = s.size();
    vector<vector<bool>> f(n+1, vector<bool>(m+1, false));
    f[0][0] = true;
    for(int j = 1; j <= m; j++){
      f[0][j] = j > 1 && '*'== p[j-1] && f[0][j-2];
    }
    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= m; j++){
	if(p[j-1] != '*'){
	  f[i][j] = f[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.');
	}else{
	  f[i][j] = f[i][j-2]||((s[i-1] == p[j-2]|| '.' == p[j-2]) && f[i-1][j]);
	}
      }
    }
    return f[n][m];
  }
};

int main(){
  Solution *s = new Solution;
  string str = "abcd", p = "d*";
  std::cout<<s->isMatch(str, p);
  return 0;
}
