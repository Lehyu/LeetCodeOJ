/*
  Implement regular expression matching with support for '.' and '*'.

  '.' Matches any single character.
  '*' Matches zero or more of the preceding element.

  The matching should cover the entire input string (not partial).

  The function prototype should be:
  bool isMatch(const char *s, const char *p)

  Some examples:
  isMatch("aa","a") → false
  isMatch("aa","aa") → true
  isMatch("aaa","aa") → false
  isMatch("aa", "a*") → true
  isMatch("aa", ".*") → true
  isMatch("ab", ".*") → true
  isMatch("aab", "c*a*b") → true
*/

class Solution {
public:
  /*
    this problem can be converted to longest common substring
    f[i][j] = f[i-1][j-1] && s[i-1] == p[j-1]
   */
  bool isMatch(string s, string p) {
    int slen = s.length(), int plen=p.length();
    vector<bool> f(slen+1, vector<bool>(plen+1, false));
    f[0][0] = true;
    for(int i = 1; i <= plen; i++){
      f[0][i] = 
    }
    
    for(int i = 1; i <= slen; i++){
      for(int j = 1; j <= plen; j++){
	if('*' != p[j-1]){
	  f[i][j] = f[i-1][j-1] && ('.' == p[j-1] || s[i-1] == p[j-1]);
	}else{
	  f[i][j] = f[i][j-2] ||(('.' == p[j-2] ||s[i-1] == p[j-2]) && f[i-1][j]);
	}
      }
    }
    return f[slen][plen];
  }
};
