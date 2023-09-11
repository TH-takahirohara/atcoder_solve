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
  vector<int> P(N);
  rep(i,0,N) cin >> P.at(i);

  int ma = -1;
  int idx = 0;
  rep(i,0,N) {
    if (ma <= P.at(i)) {
      ma = max(ma, P.at(i));
      idx = i;
    }
  }

  if (P.at(0) == ma && idx == 0) cout << 0 << endl;
  else if (P.at(0) == ma && idx != 0) cout << 1 << endl;
  else cout << ma - P.at(0) + 1 << endl;
}
