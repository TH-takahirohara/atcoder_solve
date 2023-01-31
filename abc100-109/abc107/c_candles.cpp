// 解説放送を見てから実装してAC
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
  int N, K;
  cin >> N >> K;
  vector<int> X(N);
  rep(i,0,N) cin >> X.at(i);

  int ans = 1e9;
  for (int i=0; i <= (N-K); i++) {
    if (X.at(i+K-1) < 0) {
      ans = min(ans, abs(X.at(i)));
    } else if (X.at(i) < 0 && X.at(i+K-1) >= 0) {
      int tika = min(abs(X.at(i)), abs(X.at(i+K-1)));
      int tooi = max(abs(X.at(i)), abs(X.at(i+K-1)));
      ans = min(ans, tika * 2 + tooi);
    } else {
      ans = min(ans, X.at(i+K-1));
    }
  }

  cout << ans << endl;
}
