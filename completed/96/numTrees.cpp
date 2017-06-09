/*
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
BST: left<=root<=right
set root fixed, |left|*|right|
if we know n-1 has G(n-1) trees, so n values has
G(n) = G(0)*G(n-1)+G(1)*G(n-2)+...+G(n-1)G(0)
G(0) = 1, G(1) = 1, G(2) = 2 (G(2)=G(0)*G(1)+G(1)*G(0))
*/
class Solution {
public:
  int numTrees(int n) {
    vector<int> G(n+1, 0);
    G[0]=G[1]=1;
    for(int i = 2; i <=n; i++){
      for(int j = 0; j <= i-1; j++){
	G[i] += G[j]*G[i-1-j];
      }
    }
    return G[n];
  }
};
