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
  ll N; cin >> N;

  vector<ll> vec;
  for (ll i=1; i*i<=N; i++) {
    if (N % i != 0) continue;
    if (i != N / i) {
      vec.push_back(i);
      vec.push_back(N / i);
    } else {
      vec.push_back(i);
    }
  }

  sort(vec.begin(), vec.end());
  rep(i,0,vec.size()) cout << vec.at(i) << endl;
}
