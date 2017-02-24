class Solution {
public:
  
  //543ms bad idea
  int trap(vector<int>& height) {
    vector<int> aux = height;
    sort(aux.begin(), aux.end());
    int llo = 0, lhi = height.size()-1;
    int index = 0;
    int cube = 0;
    while(true) {
      int lo = llo, hi = lhi;
      while(lo < height.size() && height[lo] == 0) lo++;
      while(hi >= 0 && height[hi] == 0) hi--;
      if(lo >= hi) break;
      llo = lo;
      lhi = hi;
      while(index < aux.size() && aux[index] == 0) index++;
      int h = aux[index];
      for(int k = lo; lo <= hi; lo++) {
	if(height[lo] == 0) cube+=h;
	else height[lo] -= h;
      }
      for(int k = index; k < aux.size(); k++) aux[k] -= h;
    }
    return cube;
  }
};
