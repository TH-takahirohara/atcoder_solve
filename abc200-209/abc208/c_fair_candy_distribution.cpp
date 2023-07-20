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
  ll K;
  cin >> N >> K;
  vector<ll> A(N);
  rep(i,0,N) cin >> A.at(i);

  vector<ll> B = A;
  sort(B.begin(), B.end());
  set<ll> st;
  ll base = K / N;
  ll amari = K % N;
  rep(i,0,amari) {
    st.insert(B.at(i));
  }

  rep(i,0,N) {
    if (st.count(A.at(i))) cout << base + 1 << endl;
    else cout << base << endl;
  }
}
