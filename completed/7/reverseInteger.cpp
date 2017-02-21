/*
  Reverse digits of an integer.
  Example1: x = 123, return 321
  Example2: x = -123, return -321
  click to show spoilers.
  Note:
  The input is assumed to be a 32-bit signed integer. Your function should return 0 when the reversed integer overflows. 
*/

class Solution {
public:
    int reverse(int x) {
      vector<int> bits;
      bool positive = x >= 0;
      positive ?x =x: x*=-1;
      while(x > 0){
	bits.push_back(x%10);
	x /= 10;
      }
      long nums = 0;
      for(int i = 0; i < bits.size(); i++){
	nums = nums*10+bits[i];
      }
      if(nums > 2147483648) return 0;
      return positive? nums:nums*-1;
      /*
	long rev= 0;
        while( x != 0){
            rev= rev*10 + x % 10;
            x= x/10;
        }
        return (rev > Integer.MAX_VALUE || rev < Integer.MIN_VALUE) ? 0:(int) rev;
       */
    }
};
