#include <bits/stdc++.h>
// #include <atcoder/segtree>
using namespace std;
// using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

ll N, K;
vector<ll> A;

ll count(ll n) {
  ll res = 0;
  rep(i,0,N) {
    res += min(A.at(i), n);
  }
  return res;
}

int main() {
  cin >> N >> K;
  A.resize(N);
  rep(i,0,N) cin >> A.at(i);

  ll ng = -1, ok = 2e12;
  while (ok - ng > 1) {
    ll mid = (ng+ok)/2;
    if (count(mid) >= K) ok = mid;
    else ng = mid; 
  }

  ok--;
  ll picked = 0;
  rep(i,0,N) {
    ll tmp = min(A.at(i), ok);
    picked += tmp;
    A.at(i) -= tmp;
  }

  ll nokori = K - picked;
  rep(i,0,N) {
    if (A.at(i) > 0 && nokori > 0) {
      A.at(i) -= 1;
      nokori--;
    }
  }

  rep(i,0,N) {
    cout << A.at(i) << " ";
  }
}
