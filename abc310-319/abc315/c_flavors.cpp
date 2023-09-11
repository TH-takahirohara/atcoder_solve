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
  vector<pair<ll,ll>> vec(400000);
  set<ll> st;
  rep(i,0,N) {
    ll f, s;
    cin >> f >> s;
    st.insert(f);
    if (s > vec.at(f).first) {
      ll tmp = 0;
      tmp = vec.at(f).first;
      vec.at(f).first = s;
      vec.at(f).second = tmp;
    } else if (s > vec.at(f).second) {
      vec.at(f).second = s;
    }
  }

  if (st.size() == 1) {
    rep(i,0,300005) {
      if (vec.at(i).first > 0) {
        cout << vec.at(i).first + vec.at(i).second / 2 << endl;
        return 0;
      }
    }
  } else {
    ll ans = 0;
    
    rep(i,0,300005) {
      if (vec.at(i).second > 0) {
        ans = max(ans, vec.at(i).first + vec.at(i).second / 2);
      }
    }

    int idx_max = -1;
    ll mx = 0;
    rep(i,0,300005) {
      if (vec.at(i).first == 0) continue;
      if (vec.at(i).first > mx) {
        idx_max = i;
        mx = vec.at(i).first;
      }
    }

    ll mx2 = 0;
    rep(i,0,300005) {
      if (vec.at(i).first == 0) continue;
      if (i == idx_max) continue;
      if (vec.at(i).first > mx2) {
        mx2 = vec.at(i).first;
      }
    }

    ans = max(ans, mx + mx2);
    cout << ans << endl;
  }
}
