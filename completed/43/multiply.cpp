/*
  Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2.
  Note:
  The length of both num1 and num2 is < 110.
  Both num1 and num2 contains only digits 0-9.
  Both num1 and num2 does not contain any leading zero.
  You must not use any built-in BigInteger library or convert the inputs to integer directly.
*/
class Solution{
public:
  string multiply(string num1, string num2){
    int len1 = num1.length(), len2 = num2.length();
    if(len1 < len2) return multiply(num2, num1);
    if(len2 == 0) return "0";
    vector<int> v(len1+len2, 0);
    for(int i = len2-1; i >= 0; i--){
      int a = num2[i] - '0';
      if(a == 0) continue;
      int bit = 0;
      for(int j = len1-1; j >= 0; j--){
	int b = num1[j] - '0';
	int k = len-1-i+len2-1-j;
	bit += a*b+v[k];
	v[k] = bit%10;
	bit /= 10;
      }
      v[len2-1-i+len1] += bit;
    }
    int start = len1+len2-1;
    while(v[start] == 0) start--;
    string res = "";
    for(int i = start; i >= 0; i--)
      res += to_string(v[i]);
    return res;
  }
  // too slow
  string multiply(string num1, string num2){
    int len1 = num1.length(), len2 = num2.length();
    if(len1 < len2) return multiply(num2, num1);
    string res = "0";
    for(int i = len2-1; i >= 0; i--){
      int a = num2[i]-'0';
      if(a == 0) continue;
      int bit = 0;
      string cur = "";
      for(int k = 0; k < len2-1-i; k++) cur+="0";
      for(int j = len1-1; j >= 0; j--){
	bit += a*(num1[j]-'0');
	cur = to_string(bit%10)+cur;
	bit /= 10;
      }
      cur = bit == 0? cur: to_string(bit)+cur;
      res = add(res, cur);
    }
    return res;
  }

  string add(string num1, string num2){
    int len1 = num1.length(), len2 = num2.length();
    int i = len1 -1, j = len2-1;
    int bit = 0;
    string res = "";
    for(; i >= 0 && j >= 0; j--, i--){
      bit += (num1[i]-'0')+(num2[j]-'0');
      res = to_string(bit%10)+res;
      bit /= 10;
    }
    num1 = i >= 0?num1:num2;
    i = i>=0?i:j;
    for(; i >= 0; i--){
      bit += (num1[i]-'0');
      res = to_string(bit%10)+res;
      bit /= 10;
    }
    res = bit == 0?res: to_string(bit)+res;
    return res;
  }
};
