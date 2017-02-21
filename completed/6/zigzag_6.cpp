/*
  The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
  P   A   H   N
  A P L S I I G
  Y   I   R
  And then read line by line: "PAHNAPLSIIGYIR"
  Write the code that will take a string and make this conversion given a number of rows:
  string convert(string text, int nRows);
  convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR". 
*/
class Solution {
public:
  // calucate each row step
  // multipy changes to moving
 string convert(string s, int numRows) {
         if(numRows <= 1) return s;
    string str = "";
    int max_step = (numRows -1) << 1;
    for(int row = 0; row < numRows; row++){
      int step = row == numRows-1?max_step: max_step - (row << 1);
      for(int pos = row; pos < s.length(); ){
        str += s[pos];
        pos += step;
        step = step == max_step?max_step:max_step-step;
      }

    }
    return str;
  }
};
