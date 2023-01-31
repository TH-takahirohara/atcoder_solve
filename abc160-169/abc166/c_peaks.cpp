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
  int N, M;
  cin >> N >> M;
  vector<int> H(N);
  rep(i,0,N) cin >> H.at(i);
  vector<set<int>> G(N);
  rep(i,0,M) {
    int a,b; cin >> a >> b;
    a--;b--;
    G.at(a).insert(H.at(b));
    G.at(b).insert(H.at(a));
  }

  int ans = 0;
  rep(i,0,N) {
    if (G.at(i).size() == 0) {
      ans++;
    } else {
      if (H.at(i) > *rbegin(G.at(i))) ans++;
    }
  }
  cout << ans << endl;
}
