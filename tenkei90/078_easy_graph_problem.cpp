// 078(★2) グラフの基本を知ろう
// 特に難しいところはない。
#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

template<class T> bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  else return false;
}

int main() {
  int N,M;
  cin >> N >> M;
  
  vector<vector<int>> G(N);
  
  rep(i,0,M) {
    int a,b;
    cin >> a >> b;
    a--;b--;
    G.at(a).push_back(b);
    G.at(b).push_back(a);
  }
  
  int ans = 0;
  rep(i,0,N) {
    int cnt = 0;
    for (auto nx : G.at(i)) {
      if (nx < i) cnt++;
    }
    if (cnt == 1) ans++;
  }
  cout << ans << endl;
}

