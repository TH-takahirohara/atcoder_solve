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
  cin >> N;
  // priority_queue<ll, vector<ll>, greater<ll>> pq;
  set<ll> size_st;
  unordered_map<ll,ll> mp;
  rep(i,0,N) {
    ll s, c;
    cin >> s >> c;
    mp[s] = c;
    size_st.insert(s);
  }

  ll ans = 0;
  while (!size_st.empty()) {
    ll min_size = *begin(size_st);
    size_st.erase(min_size);

    ll kazu = mp.at(min_size);
    ll han = kazu / 2;
    ll amari = kazu % 2;

    ans += amari;
    if (han == 0) continue;

    size_st.insert(2*min_size);
    if (mp.count(2*min_size)) {
      mp.at(2*min_size) += han;
    } else {
      mp[2*min_size] = han;
    }
  }
  cout << ans << endl;
}
