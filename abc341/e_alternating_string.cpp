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
  cin >> N >> Q;
  string S;
  cin >> S;

  set<int> st;
  st.insert(0);
  st.insert(N);
  rep(i,0,N-1) {
    if (S.at(i) == S.at(i+1)) {
      st.insert(i+1);
    }
  }

  rep(ite,0,Q) {
    int fl, l, r;
    cin >> fl >> l >> r;
    l--; r--;
    if (fl == 1) {
      if (st.count(l)) {
        st.erase(l);
      } else {
        st.insert(l);
      }

      if (st.count(r+1)) {
        st.erase(r+1);
      } else {
        st.insert(r+1);
      }
    } else { // fl == 2
      if (*st.upper_bound(l) == *st.upper_bound(r)) {
        cout << "Yes" << endl;
      } else {
        cout << "No" << endl;
      }
    }
  }
}
