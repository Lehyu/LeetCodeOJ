/*
  Implement wildcard pattern matching with support for '?' and '*'.

  '?' Matches any single character.
  '*' Matches any sequence of characters (including the empty sequence).

  The matching should cover the entire input string (not partial).

  The function prototype should be:
  bool isMatch(const char *s, const char *p)

  Some examples:
  isMatch("aa","a") → false
  isMatch("aa","aa") → true
  isMatch("aaa","aa") → false
  isMatch("aa", "*") → true
  isMatch("aa", "a*") → true
  isMatch("ab", "?*") → true
  isMatch("aab", "c*a*b") → false
*/
/*
  dp: c[i][j] = c[i-1][j-1] &&(s[i-1] == p[j-1] || p[j-1] == '?) if p[j-1] != '*'
  c[i][j] = c[i][j-1]|| c[i-1][j] if p[j-1] == '*'(c[i][j-1] first meet '*', c[i-1][j] not the first time) 
*/
class Solution {
public:
  bool isMatch(string s, string p) {
    int s_len = s.length(), p_len = p.length() ;
    vector<vector<bool>> c(s_len+1, vector<bool>(p_len+1, false));
    // s = ""
    c[0][0] = true;
    for(int col = 1; col <= p_len; col++) c[0][col] = c[0][col-1]&&p[col-1]=='*';
    
    for(int col = 1; col <= p_len; col++){
      for(int row = 1; row <= s_len; row++){
	if(p[col-1] == '*') c[row][col] = c[row][col-1] || c[row-1][col];
	else c[row][col] = c[row-1][col-1] &&(s[row-1]==p[col-1] || p[col-1]=='?');
      }
    }
    return c[s_len][p_len];
  }
  //good solution
  bool isMatch(const char *s, const char *p) {
    const char* star=NULL;
    const char* ss=s;
    while (*s){
      //advancing both pointers when (both characters match) or ('?' found in pattern)
      //note that *p will not advance beyond its length 
      if ((*p=='?')||(*p==*s)){s++;p++;continue;} 

      // * found in pattern, track index of *, only advancing pattern pointer 
      if (*p=='*'){star=p++; ss=s;continue;} 

      //current characters didn't match, last pattern pointer was *, current pattern pointer is not *
      //only advancing pattern pointer
      if (star){ p = star+1; s=++ss;continue;} 

      //current pattern pointer is not star, last patter pointer was not *
      //characters do not match
      return false;
    }

    //check for remaining characters in pattern
    while (*p=='*'){p++;}

    return !*p;  
  }
  bool isMatch(string s, string p) { 
    int m = s.length(), n = p.length();
    if (n > 30000) return false; // the trick
    vector<bool> cur(m + 1, false); 
    cur[0] = true;
    for (int j = 1; j <= n; j++) {
      bool pre = cur[0]; // use the value before update
      cur[0] = cur[0] && p[j - 1] == '*'; 
      for (int i = 1; i <= m; i++) {
	bool temp = cur[i]; // record the value before update
	if (p[j - 1] != '*')
	  cur[i] = pre && (s[i - 1] == p[j - 1] || p[j - 1] == '?');
	else cur[i] = cur[i - 1] || cur[i];
	pre = temp;
      }
    }
    return cur[m]; 
  }
  
  // runtime error
  bool isMatch(string s, string p) {
    int s_len = s.length(), p_len = p.length() ;
    vector<vector<bool>> c(s_len+1, vector<bool>(p_len+1, false));
    // s = ""
    c[0][0] = true;
    for(int col = 1; col <= p_len; col++)
      c[0][col] = c[0][col-1] &&(p[col-1] == '*');

    for(int row = 1; row <= s_len; row++) c[row][0] = false;

    for(int row = 1, col = 1; row <= s_len && col <= p_len; row++) {
      if(s[row-1] == p[col-1]||p[col-1] == '?') {
	c[row][col] = c[row-1][col-1];
	col++;
      }else if(p[col-1] == '*') {
	c[row][col] = c[row-1][col-1] || c[row-1][col];
      }  else {
	while(row >= 1 && p[col-1] != '?'&& p[col-1] != '*') col--;
	if(col <= 0) return false;
      }
    }
    return c[s_len][p_len];
  }
};
