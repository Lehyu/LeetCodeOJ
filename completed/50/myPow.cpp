/*
  Implement pow(x, n).
*/

class Solution {
public:
  double myPow(double x, int n){
    if(n == 0) return 1;
    double t = myPow(x, n/2);
    if(n%2) return n < 0? 1/x*t*t:t*t*x;
    else return t*t;
  }
  double myPow(double x, int n) {
    if(n == 0) return 1;
    x = n < 0? 1/x:x;
    unsigned long long p = abs(n);
    double res = 1;
    while(p){
      if(p &1) res *= x;
      x*=x;
      p >>= 1;
    }
    return res;
  }
};
