#include<iostream>
#include<string>
#include<vector>
using std::string;
using std::vector;
using namespace std;
class Solution{
public:
  //LeetCode 65. Valid Number
  //DFA
  /*
    Key Point: know the form of valid number
    Q0: accept . goto Q1, accept -+ goto Q2, accept d goto Q3
    Q1: accept d goto Q4
    Q2: accept . goto Q1
    Q3: accept . goto Q8, accept d goto Q3, accept e goto Q5
    Q4: accept d goto Q4, accept e goto Q5
    Q5: accept -+ goto Q6, accept d goto Q7
    Q6: accept d goto Q7
    Q7: accept d goto Q7
    Q8: accept d goto Q4, accept e goto Q5
    input type:
    . , -+, d, e, other
   */
  bool isNumber(string s){
    vector<vector<int>> ft = {
      {1, 2, 3, -1, -1},          //Q0
      {-1, -1, 4, -1, -1},       //Q1
      {1, -1, 3, -1, -1},        //Q2
      {8, -1, 3, 5, -1},         //Q3
      {-1, -1, 4, 5, -1},          //Q4
      {-1, 6, 7, -1, -1},       //Q5
      {-1, -1, 7, -1, -1},        //Q6
      {-1, -1, 7, -1, -1},       //Q7
      {-1, -1, 4, 5, -1}
    };

    s.erase(0, s.find_first_not_of(" "));
    s.erase(s.find_last_not_of(" ")+1);
    int state = 0;
    int type = 0;
    for(auto c: s){
      if(c == '.'){
	type = 0;
      }else if(c == '-'||c=='+'){
	type = 1;
      }else if(c >= '0' && c <= '9'){
	type = 2;
      }else if(c == 'e'){
	type = 3;
      }else{
	type = 4;
      }

      cout<< state<<" "<<type<<endl;

      state = ft[state][type];
      if(state == -1){
	return false;
      }
    }

    if(state == 8 ||state == 4 || state == 3 || state == 7){
      return true;
    }else{
      return false;
    }
  }
};

int main(){
  Solution *s = new Solution;
  string str = "01", p = "d*";
  std::cout<<s->isNumber(str);
  return 0;
}
