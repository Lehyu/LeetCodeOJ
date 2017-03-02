class Solution {
public:
  int lengthOfLastWord(string s) {
    if(s=="") return 0;
    int i = s.length()-1;
    int len = 0;
    for(; i >= 0 && s[i] == ' '; i--);
    for(; i >= 0 && s[i] != ' '; i--) len++;
    return len;
  }
};
