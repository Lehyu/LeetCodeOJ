/*
  Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
  Example:
  Input: "babad"
  Output: "bab"
  Note: "aba" is also a valid answer.
*/

class Solution {
public:
  string longestPalindrome(string s){
    if(s.empty()) return "";
    if(s.size() == 1) return s;
    int start = 0, max_len = 1;
    int len = s.length();
    for(int i = 0; i < len; ){
      if(len - i <= max_len/2) break;
      int j = i, k = i;
      while(k < len && s[k+1]==s[k]) ++k;
      i = k+1;
      while(k < len && j > 0 && s[k+1] == s[j-1]){ k++;j--;}
      int new_len = k-j+1;
      if(max_len < new_len){
	max_len = new_len;
	start = j;
      }
    }
    return s.substr(start, max_len);
  }
  // reverse s, we obtain rs, then find the longest substring
  //error s = abcdedfsefdcba
  string longestPalindrome(string s) {
    string rs="";
    for(int i = s.length()-1; i >=0; i--)
      rs += s[i];
    return LCSubstring(s, rs);
  }

  string LCSubstring(string str1, string str2){
    int len1 = str1.length(), len2 = str2.length();
    int **c = new int*[len1+1];
    for(int i = 0; i <= len1; i++){
      c[i] = new int[len2+1];
    }
    for(int i = 0; i <= len1; i++){
      c[i][0] = 0;
    }
    for(int i = 0; i <= len2; i++){
      c[0][i] = 0;
    }
    int max = -1;
    int index1 = -1, index2 = -1;
    for(int i = 1; i <= len1; i++){
      for(int j = 1; j <= len2; j++){
	if(str1[i-1] == str2[j-1]) c[i][j] = c[i-1][j-1]+1;
	else c[i][j] = 0;
	if(c[i][j] > max){
	  max = c[i][j];
	  index1 = i;
	  index2 = j;
	}
      }
    }

    return walk(str1, str2, index1, index2);
  }

  string walk(string str1, string str2, int index1, int index2){
    int len1 = strlen(str1), len2 = strlen(str2);
    string s = "";
    while(index1 >= 0 && index2 >= 0){
      if(str1[index1-1] != str2[index2-1]) break;
      s = str1[index1-1]+s;
      index1--;
      index2--;
    }
    return s;
  }
};
