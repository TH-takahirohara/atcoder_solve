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
  ull L, R;
  cin >> L >> R;

  vector<ull> ruis(70);
  ull kake = 1;
  rep(i,0,62) {
    ruis.at(i) = kake;
    kake *= 2;
  }

  vector<pair<ull,ull>> vec;
  ull l = L;
  while (l < R) {
    ull tl = l, tr = l+1;
    rep(i,0,61) {
      ull rui = ruis.at(i);
      if (l % rui != 0) break;

      ull j = l / rui;
      if (rui * (j+1) <= R) {
        tr = max(tr, rui * (j+1));
      }
    }

    vec.push_back(make_pair(tl,tr));
    l = tr;
  }

  cout << vec.size() << endl;
  rep(i,0,vec.size()) {
    auto p = vec.at(i);
    cout << p.first << " " << p.second << endl;
  }
}
