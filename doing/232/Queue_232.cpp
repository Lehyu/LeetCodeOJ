#include <stack>
#include<iostream>
using namespace std;
class Solution {
public:
  Solution(){
  }
  void push(int x) {
    mainstack.push(x);
  }
  void pop() {
    while(!mainstack.empty()){
      int x = mainstack.top();
      auxstack.push(x);
      mainstack.pop();
    }
    auxstack.pop();
    while(!auxstack.empty()) {
      int x = auxstack.top();
      auxstack.pop();
      mainstack.push(x);
    }
  }

  int peek() {
    while(!mainstack.empty()){
      int x = mainstack.top();
      auxstack.push(x);
      mainstack.pop();
    }
    int top = auxstack.top();
    while(!auxstack.empty()) {
      int x = auxstack.top();
      auxstack.pop();
      mainstack.push(x);
    }
    return top;
  }

  bool empty() {
    return mainstack.empty();
  }
private:
  stack<int> mainstack;
  stack<int> auxstack;
};

stack<int> input, output;
void push(int x) {
  input.push(x);
}
void peek() {
  if(output.empty()) {
    while(!input.empty()) {
      output.push(input.top());
      input.pop();
    }
  }
  return output.top();
}
void pop(){
  peek();
  output.pop();
}

bool empty(){
  return input.empty() && output.empty();
}





int main(){
  Solution *sl = new Solution;
  int x;
  cin >>x;
  while(x!=-1){
    sl->push(x);
    cin>>x;
  }

  cout<<sl->peek()<<endl;
  sl->pop();
  sl->push(19);
  cout<<sl->peek()<<endl;
}
