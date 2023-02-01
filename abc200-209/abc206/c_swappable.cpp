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
  int N;
  cin >> N;
  vector<int> A(N);
  rep(i,0,N) cin >> A.at(i);

  map<int,vector<int>> mp;
  rep(i,0,N) {
    mp[A.at(i)].push_back(i);
  }

  ll ans = 0;
  rep(i,0,N) {
    int val = A.at(i);
    ll cnt = mp[val].size() - (upper_bound(mp[val].begin(), mp[val].end(), i) - mp[val].begin());
    ans += N - i - 1 - cnt;
  }
  cout << ans << endl;
}
