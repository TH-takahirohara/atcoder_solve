#include <bits/stdc++.h>
// #include <atcoder/segtree>
using namespace std;
// using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

ll N = 1048576LL;

int main() {
  int Q;
  cin >> Q;

  map<ll,ll> mp;
  set<ll> st;

  // setに0~N-1の値を入れておき、x % Nの値以上の数があったら、それを添字としたAiに値を入れ、
  // setからx % Nを消すようにする。
  // x % N の値がN-1の時などに再度0に戻る必要があるので、2倍しておく
  rep(i,0,2*N) st.insert(i);

  rep(i,0,Q) {
    int t;
    ll x;
    cin >> t >> x;
    if (t == 1) {
      auto it = st.lower_bound(x % N);
      mp[*it % N] = x;
      st.erase(*it % N);
      st.erase(*it % N + N);
    } else { // t == 2
      if (!mp.count(x % N)) {
        cout << -1 << endl;
      } else {
        cout << mp.at(x % N) << endl;
      }
    }
  }
}
