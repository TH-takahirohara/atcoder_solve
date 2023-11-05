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
  vector<int> A(M), B(M);
  rep(i,0,M) {
    int a; cin >> a;
    a--;
    A.at(i) = a;
  }
  rep(i,0,M) {
    int b; cin >> b;
    b--;
    B.at(i) = b;
  }

  vector<vector<int>> G(N);
  rep(i,0,M) {
    G.at(A.at(i)).push_back(B.at(i));
    G.at(B.at(i)).push_back(A.at(i));
  }

  vector<int> num(N, -1);
  vector<bool> seen(N, false);

  string ans = "Yes";

  rep(i,0,N) {
    if (G.at(i).size() == 0) continue;
    if (seen.at(i)) continue;
    num.at(i) = 0;
    seen.at(i) = true;
    queue<int> que;
    que.push(i);
    while (!que.empty()) {
      int v = que.front();
      que.pop();
      seen.at(v) = true;
      for (auto nv : G.at(v)) {
        if (num.at(nv) != -1 && num.at(v) == num.at(nv)) {
          ans = "No";
          cout << "No" << endl;
          return 0;
        } else if (num.at(nv) != -1 && num.at(v) != num.at(nv)) { // 次が今と違う場合
          continue;
        } else if (num.at(nv) == -1) { // まだ訪れてない場合
          num.at(nv) = 1 - num.at(v);
          que.push(nv);
        }
      }
    }
  }

  cout << ans << endl;
}
