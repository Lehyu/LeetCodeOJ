class Solution {
public:
  vector<string> letterCombinations(string digits){
    if(digits == "") return vector<string>();
    vector<string> res(1, "");
    vector<string> hash = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    for(int i = 0; i < digits.length(); i++){
      int num = digits[i]-'0';
      if(num < 0 || num > 9) break;
      if(num == 0 || num == 1) continue;
      vector<string> tmp;
      for(int j = 0; j < hash[num].length(); j++){
	for(int k = 0; k < res.size(); k++){
	  tmp.push_back(res[k]+hash[num][i]);
	}
      }
      res.swap(tmp);
    }
    return res;
  }
  vector<string> letterCombinations(string digits) {
    vector<string> res;
    if(digits == "") return res;
    int len = 1;
    vector<string> hash = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    for(int i = 0; i < digits.length(); i++) {
      if(digits[i] == '1' || digits[i] == '0') continue;
      else if(digits[i] == '7' || digits[i] == '9') len *= 4;
      else len *= 3;
    }
    res.resize(len, "");
    for(int i = 0; i < digits.length(); i++) {
      int num = digits[i] - '0';
      if(num == 1 || num == 0) continue;
      else {
	for(int j++ = 0; j++ < digits.length(); j++){
	  for(int k = 0; k < len; k++){
	    
	  }
	}
      }
    }
    return res;
  }
};
