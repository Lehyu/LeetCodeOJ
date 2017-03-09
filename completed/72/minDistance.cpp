/*
  Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

  You have the following 3 operations permitted on a word:

  a) Insert a character
  b) Delete a character
  c) Replace a character
*/
class Solution {
public:

  // find the longest common squence
  int minDistance(string word1, string word2) {
    return LCS(word1, word2);
  }
  int dp(string word1, word2){
    int m = word1.size(), n = word2.size();
    vector<vector<int>> c(m+1, vector<int>(n+1, 0));
    for(int i = 0; i <= m; i++) c[i][0] = i;
    for(int j = 0; j <= n; j++) c[0][j] = j;
    for(int i = 1; i <= m; i++){
      for(int j = 1; j <= n; j++){
	if(word1[i-1] == word2[j-1]){
	  c[i][j] = c[i-1][j-1];
	}else{
	  c[i][j] = min(c[i-1][j-1], min(c[i-1][j], c[i][j-1]))+1;
	}
      }
    }
    return c[m][n];
  }

  // reduce space
  int dp(string word1, word2){
    int m = word1.size(), n = word2.size();
    vector<int> c(m+1,0)
    for(int i = 0; i <= m; i++) c[i] = i;
    for(int j = 1; j <= n; j++){
      int pre = c[0];
      c[0] = j;
      for(int i = 1; i <= m; i++){
	int temp = c[i];
	if(word1[i-1] == word2[j-1]){
	  c[i] = pre;
	}else{
	  c[i] = min(pre, min(c[i], c[i-1]))+1;
	}
	pre = temp;
      }
    }
    return c[m];
  }
};
