/*
  You are given a string, s, and a list of words, words, that are all of the same length. 
  Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.
  For example, given:
  s: "barfoothefoobarman"
  words: ["foo", "bar"]
  You should return the indices: [0,9].
  (order does not matter).
*/


class Solution {
public:
  vector<int> findSubstring(string s, vector<string> &words){
    int s_len = s.length(), word_len = words[0].length();
    vector<int> res;
    if(s_len < word_len*words.size()) return res;
    unordered_map<string, int> counts;
    for(auto word: words) counts[word]++;
    for(int i = 0; i < s_len-word_len+1; i++){
      unordered_map<string,int> seen;
      int j = 0;
      for(; j < words.size(); j++){
	string tmp = s.substr(i+j*word_len, word_len);
	if(counts.find(tmp) != counts.end()){
	  seen[tmp]++;
	  if(seen[tmp] > counts[tmp]) break;
	}else break;
      }
      if( j == num ) res.push_back(i);
    }
    return res;
  }
  // time limit exceeded
  vector<int> findSubstring(string s, vector<string> & words) {
    int len = words[0].length();
    if(s.length() < len*words.size()) return vector<int>();
    int range = s.length()-len*words.size();
    unordered_map<int, bool> m;
    vector<int> res;
    for(int i = 0; i <= range;i++) {
      while(i < range) {
	string tmp = s.substr(i,len);
	int j;
	for(j = 0; j < words.size() && tmp != words[j]; ) j++;
	if(j < words.size()) break;
	i++;
      }
      for(int i = 0; i < words.size(); i++)
	m[i]=false;
      int k = i;
      while(true) {
	string tmp = s.substr(k, len);
	bool flag = false;
	for(int j = 0; j < words.size(); j++) {
	  if(words[j] == tmp && !m[j]) {
	    flag = true;
	    m[j] = true;
	    break;
	  }
	}
	if(!flag||(k-i+len >= len*words.size())) break;
	k+=len;
      }
      bool flag = true;
      for(int i = 0; i < words.size(); i++)
	flag = m[i] &&flag;
      if(flag) 
	res.push_back(i);
            
            
    }
    return res;
  }
  vector<int> brute_search(string s, vector<int> & words){
    int len = words[0].length();
    if(s.length() < len*words.size()) return vector<int>();
    
  }
  
  //word must be identical
  vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> key;
    vector<int> val;
    vector<int> res;
    int len = words[0].length();
    int range = s.length()-len; //important
    //for(int i = 0; i < s.length()-len; i++){
    for(int i = 0; i < range; i++){
      for(int j = 0; j < words.size(); j++){
	if(s.substr(i,len) == words[j]){
	  key.push_back(i);
	  val.push_back(j);
	  i += (len-1);
	  break;
	}
      }
    }
    for(int i = 0; i < key.size();){
      unordered_set<int> vals;
      vals.insert(val[i]);
      int j;
      for(j = 1; j < words.size(); j++){
	if(key[i+j] - key[i+j-1] != len) break;
	else vals.insert(val[i+j]);
      }
      if(vals.size() == words.size()) res.push_back(key[i]);
    }
    return res;
  }
};
