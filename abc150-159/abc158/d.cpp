#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

int main() {
  string S;
  int Q;
  cin >> S >> Q;
  
  bool is_front = true;
  
  deque<char> dq;
  rep(i,0,S.size()) {
    dq.push_back(S.at(i));
  }
    
  rep(i,0,Q) {
    int t;
    cin >> t;
    if (t==1) {
      if (is_front) is_front = false;
      else is_front = true;
    } else {
      int f;
      char c;
      cin >> f >> c;
      
      if (f==1) {
        if (is_front) dq.push_front(c);
        else dq.push_back(c);
      } else {
        if (is_front) dq.push_back(c);
        else dq.push_front(c);
      }
    }
  }
  
  int size = dq.size();
  
  rep(i,0,size) {
    if (is_front) {
      cout << dq.front();
      dq.pop_front();
    } else {
      cout << dq.back();
      dq.pop_back();
    }
  }
}

