#include "header.hpp"
#include<unordered_map>
class Solution {
public:
  bool canWin(int key, int desiredTotal,vector<unordered_map<int,bool>> &cache, int mx) {
    cout<<"key: "<<key<<" mx: "<<mx<<endl;
    if(cache[desiredTotal-1].find(key) != cache[desiredTotal-1].end())
      return cache[desiredTotal-1][key];
    for(int i = mx-1; i >= 0;--i){
      cout<<"key: "<<key<<" 1<<i: "<<(1<<i)<<"&:"<<(key&(1<<i))<<endl;
      if(key & (1 << i)){

	key ^= (1 << i);
	if(i+1 >= desiredTotal || !canWin(key,desiredTotal-i-1,cache,mx)){
	  cache[desiredTotal-1][key] = true;
	  key |= (1 << i);
	  return true;
	}
	key |= (1 << i);
      }
    }
    cache[desiredTotal-1][key] = false;
    return false;
  }
  bool canIWin(int maxChoosableInteger, int desiredTotal) {
    if(desiredTotal <= 1)
      return true;
    if(maxChoosableInteger*(maxChoosableInteger+1) < desiredTotal*2)
      return false;
    vector<unordered_map<int,bool>> cache(desiredTotal);
    vector<bool> v(maxChoosableInteger,true);
    int key = (1 << maxChoosableInteger)-1;
    return canWin(key,desiredTotal,cache,maxChoosableInteger);
  }
};

int main() {
  Solution *sl = new Solution;
  int maxChoosableInteger, desiredTotal;
  cin>>maxChoosableInteger>>desiredTotal;
  cout<<sl->canIWin(maxChoosableInteger, desiredTotal);
}
