/*
  Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
  The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

class Solution {
public:
  // 5ms
  bool isValid(string s) {
    int len = s.length();
    unordered_map<char, char> hash;
    hash['('] = ')';
    hash['{'] = '}';
    hash['['] = ']';
    if(len % 2 != 0) return false;
    string st = "";
    for(int i = 0; i < len; i++){
      if(st == "") st += s[i];
      else if(hash[st[st.length()-1]] == s[i]) st = st.substr(0, st.length()-1);
      else if(s[i] == '[' || s[i] == '{' || s[i] == '(') st += s[i];
      else return false;
    }
    return st == "";
  }
  // 3ms
  bool isValid(string s){
    int len = s.length();
    if(len % 2 != 0) return false;
    unordered_map<char, char> hash;
    hash['('] = ')';
    hash['{'] = '}';
    hash['['] = ']';
    stack<char> st;
    for(int i = 0; i < len; i++){
      if(st.empty()) st.push(s[i]);
      else if(hash[st.top()] == s[i]) st.pop();
      else if(s[i] == '[' || s[i] == '{' || s[i] == '(') st.push(s[i]);
      else return false;
    }
    return st.empty();
  }
};
