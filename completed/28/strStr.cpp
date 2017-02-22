/*
  Implement strStr().
  Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
*/
class Solution {
public:
  int strStr(string haystack, string needle) {
  }

  //KMP:http://blog.csdn.net/yutianzuijin/article/details/11954939/
  int KMP_search(string haystack, string needle){
    int m = haystack.length(), n = needle.length();
    vector<int> next = getNext(needle);
    int j = 0;
    for(int i = 0; i <= m-n; i++ ){
      while(j > 0 && haystack[i] == needle[j]) j = next[j];
      if(haystack[i] == needle[j]) j++;
      if(j == n) return i-j;
    }
    return -1;
  }
  vector<int> getNext(string needle){
    int len = needle.length();
    vector<int> next(len, 0);
    int j = 0;
    for(int i = 1; i < len; i++){
      while(j > 0 && needle[i] != needle[j]) j = next[j];
      if(needle[j] == needle[i]) j++;
      next[i+1] = j
    }
    return next;
  }
  int brute_search(string haystack, string needle){
    int m = haystack.length(), n = needle.length();
    for(int i = 0; i < m-n; i++){
      int j = 0;
      for(; j < n; j++){
	if(haystack[i+j] != needle[j]) break;
      }
      if(j == n) return i;
    }
    return -1;
  }
};
