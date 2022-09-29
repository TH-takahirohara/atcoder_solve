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
  int N,K;
  cin >> N >> K;
  vector<int> A(N);
  rep(i,0,N) cin >> A.at(i);

  ll s = 0;
  rep(i,0,K) s += A.at(i);

  vector<int> C = A;
  sort(C.begin(), C.end());
  reverse(C.begin(), C.end());
  ll max_s = 0;
  rep(i,0,K) max_s += C.at(i);

  if (max_s <= s) {
    cout << -1 << endl;
    return 0;
  }

  // 座標圧縮
  vector<int> B = A;
  sort(B.begin(), B.end());
  B.erase(unique(B.begin(), B.end()), B.end());
  vector<int> res(N);
  rep(i,0,N) {
    res.at(i) = lower_bound(B.begin(), B.end(), A.at(i)) - B.begin();
  }

  vector<int> bigk;
  rep(i,K,N) {
    bigk.push_back(res.at(i));
  }

  // ある値より大きい値が出てくる最小のindexを保持する
  vector<int> large(400005, -1);
  int cur = 0;
  rep(i,0,bigk.size()) {
    if (cur >= bigk.at(i)) continue;
    rep(j,cur,bigk.at(i)) {
      large.at(j) = i;
    }
    cur = bigk.at(i);
  }

  int ans = 1e9;
  rep(i,0,K) {
    if (large.at(res.at(i)) == -1) continue;
    ans = min(ans, (K-i-1) + large.at(res.at(i)) + 1);
  }
  cout << ans << endl;
}
