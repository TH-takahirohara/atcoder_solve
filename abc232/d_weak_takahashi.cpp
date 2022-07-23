#include <bits/stdc++.h>
// #include <atcoder/segtree>
using namespace std;
// using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

typedef pair<int,int> P;

int main() {
  int R,C;
  cin >> R >> C;
  
  vector<string> vec(R);
  rep(i,0,R) cin >> vec.at(i);
  
  vector<vector<int>> masu(R, vector<int>(C, 1));
  
  queue<P> que;
  que.push(make_pair(0,0));
  
  while (!que.empty()) {
    P p = que.front();
    que.pop();
    
    int r = p.first;
    int c = p.second;
    
    if (c + 1 < C && vec.at(r).at(c + 1) == '.') {
      if (masu.at(r).at(c+1) == 1) {
        masu.at(r).at(c+1) = masu.at(r).at(c) + 1;
        que.push(make_pair(r, c+1));
      }
    }
    
    if (r + 1 < R && vec.at(r + 1).at(c) == '.') {
      if (masu.at(r+1).at(c) == 1) {
        masu.at(r+1).at(c) = masu.at(r).at(c) + 1;
        que.push(make_pair(r+1, c));
      }
    }
  }
  
  int ans = 0;
  rep(r,0,R) {
    rep(c,0,C) {
      ans = max(ans, masu.at(r).at(c));
    }
  }
  cout << ans << endl;
}

