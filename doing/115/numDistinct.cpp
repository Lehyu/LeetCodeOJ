/*
  Given a string S and a string T, count the number of distinct subsequences of T in S.

  A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

  Here is an example:
  S = "rabbbit", T = "rabbit"

  Return 3
*/
// DP?
/*
s[i] = t[j],  dp[i][j] = dp[i-1][j-1]
s[i] != t[j], dp[i][j] = dp[i-1][j]+dp[i][j-1]
*/
class Solution {
public:
  int numDistinct(string s, string t) {
    int m=s.length(), n=t.length();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    dp[0][0] = 1;
    
  }
};
