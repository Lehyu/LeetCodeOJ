/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
*/
struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};
 
class Solution {
public:
  vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
    auto it = intervals.begin();
    vector<Interval> ans;
    for(; it != intervals.end(); it++){
      if((*it).end < newInterval.start) ans.push_back(*it);
      else break;
    }
    ans.push_back(newInterval);
    for(; it!=intervals.end(); it++){
      if(ans.back().start > (*it).start)  ans.back().start = min(ans.back().start, (*it).start);
      if(ans.back().end < (*it).start) ans.push_back(*it);
      else ans.back().end = max(ans.back().end, (*it).end);
    }
    return ans;
  }
  //haven't considered that intervals were sorted
  vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
    intervals.push_back(newInterval);
    sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){return a.start < b.start;});
    if(intervals.empty()) return {};
    vector<Interval> ans;
    ans.push_back(intervals[0]);
    for(int i = 1; i < intervals.size(); i++){
      if(ans.back().end < intervals[i].start) ans.push_back(intervals[i]);
      else ans.back().end = max(ans.back().end, intervals[i].end);
    }
    return ans;
  }
};
