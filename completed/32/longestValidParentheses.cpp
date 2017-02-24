/*
  Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

  For "(()", the longest valid parentheses substring is "()", which has length = 2.

  Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
*/

class Solution {
public:
  // valid longest
  // 9ms
  int longestValidParentheses(string s) {
    int maxmium = 0;
    stack<int> key;
    for(int i = 0; i < s.length(); i++){
      if(key.empty() || s[i] == '(') key.push(i);
      else if(s[key.top()] == '(') key.pop();
      else key.push(i);
    }
    int last = s.length();
    while(!key.empty()){
      int cur = last-key.top()-1;
      if(cur %2 == 0) maxmium = maxmium>cur?maxmium:cur;
      last = key.top();
      key.pop();
    }
    maxmium = maxmium>last?maxmium:last;
    return maxmium;
  }
  // 22ms
  int longestValidParentheses(string s) {
    int maxmium = 0;
    string st = "";
    stack<int> key;
    for(int i = 0; i < s.length(); i++){
      if(s[i] == '('){
	st += s[i];
	key.push(i);
      } else {
	if(st == ""){
	  key.push(i);
	}else{
	  st = st.substr(0, st.length()-1);
	  key.pop();
	}
      }
    }
    int last = s.length();
    while(!key.empty()){
      int cur = last-key.top()-1;
      if(cur %2 == 0) maxmium = maxmium>cur?maxmium:cur;
      last = key.top();
      key.pop();
    }
    maxmium = maxmium>last?maxmium:last;
    return maxmium;
  }
};

