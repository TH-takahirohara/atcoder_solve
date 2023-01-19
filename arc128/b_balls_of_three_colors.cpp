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

int calc(int a, int b) {
  int ans = 2e9;
  if (abs(a - b) % 3 != 0) return ans;
  int kai1 = abs(a - b) / 3;
  int kai2 = max(a, b) - kai1;
  return kai1 + kai2;
}

int main() {
  int T;
  cin >> T;
  rep(i,0,T) {
    int r,g,b;
    cin >> r >> g >> b;
    if (r==g) {
      cout << r << endl;
      continue;
    } else if (r==b) {
      cout << r << endl;
      continue;
    } else if (g==b) {
      cout << g << endl;
      continue;
    }

    int ans = 2e9;
    ans = min(ans, calc(r,g));
    ans = min(ans, calc(r,b));
    ans = min(ans, calc(g,b));
    if (ans == 2e9) cout << -1 << endl;
    else cout << ans << endl;
  }
}
