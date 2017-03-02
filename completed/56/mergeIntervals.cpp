
struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};
 
class Solution {
public:
  // simplify code
  vector<Interval> merge(vector<Interval> & intervals){
    if(intervals.empty()) return {};
    sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){return a.start < b.start});
    vector<Interval> res;
    res.push_back(intervals[0]);
    for(int i = 1; i < intervals.size(); i++){
      if(res.back().end < intervals.start) res.push_back(intervals[i]);
      else res.back().end = res.back().end > intervals[i].end?res.back().end:intervals[i].end;
    }
    return res;
  }
  
  static bool comp(const Interval &a, const Interval &b){
    return a.start < b.start;
  }
  vector<Interval> merge(vector<Interval>& intervals) {
    if(intervals.size() == 0) return {};
    sort(intervals.begin(), intervals.end(), comp);
    int start = intervals[0].start, end = intervals[0].end;
    vector<Interval> ans;
    for(int i = 1; i < intervals.size(); i++){
      if(end >= intervals[i].start){
	end = end > intervals[i].end? end:intervals[i].end;
      }else{
	ans.push_back(Interval(start, end));
	start = intervals[i].start;
	end = intervals[i].end;
      }
    }
    ans.push_back(Interval(start, end));
    return ans;
  }
};
