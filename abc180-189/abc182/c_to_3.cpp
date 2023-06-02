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
  string S;
  cin >> S;

  int N = S.size();
  int ans = 1e9;
  for (int i = 1; i < (1 << N); i++) {
    int sum_keta = 0;
    int ketasuu = 0;
    for (int j = 0; j < N; j++) {
      if (i & (1 << j)) {
        sum_keta += int(S.at(j));
        ketasuu++;
      }
    }
    if (sum_keta % 3 == 0) {
      ans = min(ans, N - ketasuu);
    }
  }

  if (ans == 1e9) cout << -1 << endl;
  else cout << ans << endl;
}
