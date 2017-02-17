#include "header.hpp"
int n = 0;
void swap(int *a, int *b){
  int tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}

string nextPerm(string cur){
  if(cur == "")
    return "";
  int len = cur.size();
  char cstr[len];
  for(int i = 0; i < len; i++){
    cstr[i] = cur[i];
  }
  int j = len-2;
  while(j >= 0 && cstr[j] > cstr[j+1]){
    j--;
  }

  if(j < 0){
    return "";
  }
  int k = j+1;
  while(k < len && cstr[k] > cstr[j]){
    k++;
  }
  if(k != len-1) k = k-1;
  char tmp = cstr[k];
  cstr[k] = cstr[j];
  cstr[j] = tmp;
  int low = j+1;
  int high = len-1;
  while(low < high){
    tmp = cstr[low];
    cstr[low] = cstr[high];
    cstr[high] = tmp;
    low++;
    high--;
  }
  string ret(cstr);
  return ret;
}
int main() 
{ 
  int list[] = {1, 2, 3, 4, 5};
  string cur = "12345";
  int n = 1;
  while(cur!=""){
    cout<<cur<<endl;
    cur = nextPerm(cur);
    n++;
  }
  cout<<n<<endl;
  return 0; 
}
