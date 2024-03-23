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
  int N;
  cin >> N;
  string S;
  cin >> S;
  vector<ll> C(N);
  rep(i,0,N) cin >> C.at(i);

  vector<ll> rui0st(N), rui1st(N);
  bool iszero = true;
  rep(i,0,N) {
    if (iszero) {
      if (S.at(i) == '1') {
        rui0st.at(i) += C.at(i);
      }
    } else { // 1でないといけない
      if (S.at(i) == '0') {
        rui0st.at(i) += C.at(i);
      }
    }
    if (i != 0) rui0st.at(i) += rui0st.at(i-1);
    if (iszero) iszero = false;
    else iszero = true;
  }

  iszero = false;
  rep(i,0,N) {
    if (iszero) {
      if (S.at(i) == '1') {
        rui1st.at(i) += C.at(i);
      }
    } else { // 1でないといけない
      if (S.at(i) == '0') {
        rui1st.at(i) += C.at(i);
      }
    }
    if (i != 0) rui1st.at(i) += rui1st.at(i-1);
    if (iszero) iszero = false;
    else iszero = true;
  }


  ll ans = 8e18;
  rep(i,0,N-1) {
    // S(i), S(i+1) が0の場合
    ll ans0 = 0;
    if (i % 2 == 0) { // zero始まり
      ans0 = rui0st.at(i) + (rui1st.at(N-1) - rui1st.at(i));
    } else {
      ans0 = rui1st.at(i) + (rui0st.at(N-1) - rui0st.at(i));
    }
    ans = min(ans, ans0);

    // S(i), S(i+1) が1の場合
    ll ans1 = 0;
    if (i % 2 == 0) { // 1始まり
      ans1 = rui1st.at(i) + (rui0st.at(N-1) - rui0st.at(i));
    } else {
      ans1 = rui0st.at(i) + (rui1st.at(N-1) - rui1st.at(i));
    }
    ans = min(ans, ans1);
  }
  cout << ans << endl;
}
