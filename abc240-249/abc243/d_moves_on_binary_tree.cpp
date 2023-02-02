#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

int main() {
  int N;
  ull X;
  string S;
  
  cin >> N >> X >> S;
  
  stack<char> sta;
  
  rep(i,0,N) {
    char tmp = S.at(i);
    if (sta.empty()) {
      sta.push(tmp);
    } else {
      if (sta.top() != 'U' && tmp == 'U') sta.pop();
      else sta.push(tmp);
    }
  }
  
  vector<char> new_arr;
  while (!sta.empty()) {
    char tmp = sta.top();
    sta.pop();
    new_arr.push_back(tmp);
  }
  
  reverse(new_arr.begin(), new_arr.end());
  
  int arr_size = new_arr.size();
  rep(i,0,arr_size) {
    char tmp = new_arr.at(i);
    if (tmp == 'U') {
      X = X / 2;
    } else if (tmp == 'L') {
      X = 2 * X;
    } else {
      X = 2 * X + 1;
    }
  }
  
  cout << X << endl;
}
