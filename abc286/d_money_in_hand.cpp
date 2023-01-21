#include <bits/stdc++.h>
// #include <atcoder/segtree>
using namespace std;
// using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

int main() {
  int N, X;
  cin >> N >> X;
  vector<int> A(N), B(N);
  rep(i,0,N) {
    cin >> A.at(i) >> B.at(i);
  }

  vector<vector<bool>> dp(N+1, vector<bool>(10005, false));
  dp.at(0).at(0) = true;

  rep(i,0,N) {
    rep(j,0,10003) {
      if (!dp.at(i).at(j)) continue;
      dp.at(i+1).at(j) = true;
      rep(k, 1, B.at(i)+1) { // 枚数分行う
        if (j + A.at(i) * k <= 10000) {
          dp.at(i+1).at(j + A.at(i) * k) = true;
        }
      }
    }
  }
  if (dp.at(N).at(X)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
