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
  vector<int> _T(N), _X(N);
  rep(i,0,N) cin >> _T.at(i) >> _X.at(i);

  vector<int> T = _T;
  vector<int> X = _X;

  reverse(T.begin(), T.end());
  reverse(X.begin(), X.end());

  vector<int> mst(N+1);
  vector<int> kusuri(N+1);
  vector<int> pors; // ポーション拾ったかどうか
  rep(i,0,N) {
    if (T.at(i) == 2) {
      int x = X.at(i);
      mst.at(x)++;
    } else { // ポーション
      int x = X.at(i);
      if (mst.at(x) > 0) {
        kusuri.at(x)++;
        mst.at(x)--;
        pors.push_back(1);
      } else {
        pors.push_back(0);
      }
    }
  }

  bool can = true;
  rep(i,0,N+1) {
    if (mst.at(i) > 0) can = false;
  }

  if (!can) {
    cout << -1 << endl;
  } else {
    reverse(pors.begin(), pors.end()); // 反転していたので、元に戻す
    int ans = 0;
    int answer = 0;
    int pos_idx = 0;
    vector<int> mons(N+1);
    vector<int> kusu(N+1);
    rep(i,0,N) {
      if (_T.at(i) == 1) { // ポーション
        if (pors.at(pos_idx) == 1) { // 拾った
          ans++;
          answer = max(answer, ans);
        }
        pos_idx++;
      } else { // モンスター
        ans--;
      }
    }
    cout << answer << endl;
    rep(i,0,pors.size()) {
      cout << pors.at(i) << " ";
    }
    cout << endl;
  }
}
