#include <bits/stdc++.h>
// #include <atcoder/segtree>
using namespace std;
// using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

int main() {
  int N; cin >> N;
  vector<ll> A(N);
  rep(i,0,N) cin >> A.at(i);

  int minus_cnt = 0;
  bool zero_exist = false;
  rep(i,0,N) {
    if (A.at(i) == 0) zero_exist = true;
    if (A.at(i) < 0) minus_cnt++;
  }

  ll sum = 0;
  ll min_abs = 1e10;
  rep(i,0,N) {
    sum += abs(A.at(i));
    if (abs(A.at(i)) < min_abs) min_abs = abs(A.at(i));
  }

  if (minus_cnt % 2 == 1 && !zero_exist) {
    sum -= 2*min_abs;
  }
  cout << sum << endl;
}
