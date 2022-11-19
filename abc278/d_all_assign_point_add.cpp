#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

int main() {
  int N, Q;
  cin >> N;
  vector<ll> A(N);
  rep(i,0,N) cin >> A.at(i);
  cin >> Q;
  set<ll> st;
  rep(i,0,N) st.insert(i);

  ll kijun = 0;

  rep(i,0,Q) {
    int t;
    cin >> t;

    if (t == 1) {
      ll x;
      cin >> x;
      kijun = x;
      set<ll> nst;
      swap(st, nst);
    } else if (t == 2) {
      int idx;
      ll x;
      cin >> idx >> x;
      idx--;
      if (st.count(idx)) {
        A.at(idx) += x;
      } else {
        A.at(idx) = kijun + x;
        st.insert(idx);
      }
    } else {
      int idx;
      cin >> idx;
      idx--;
      if (!st.count(idx)) {
        cout << kijun << endl;
      } else {
        cout << A.at(idx) << endl;
      }
    }
  }
}
