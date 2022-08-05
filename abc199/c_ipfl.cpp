#include <bits/stdc++.h>
// #include <atcoder/segtree>
using namespace std;
// using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

int main() {
  int N,Q;
  string S;
  cin >> N >> S >> Q;
  
  vector<char> vec(2*N);
  rep(i,0,2*N) vec.at(i) = S.at(i);
  
  int turn_cnt = 0;
  rep(i,0,Q) {
    int t,x,y;
    cin >> t >> x >> y;
    x--;y--;
    
    if (t==1) {
      if (turn_cnt % 2 != 0) {
        x = (x + N) % (2*N);
        y = (y + N) % (2*N);
      }
      swap(vec.at(x), vec.at(y));
    } else {
      turn_cnt++;
    }
  }
  
  if (turn_cnt % 2 != 0) {
    rep(i,0,N) cout << vec.at(i+N);
    rep(i,0,N) cout << vec.at(i);
  } else {
    rep(i,0,2*N) cout << vec.at(i);
  }
}

