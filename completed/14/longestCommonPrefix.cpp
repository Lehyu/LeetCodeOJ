/*
  Write a function to find the longest common prefix string amongst an array of strings.
*/


class Solution {
public:
  string longestCommonPrefix(vector<string> &strs){
    string prefix = "";
    for(int idx = 0; !strs.empty() && idx<strs[0].size();idx++){
      for(int i = 1; i < strs.size();i++){
	if(strs[i-1][idx] != strs[i][idx]){
	  return prefix;
	}
      }
      prefix += strs[0][idx];
    }
    return prefix;
  }
  /*
    assume prefix = strs[0], compare each strs[1,2,...] find index
   */
  string longestCommonPrefix(vector<string>& strs) {
    if(strs.empty()) return "";
    //sort(strs.begin(), strs.end());
    string prefix = strs[0];
    for(int i= 1; i < strs.size(); i++){
      int k;
      for(k = 0; k < strs[i].size() && k < prefix.size(); ){
	if(prefix[k] == strs[i][k])  k++;
	else break;
      }
      prefix = prefix.substr(0, k);
    }
    return prefix;
  }
};
