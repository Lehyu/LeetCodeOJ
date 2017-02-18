/*
Given a string, find the length of the longest substring without repeating characters.
Examples:
Given "abcabcbb", the answer is "abc", which the length is 3.
Given "bbbbb", the answer is "b", with the length of 1.
Given "pwwkew", the answer is "wke", with the length of 3. 
      Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/
class Solution{
public:
  //3.Longest Substring without Repeating Characters
  //Method: dp
  
  int lengthOfLonestSubstring(string s){
    string cur = "";
    string last = "";
    for(auto c: s){
      int i = cur.find_first_of(c);
      if(i < 0 || i >= cur.size()){
	cur += c;
	std::cout<<"not cur:"<<cur<<std::endl;
      }else{
	if(last.size() < cur.size())
	  last = cur;
	cur.erase(0, i+1);
	cur += c;
	std::cout<<"cur:"<<cur<<std::endl;
	std::cout<<"last:"<<last<<std::endl;
      }
      
    }
    return last.size()>cur.size()?last.size():cur.size();
  }

  /*l is the current substring's start index, 
    r is the current substring's end index,
    when we meet a repeated char (count(c) > 1), 
    r-l is the current substring's len
    then move l to find the repeated char.
    space change time, 
    we don't have to compare the whole current substring
    to see whether repeated or not.
   */

  int lengthOfLonestSubstring2(string s){
    int count[256]{0}, l = 0, r = 0;
    int len = s.size(), maxLen = 0;
    while(r < len){
      if(count[s[r]] < 1) count[s[r]]++;             //trick
      else{
	maxLen = maxLen > r-l ? maxLen : r-l;
	while(count[s[r]]) count[s[l++]]--;
	count[s[r]]++;
      }
      r++;
    }
    maxLen = maxLen > r-l ? maxLen : r-l;
    return maxLen;
  }
};

int main(){
  Solution *sl = new Solution;
  string s = "abcabcbb";
  std::cout<<s.find_first_of('d')<<std::endl;
  std::cout<<sl->lengthOfLonestSubstring2(s)<<std::endl;
  return 0;
}
