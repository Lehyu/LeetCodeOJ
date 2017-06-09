class Solution{
public:
void backtrap(vector<string> &ans, const string s, string vs, string cur, int pos, int n, int dot){
    if(pos >= n){
        if(dot == 4 && vs.length() == n+3)
            ans.push_back(vs);
        return;
    }
    cur += s[pos];
    int seg = stoi(cur);
    if(seg > 255) return;
    else if(seg != 0){
        backtrap(ans, s, vs, cur, pos+1, n, dot);
    }
    vs = vs==""?cur:vs+"."+cur;
    dot += vs == ""?0:1;
    backtrap(ans, s, vs, "", pos+1, n, dot);
}
vector<string> restoreIpAddresses(string s) {
    if(s == "" || s.length() > 12) return {};
    vector<string> ans;
    backtrap(ans, s, "","", 0, s.length(), 0);

    return ans;
}
};
