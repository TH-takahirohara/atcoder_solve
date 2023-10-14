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
  string S;
  cin >> N >> S;
  vector<int> kazu(10);

  if (S=="0") {
    cout << 1 << endl;
    return 0;
  }

  string ss = S;
  
  rep(i,0,ss.size()) {
    char c = ss.at(i);
    int n = int(c - '0');
    kazu.at(n)++;
  }

  vector<ll> vec;
  for (ll i=1; i<=5e6; i++) {
    if (i * i >= 1e14) break;
    ll num = i * i;
    vec.push_back(num);
  }

  ll ans = 0;
  rep(ite,0,vec.size()) {
    ll num = vec.at(ite);

    vector<int> ketan(10);
    string numstr = to_string(num);
    rep(i,0,numstr.size()) {
      char c = numstr.at(i);
      int n = int(c - '0');
      ketan.at(n)++;
    }

    bool can = true;
    rep(i,0,10) {
      if (i==0) {
        if (ketan.at(i) > kazu.at(i)) { // 累乗の数の方が0の数が多い時は不可能
          can = false;
        }
      } else {
        if (ketan.at(i) != kazu.at(i)) {
          can = false;
        }
      }
    }
    if (can) {
      ans++;
    }
  }
  cout << ans << endl;
}
