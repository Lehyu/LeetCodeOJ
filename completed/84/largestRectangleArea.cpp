class Solution{
public:
  int maxCombineArea(vector<int> &heights, int s, int m, int e){
    int i = m, j = m+1;
    int h = min(heights[i], heights[j]), area = 0;
    while(i >= s && j <= e){
      h = min(h, min(heights[i], heights[j]));
      area = max(area, h*(j-i+1));
      if(i == s) j++;
      else if(j == e) i--;
      else{
	heights[i-1] > heights[j+1] ? i--:j++;
      }
    }
    return area;
  }
  int maxArea(vector<int> &heights, int s, int e){
    if(s == e) return heights[s];
    int m = s+(e-s)>>1;
    int area = maxArea(heights, s, m);
    area = max(area, maxArea(heights, m+1, e));
    area = max(area, maxCombineArea(heights, s, m, e));
    return area;
  }
  int largestRectangleArea(vector<int> & heights){
    if(heights.empty()) return 0;
    return maxArea(heights, 0, heights.size() -1);
  }
};
