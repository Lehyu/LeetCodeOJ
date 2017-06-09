class Solution {
public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m-1, j = n-1, k=n+m-1;
    while(j >= 0){
      nums1[k--] = i>=0 && nums1[i] > nums2[j] ? nums1[i--]:nums2[j--];
    }
  }
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int len = nums1.size()-1;
    int k = len;
    int i = n-1, j = m-1;
    while(i >= 0 || j >= 0){
      if(i < 0){
	nums1[k] = nums1[j--];
      }else if(j < 0){
	nums1[k] = nums2[i--];
      }else{
	nums1[k] = nums1[j] > nums2[i] ? nums1[j--]:nums2[i--];
      }
      k--;
    }
    for(i = 0; i < m+n; i++){
      nums1[i] = nums1[++k];
    }
  }
};
