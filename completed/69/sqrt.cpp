class Solution {
public:
  
  int mySqrt(int x) {
    return brute_search(x);
  }

  int newton(int x){
    long long r = x;
    while(r*r > x) r = (r+x/r) >> 1;
    return r;
  }

  int brute_search(int x){
    int left = 0, right = (x+1) >> 1, ans;
    while(left <= right){
      int mid = (left+right) >> 1;
      if(mid <= x/mid){
	left = mid+1;
	ans = left;
      }else{
	right = mid-1;
      }
    }
    return ans;
  }
};
