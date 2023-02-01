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
  int N,M;
  cin >> N >> M;
  vector<int> A(N), B(M);
  rep(i,0,N) cin >> A.at(i);
  rep(i,0,M) cin >> B.at(i);

  sort(A.begin(), A.end());
  sort(B.begin(), B.end());

  int ans = 2e9;
  rep(i,0,N) {
    int val = A.at(i);
    auto it = upper_bound(B.begin(), B.end(), val);
    int tmp;
    if (it==B.end()) {
      tmp = abs(val - *prev(it));
    } else if (it==B.begin()) {
      tmp = abs(val - *it);
    } else {
      tmp = min(abs(val - *it), abs(val - *prev(it)));
    }
    ans = min(ans, tmp);
  }
  cout << ans << endl;
}
