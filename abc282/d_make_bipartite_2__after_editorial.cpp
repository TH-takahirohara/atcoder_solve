// コンテスト時の解答でほぼ合っていたが、１つでも二部グラフでない連結成分があったら、
// グラフ全体が二部グラフにはならないために答えは0になるという認識ができておらず、
// そのケースに対応できていないためにいくつかWAを出してしまっていた。解説を見て気づいて書き直し、AC。
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
  int N, M;
  cin >> N >> M;

  vector<vector<int>> G(N);
  rep(i,0,M) {
    int u,v;
    cin >> u >> v;
    u--; v--;
    G.at(u).push_back(v);
    G.at(v).push_back(u);
  }

  vector<bool> is_nibu_g(N, true);
  vector<int> maru(N);
  vector<int> batsu(N);
  vector<int> color(N, -1); // 頂点の色の種類を0か1で表す
  vector<int> group_nums(N, -1); // 各頂点が所属するグループ番号

  int group_num = 0;
  rep(i,0,N) {
    if (color.at(i) != -1) continue;
    color.at(i) = 0; // 0はmaruに相当

    queue<int> que;
    que.push(i);
    while (!que.empty()) {
      int v = que.front();
      que.pop();

      group_nums.at(v) = group_num;
      if (color.at(v) == 0) maru.at(group_num)++;
      else if (color.at(v) == 1) batsu.at(group_num)++;

      for (auto nv : G.at(v)) {
        if (color.at(nv) != -1) {
          if (color.at(v) == color.at(nv)) is_nibu_g.at(group_num) = false; // 二部グラフではない
          continue;
        }
        color.at(nv) = 1 - color.at(v);
        que.push(nv);
      }
    }

    group_num++;
  }

  ll nibu_chouten_num = 0;
  rep(i,0,N) {
    if (is_nibu_g.at(i)) {
      nibu_chouten_num += (ll)maru.at(i);
      nibu_chouten_num += (ll)batsu.at(i);
    }
  }

  ll ans = 0LL;
  rep(i,0,N) {
    int g_num = group_nums.at(i);
    // 二部グラフでない連結成分がある場合は、その時点でグラフ全体が二部グラフにはならないので0を返す
    if (!is_nibu_g.at(g_num)) {
      cout << 0 << endl;
      return 0;
    }

    ll douren_gyaku = 0;
    if (color.at(i) == 0) { // maruの場合
      douren_gyaku += (batsu.at(g_num) - G.at(i).size());
    } else { // batsuの場合
      douren_gyaku += (maru.at(g_num) - G.at(i).size());
    }

    ll betunibu = (nibu_chouten_num - maru.at(g_num) - batsu.at(g_num));
    ans += (douren_gyaku + betunibu);
  }
  cout << ans / 2 << endl;
}
