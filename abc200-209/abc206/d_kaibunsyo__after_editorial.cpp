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
  int N; cin >> N;
  vector<int> A(N);
  rep(i,0,N) cin >> A.at(i);

  vector<vector<int>> G(200005);
  rep(i,0,N/2) {
    if (A.at(i) == A.at(N-i-1)) continue;
    G.at(A.at(i)).push_back(A.at(N-i-1));
    G.at(A.at(N-i-1)).push_back(A.at(i));
  }

  vector<bool> seen(200005);
  int ans = 0;
  rep(i,0,N) {
    if (seen.at(A.at(i))) continue;
    queue<int> que;
    int cnt = 0;
    que.push(A.at(i));
    while (!que.empty()) {
      int v = que.front(); que.pop();
      if (seen.at(v)) continue;
      seen.at(v) = true;
      cnt++;
      for (auto nv : G.at(v)) {
        if (seen.at(nv)) continue;
        que.push(nv);
      }
    }
    ans += cnt - 1;
  }
  cout << ans << endl;
}
