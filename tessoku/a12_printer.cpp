// 答えで二分探索の基本的な形式 
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
  ll ng = 0;
  ll ok = 1e10;
  while (ok - ng > 1) {
    ll mid = (ng + ok) / 2;
    ll sum = 0;
    rep(i,0,N) {
      sum += mid / A.at(i);
    }
    if (sum >= K) ok = mid;
    else ng = mid;
  }
  cout << ok << endl;
}
