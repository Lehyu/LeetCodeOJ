/*
  Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

  For example,
  Given:
  s1 = "aabcc",
  s2 = "dbbca",

  When s3 = "aadbbcbcac", return true.
  When s3 = "aadbbbaccc", return false.
  which means s3 keep the relative position.
  insert sort??
*/
class Solution {
public:
  // time limit
  bool isInterleave(string s1, string s2, string s3) {
    int s1len = s1.length(), s2len = s2.length(), s3len = s3.length();
    if(s1len+s2len != s3len) return false;
    int i=0, j=0, k=0;
    while(i < s1len || j < s2len || k < s3len){
      if(i == s1len) return s2.substr(j, s2len) == s3.substr(k, s3len);
      if(j == s2len) return s1.substr(i, s1len) == s3.substr(k, s3len);

      if(s1[i] == s2[j] && s1[i]==s3[k]){
	return isInterleave(s1.substr(i+1, s1len), s2.substr(j, s2len), s3.substr(k+1, s3len))
	  || isInterleave(s1.substr(i, s1len), s2.substr(j+1, s2len), s3.substr(k+1, s3len));
      }
      else if(s1[i] == s3[k]){
	i++;
      }else if(s2[j] == s3[k]){
	j++;
      }else{
	return false;
      }
      k++;
    }
    return true;
  }

  bool isInterleave(string s1, string s2, string s3) {
    
    if(s3.length() != s1.length() + s2.length())
      return false;
    
    bool table[s1.length()+1][s2.length()+1];
    
    for(int i=0; i<s1.length()+1; i++)
      for(int j=0; j< s2.length()+1; j++){
	if(i==0 && j==0)
	  table[i][j] = true;
	else if(i == 0)
	  table[i][j] = ( table[i][j-1] && s2[j-1] == s3[i+j-1]);
	else if(j == 0)
	  table[i][j] = ( table[i-1][j] && s1[i-1] == s3[i+j-1]);
	else
	  table[i][j] = (table[i-1][j] && s1[i-1] == s3[i+j-1] ) || (table[i][j-1] && s2[j-1] == s3[i+j-1] );
      }
        
    return table[s1.length()][s2.length()];
  }
};
