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
  // vector<ll> A(N);
  map<ll,bool> mp;
  // rep(i,0,N) cin >> A.at(i);
  rep(i,0,N) {
    ll a;
    cin >> a;
    mp[a] = true;
  }

  ll sum = 0;
  if (K % 2 == 0) {
    sum = K / 2 * (K+1);
  } else {
    sum = (K+1) / 2 * K;
  }

  for (auto p : mp) {
    ll key = p.first;
    if (key <= K) {
      sum -= key;
    }
  }
  cout << sum << endl;
}
