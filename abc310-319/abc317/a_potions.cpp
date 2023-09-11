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
  int N, H, X;
  cin >> N >> H >> X;
  vector<int> P(N);
  rep(i,0,N) cin >> P.at(i);

  rep(i,0,N) {
    if (H + P.at(i) >= X) {
      cout << i + 1 << endl;
      return 0;
    }
  }
}
