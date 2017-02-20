/*
  Given a roman numeral, convert it to an integer.
  Input is guaranteed to be within the range from 1 to 3999.
*/
class Solution {
public:
  int romanToInt(string s) {
    unordered_map<string, int> hash;
    hash["M"] = 1000;
    hash["C"] = 100;
    hash["CD"] = 400;
    hash["D"] = 500;
    hash["CM"] = 900;
    hash["X"] = 10;
    hash["XL"] = 40;
    hash["L"] = 50;
    hash["XC"] = 90;
    hash["I"] = 1;
    hash["IV"] = 4;
    hash["V"] = 5;
    hash["IX"] = 9;
    string last = s.substr(0,1);
    int num = 0;
    for(int i = 1; i < s.length();){
      bool flag = hash.find(last+s[i])!=hash.end();
      num += flag?hash[last+s[i]]:hash[last];
      if(flag){
	last = s.substr(i+1,1);
	i += 2;
      }else{
	last = s.substr(i,1);
	i+=1;
      }
    }
    num += hash[last];
    return num;
  }
};
