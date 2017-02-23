class Solution {
public:
  string next(string seq){
    string res = "";
    for(int i = 0; i < seq.length(); i++){
      int count = 1;
      while(i+1 < seq.length() && seq[i]==seq[i+1]){
	count++;
	i++;
      }
      res += to_string(count)+seq[i];
    }
    return res;
  }
  string next(string seq) {
    char c = seq[0];
    int count = 1;
    string res = "";
    for(int i = 1; i < seq.length(); i++) {
      if(seq[i] == c) {
	count++;
	continue;
      }
      res += to_string(count)+c;
      c = seq[i];
      count = 1;
    }
    res += to_string(count)+c;
    return res;
  }

  string countAndSay(int n) {
    string seq = "1";
    for(int i = 1; i < n; i++) {
      seq = next(seq);
      cout<<seq<<endl;
    }
    return seq;
  }
};
