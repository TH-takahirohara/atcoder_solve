#include <bits/stdc++.h>
// #include <atcoder/segtree>
using namespace std;
// using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

ll MAX = 3000000000000000000LL;
int N,Q;
vector<ll> A;

ll calc(ll k) {
  ll left = 0LL;
  ll right = MAX;
  while (right - left > 1) {
    ll mid = left + (right - left) / 2;
    ll idx = lower_bound(A.begin(), A.end(), mid) - A.begin();
    if (k + idx == mid && idx < N && (mid == A.at(idx))) {
      left = mid;
    } else if (k + idx == mid) {
      return mid;
    } else if (k + idx < mid) {
      right = mid;
    } else {
      left = mid;
    }
  }
  return right;
}

int main() {
  cin >> N >> Q;
  
  A.assign(N,0);
  rep(i,0,N) cin >> A.at(i);
  sort(A.begin(), A.end());
  
  rep(i,0,Q) {
    ll tmp;
    cin >> tmp;
    
    cout << calc(tmp) << endl;
  }
}

