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
  int N, M;
  cin >> N >> M;
  vector<int> vec(M);
  vector<vector<int>> G(N);
  rep(i,0,M) {
    int a;
    cin >> a;
    a--;
    G.at(a).push_back(a+1);
    G.at(a+1).push_back(a);
  }

  vector<int> ans = {};

  vector<bool> seen(N, false);
  rep(i,0,N) {
    if (seen.at(i)) continue;

    queue<int> que;
    que.push(i);
    vector<int> tmpv = {};
    while (!que.empty()) {
      int v = que.front();
      que.pop();
      
      if (seen.at(v)) continue;
      seen.at(v) = true;
      tmpv.push_back(v);

      for (auto nv : G.at(v)) {
        if (seen.at(nv)) continue;
        que.push(nv);
      }
    }

    sort(tmpv.begin(), tmpv.end());
    reverse(tmpv.begin(), tmpv.end());
    rep(i,0,tmpv.size()) {
      ans.push_back(tmpv.at(i)+1);
    }
  }

  rep(i,0,ans.size()) {
    cout << ans.at(i) << " ";
  }
  cout << endl;
}
