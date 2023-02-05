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
  vector<int> vec(N);
  rep(i,0,N) cin >> vec.at(i);

  int st = vec.at(0);
  rep(i,1,N) {
    st = __gcd(st, vec.at(i));
  }
  // cout << st << endl;

  bool can = true;
  int ans = 0;
  rep(i,0,N) {
    int tmp = 0;
    int tar = vec.at(i) / st;
    while (tar > 0) {
      if (tar % 2 == 0) {
        tar /= 2;
        tmp++;
      } else if (tar % 3 == 0) {
        tar /= 3;
        tmp++;
      } else {
        break;
      }
    }
    if (tar > 1) {
      can = false;
      break;
    } else {
      ans += tmp;
    }
  }
  if (can) cout << ans << endl;
  else cout << -1 << endl;
}
