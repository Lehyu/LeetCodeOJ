/*
  Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
  For example, given n = 3, a solution set is:

  [
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
  ]
*/

class Solution {
public:
  vector<string> generateParenthesis(int n){
    vector<string> res;
    stack<string> tmp;
    stack<int> valid;
    tmp.push("(");
    valid.push(0);
    while(!tmp.empty()){
      string s = tmp.pop();
      int v = valid.pop();
      if(s.length() == n << 1){
	res.push_back(s);
	continue;
      }
      if(s.length()-v < n){
	tmp.push(s+"(");
	valid.push(v);
      }
      if(2*v < s.length()){
	tmp.push(s+")");
	valid.push(v+1);
      }
    }
    return res;
  }
  vector<string> generateParenthesis(int n) {
    unordered_set<string> p_set({"()"});
    for(int i = 1; i < n; i++) {
      unordered_set<string> tmp;
      for(unordered_set<string>::iterator it = p_set.begin(); it != p_set.end(); it++) {
	string s = *it;
	for(int k = 0; k < s.length(); k++) {
	  string tmp_s = s;
	  tmp_s.insert(k, "()");
	  tmp.insert(tmp_s);
	}
      }
      p_set.swap(tmp);
    }
    vector<string> res;
    for(unordered_set<string>::iterator it = p_set.begin(); it != p_set.end(); it++)
      res.push_back(*it);
    return res;
  }
};
