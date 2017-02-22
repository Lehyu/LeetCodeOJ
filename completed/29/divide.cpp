/*
  Divide two integers without using multiplication, division and mod operator.

  If it is overflow, return MAX_INT.
*/


// -22222222222222222 2 overflow
int divide(int divided, int divisor){
  if(!divisor || (divided == INT_MIN && divisor == -1)) return INT_MAX;
  if(divisor == 1 || divisor == -1) return divisor ==1? divided:-divided;
  bool positive = !((divisor < 0)^(divided <0));
  divided = abs(divided);
  divisor = abs(divisor);
  long res = 0;
  while(divided >= divisor){
    int temp = divisor, multip = 1;
    while(divided >= (temp << 1)){
      multip <<= 1;
      temp <<= 1;
    }
    divided -= temp;
    res += multip;
  }
  return positive?res:-res;
}
int divide(int divided, int divisor){
  if(!divisor || (divided == INT_MIN && divisor == -1)) return INT_MAX;
  bool positive = !((divisor < 0)^(divided <0));
  long dvd = labs(divided);
  long dsr = labs(divisor);
  int res = 0;
  while(dvd >= dsr){
    long temp = dsr, multip = 1;
    while(dvd >= (temp << 1)){
      multip <<= 1;
      temp <<= 1;
    }
    dvd -= temp;
    res += multip;
  }
  return positive?res:-res;
}

int divide(int divided, int divisor){
  if(!divisor || (divided == INT_MIN && divisor == -1)) return INT_MAX;
  bool positive = !((divisor < 0)^(divided <0));
  long dvd = labs(divided);
  long dsr = labs(divisor);
  int res = 0;
  while(dvd >= dsr){
    if(dvd >= (dsr << 1)){
      res += 2;
      dvd -= (dsr << 1);
    }else{
      res += 1;
      break;
    }
  }
  return positive?res:-res;
}
