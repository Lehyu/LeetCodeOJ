/*
  Given an absolute path for a file (Unix-style), simplify it.

  For example,
  path = "/home/", => "/home"
  path = "/a/./b/../../c/", => "/c"
*/
class Solution {
public:
  // simplify code
  string simplifyPath(string path){
    string res, tmp;
    vector<string> stk;
    stringstream ss(path);
    while(getline(ss,tmp,'/')) {
      if (tmp == "" or tmp == ".") continue;
      if (tmp == ".." and !stk.empty()) stk.pop_back();
      else if (tmp != "..") stk.push_back(tmp);
    }
    for(auto str : stk) res += "/"+str;
    return res.empty() ? "/" : res;
  }
  string simplifyPath(string path) {
    vector<string> ss;
    string name = "";
    for(int i = 0; i < path.length(); i++) {
      if(path[i] == '/') {
	if(name.empty()) continue;
	else if(name == "."){}
	else if(name != "..") ss.push_back(name);
	else if(!ss.empty()) ss.pop_back();
	name = "";
      } else {
	name += path[i];
      }
    }
    if(name != "" && name != ".." && name != ".") ss.push_back(name);
    else if(name == "."){}
    else if(name == ".." && !ss.empty()) ss.pop_back();
    if(ss.empty()) return "/";
    name = "";
    for(int i = 0; i < ss.size(); i++) {
      name += "/"+ss[i];
    }
    return name;
  }
};
