#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
template<class T> bool chmin(T& a, T b) {if (a > b) {a = b; return true;} else return false;}
template<class T> bool chmax(T& a, T b) {if (a < b) {a = b; return true;} else return false;}
// 桁数指定： cout << fixed << setprecision(10)

int main() {
  ll N;
  cin >> N;
  vector<bool> vec(300005, true);
  vec.at(0) = false;
  vec.at(1) = false;
  rep(i,2,300001) {
    if (!vec.at(i)) continue;
    for (int q = i*2; q <= 300000; q += i) {
      vec.at(q) = false;
    }
  }

  vector<ll> pr;
  rep(i,2,300000) {
    if (vec.at(i)) pr.push_back(i);
  }

  int sz = pr.size();
  int ans = 0;
  for (int i=0; i < sz; i++) {
    ll a = pr.at(i);
    if (a*a*a*a*a > N) break;
    for (int j=i+1; j < sz; j++) {
      ll b = pr.at(j);
      if (a*a*b > N) break;
      ll c = floor(sqrt(N / (a*a*b)));
      int kosuu = upper_bound(pr.begin(), pr.end(), c) - pr.begin();
      int tmp = max(kosuu - j - 1, 0);
      ans += tmp;
    }
  }

  cout << ans << endl;
}
