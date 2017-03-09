/*
  You are climbing a stair case. It takes n steps to reach to the top.
  Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/
class Solution {
public:
  int climbStairs(int n) {
    
  }
  // simplify code
  int dp(int n){
    int a = 1, b = 1;
    while(n--) a = (b+=a)-a;
    return a;
  }
  // dp
  int dp(int n){
    if(n == 1) return 1;
    if(n == 2) return 2;
    int hn_2 = 1, hn_1 = 2, hn;
    for(int i = 3; i <= n; i++){
      hn = hn_1+hn_2;
      hn_2 = hn_1;
      hn_1 = hn;
    }
    return hn;
  }
};
