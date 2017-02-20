/*
  Given an integer, convert it to a roman numeral.
  Input is guaranteed to be within the range from 1 to 3999.
*/

class Solution {
public:
  string intToRoman(int num){
    String M[] = {"", "M", "MM", "MMM"};
    String C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    String X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    String I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    return M[num/1000] + C[(num%1000)/100] + X[(num%100)/10] + I[num%10];
  }
  string intToRoman(int num) {
    string s;
    while(num){
      int remain;
      if(num >= 1000){
	remain = num/1000;
	num %= 1000;
	for(int i = 0; i < remain; i++){
	  s+="M";
	}
      }else if(num >= 100){
	remain = num/100;
	num %= 100;
	s += bitToRoman(remain, "C", "D", "M");
      }else if(num >= 10){
	remain = num/10;
	num %= 10;
	s += bitToRoman(remain, "X", "L", "C");
      }else if(num > 0){
	s += bitToRoman(num, "I", "V", "X");
	num /= 10;
      }else{
	break;
      }
    }
    return s;
  }

  string bitToRoman(int bit, string a, string b, string c){
    switch(bit){
    case 1:
      return a;
    case 2:
      return a+a;
    case 3:
      return a+a+a;
    case 4:
      return a+b;
    case 5:
      return b;
    case 6:
      return b+a;
    case 7:
      return b+a+a;
    case 8:
      return b+a+a+a;
    case 9:
      return a+c;
    default:
      return "";
    }
  }
};
