class Solution {
public:
  vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> res;
    int begin = 0;
    while(begin < words.size()){
      int last = begin++;
      int width = words[last].size();
      while(begin < words.size() && width + words[begin].size()+begin-last <= maxWidth){
	width += words[begin++].size();
      }
      string s = "";
      if(last+1 == begin){
	s = words[last]+string(maxWidth-width, ' ');
      }else{
	int space = begin >= words.size()?1:(maxWidth-width)/(begin-1-last);
	int remain = begin >= words.size()?1:(maxWidth-width)%(begin-1-last);
	s = words[last++];
	for(; last < begin; last++)
	  s+= string(space+(remain-->0?1:0), ' ')+words[last];
	s+=string(maxWidth-s.size(), ' ');
      }
      res.push_back(s);	
    }
    return res;
  }
  vector<string> fullJustify(vector<string>& words, int maxWidth) {
    if(words.size() < 2) return {words[0]+string(maxWidth-words[0].size(), ' ')};
    int width = words[0].size(), start = 0, i;
    vector<string> res;
    for(int i = 1; i < words.size(); i++){
      if(width + words[i].size()+i-start < maxWidth
	 && i != words.size()-1){
	width += words[i].size();
	continue;
      }
      int num, remain;
      string s = "";
      if(i-1 == start){
	s = words[start]+string(maxWidth-width, ' ');
      }else{
	num = (maxWidth-width)/(i-start-1);
	remain = (maxWidth-width)%(i-start-1);
	s = words[start];
	for(int j = start+1; j < i; j++){
	  s+= string(num+(remain-->0?1:0), ' ')+words[j];
	}
      }
      cout<<s.size();
      res.push_back(s);
      start = i;
      width = words[i].size();
    }
    return res;
  }
};
