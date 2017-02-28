/*
  Given an array of strings, group anagrams together.

  For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
  Return:

  [
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
  ]
*/
class Solution {
public:
  // encode
  vector<vector<string>> groupAnagrams(vector<string> &strs){
    vector<int> prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103};
    unordered_map<int, int> pair;
    int index = 0;
    vector<vector<string>> res;
    for(auto s: strs){
      int key = 1;
      for(auto c: s) key *= prime[c-'a'];
      if(pair.find(key) == pair.end()) pair[key] = index++;
      if(res.size() > pair[key]) res[pair[key]].push_back(s);
      else res.push_back(vector<string>{s});
    }
    return res;
  }
  //76ms
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> res;
    unordered_map<string, int> pair;
    int index = 0;
    for(auto s: strs){
      string temp = s;
      sort(temp.begin(), temp.end());
      if(pair.find(key) == pair.end()) pair[key] = index++;
      if(res.size() > pair[key])
	res[pair[key]].push_back(strs[i]);
      else
	res.push_back(vector<string> {strs[i]});
     
    }
    /*
      for(int i = 0; i < strs.size(); i++) {
    
      vector<char> temp;
      for(int j = 0; j < strs[i].length(); j++)
      temp.push_back(strs[i][j]);
      sort(temp.begin(), temp.end());
      string key = "";
      for(int j = 0; j < temp.size(); j++) key += to_string(temp[j]);
      if(pair.find(key) == pair.end()) pair[key] = index++;
      if(res.size() > pair[key])
      res[pair[key]].push_back(strs[i]);
      else
      res.push_back(vector<string> {strs[i]});
      }*/
    return res;
  }
};
