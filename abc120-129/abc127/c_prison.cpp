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

  int max_l = 0, min_r = 1e9;

  rep(i,0,M) {
    int l, r;
    cin >> l >> r;
    max_l = max(max_l, l);
    min_r = min(min_r, r);
  }

  cout << max(min_r - max_l + 1, 0) << endl;
}
