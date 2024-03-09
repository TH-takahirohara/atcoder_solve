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
  int N, M, L, Q;
  cin >> N;
  vector<ll> A(N);
  rep(i,0,N) cin >> A.at(i);
  cin >> M;
  vector<ll> B(M);
  rep(i,0,M) cin >> B.at(i);
  cin >> L;
  vector<ll> C(L);
  rep(i,0,L) cin >> C.at(i);

  cin >> Q;
  vector<ll> X(Q);
  rep(i,0,Q) cin >> X.at(i);

  set<ll> st;
  rep(i,0,N) {
    rep(j,0,M) {
      rep(k,0,L) {
        st.insert(A.at(i) + B.at(j) + C.at(k));
      }
    }
  }

  rep(i,0,Q) {
    if (st.count(X.at(i))) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
}
