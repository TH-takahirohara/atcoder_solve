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
  int N,Q;
  cin >> N >> Q;

  map<int,set<int>> mp;
  rep(i,0,Q) {
    int t,a,b;
    cin >> t >> a >> b;

    if (t == 1) {
      mp[a].insert(b);
    } else if (t == 2) {
      if (!mp[a].count(b)) continue;
      mp[a].erase(b);
    } else {
      if (mp[a].count(b) && mp[b].count(a)) cout << "Yes" << endl;
      else cout << "No" << endl;
    }
  }
}
