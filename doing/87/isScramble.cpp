class Solution {
public:
  bool scramble(string s1, string s2){
    if(s1 == s2) return true;
    if(s1.length() == 1) return s1 == s2;
    int llen = s1.length()/2;
    int rlen = s1.length()-llen;
    bool flag =  scramble(s1.substr(0, llen), s2.substr(0, llen)) && scramble(s1.substr(llen, rlen), s2.substr(llen, rlen));
    if(!flag && llen != rlen){
      swap(llen, rlen);
      flag =  scramble(s1.substr(0, llen), s2.substr(0, llen)) && scramble(s1.substr(llen, rlen), s2.substr(llen, rlen));
    }
    return flag;
  }
  bool isScramble(string s1, string s2) {
    if(s1.length() != s2.length()) return false;
    return scramble(s1, s2);
  }
};
