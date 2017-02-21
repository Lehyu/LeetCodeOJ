/*
  find str1(i,i+1,...,i+k) = str2(j,j+1,...,j+k)
  c[i][j] = c[i-1][j-1]+1 if str1[i] == str[j] else c[i][j] = 0
*/
string LCSubstring(string str1, string str2){
  int len1 = strlen(str1), len2 = strlen(str2);
  int **c = new int*[len1+1];
  for(int i = 0; i <= len1; i++){
    c[i] = new int[len2+1];
  }
  for(int i = 0; i <= len1; i++){
    c[i][0] = 0;
  }
  for(int i = 0; i <= len2; i++){
    c[0][i] = 0;
  }
  int max = -1;
  int index1 = -1, index2 = -1;
  for(int i = 1; i <= len1; i++){
    for(int j = 1; j <= len2; j++){
      if(str1[i-1] == str2[j-1]) c[i][j] = c[i-1][j-1]+1;
      else c[i][j] = 0;
      if(c[i][j] > max){
	max = c[i][j];
	index1 = i;
	index2 = j;
      }
    }
  }

  return walk(str1, str2, index1-1, index2-1);
}

string walk(string str1, string str2, int index1, index2){
  int len1 = strlen(str1), len2 = strlen(str2);
  string s = "";
  while(index1 >= 0 && index2 >= 0){
    if(str1[index1] != str2[index2]) break;
    s = str1[index1]+s;
    index1--;
    index2--;
  }
  return s;
}
