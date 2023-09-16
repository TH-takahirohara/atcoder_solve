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

  priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pqsoto;
  priority_queue<int, vector<int>, greater<int>> pqretsu;
  rep(i,0,N) {
    pqretsu.push(i);
  }

  vector<ll> ans(N);
  rep(i,0,M) {
    ll t, w, s;
    cin >> t >> w >> s;
    while (!pqsoto.empty()) {
      pair<ll,int> tp = pqsoto.top();
      if (tp.first > t) break;
      pqsoto.pop();
      pqretsu.push(tp.second);
    }
    if (pqretsu.empty()) continue;
    int saizen = pqretsu.top();
    pqretsu.pop();
    ans.at(saizen) += w;
    pqsoto.push(make_pair(t+s, saizen));
  }

  rep(i,0,N) {
    cout << ans.at(i) << endl;
  }
}
