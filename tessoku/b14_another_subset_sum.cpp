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
  int n1 = N/2;
  int n2 = N - N/2;
  vector<ll> A1(n1), A2(n2);
  rep(i,0,n1) cin >> A1.at(i);
  rep(i,0,n2) cin >> A2.at(i);

  vector<ll> sum1;
  set<ll> st;
  for (int b=0; b < (1 << n1); b++) {
    ll tmp = 0;
    rep(i,0,n1) {
      if (b & (1 << i)) tmp += A1.at(i);
    }
    sum1.push_back(tmp);
  }
  for (int b=0; b < (1 << n2); b++) {
    ll tmp = 0;
    rep(i,0,n2) {
      if (b & (1 << i)) tmp += A2.at(i);
    }
    st.insert(tmp);
  }

  string ans = "No";
  rep(i,0,sum1.size()) {
    if (st.count(K - sum1.at(i))) ans = "Yes";
  }
  cout << ans << endl;
}
