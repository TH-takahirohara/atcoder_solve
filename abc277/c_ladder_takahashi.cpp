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
  map<int, vector<int>> mp;
  rep(i,0,N) {
    int a,b;
    cin >> a >> b;
    mp[a].push_back(b);
    mp[b].push_back(a);
  }

  map<int, bool> seenmp;
  queue<int> que;
  que.push(1);
  int ans = -1;
  while (!que.empty()) {
    int v = que.front(); que.pop();
    ans = max(ans, v);

    if (seenmp.count(v) && seenmp.at(v)) continue;
    seenmp[v] = true;

    if (!mp.count(v)) continue;
    for (auto nv : mp.at(v)) {
      if (seenmp.count(nv) && seenmp.at(nv)) continue;
      que.push(nv);
    }
  }
  cout << ans << endl;
}
