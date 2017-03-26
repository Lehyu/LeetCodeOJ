class Solution {
public:
  vector<int> grayCode(int n){
    if(n==0) return {0};
    int len = pow(2, n);
    vector<int> ans;
    unordered_set<int> unused;
    for(int i = 1; i < len; i++) unused.insert(i);
    int num = 0;
    ans.push_back(num);
    while(!unused.empty()){
      for(auto it = unused.begin(); it != unused.end(); it++){
	int flag = (*it) ^ num;
	if(flag == 1 || flag%2 == 0){
	  ans.push_back((*it));
	  num = (*it);
	  unused.erase(it);
	  break;
	}
      }
    }
    return ans;
  }
  vector<int> grayCode(int n) {
    int N(1 << n);
    vector<int> ans;
    for(int i(0); i < N; i++){
      tmp = i << 1;
      ans.push_back((tmp^i) >> 1);
    }
    return ans;
  }
};
