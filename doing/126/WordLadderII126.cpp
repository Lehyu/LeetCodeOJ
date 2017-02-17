#include "../header.hpp"
class Solution{
public:
  //maybe use DP?
  vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList){
    vector<vector<string>> result;
    vector<string> node;
    int i = 0;
    for(auto& t: wordList){
      node[i] = t;
      i++;
    }

    vector<vector<int>> edge;
    for(i = 0; i < node.size(); i++){
      for(int j = i; j < node.size; j++){
	int l = edgeLen(node[i], node[j]);
	edge[i][j] = l;
	edge[j][i] = l;
      }
    }
    
  }

  int edgeLen(string s, string t){
    if(s == t) return 0;
    int len = s.size();
    int dif = 0;
    for(int i = 0; i < len; i++){
      if(s[i] != t[i]){
	dif++;
      }
      if(dif > 1){
	return 0;
      }
    }
    return dif;
  }
  
};

int main(){
  return 0;
}
