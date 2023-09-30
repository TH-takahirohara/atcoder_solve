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
  string S, T;
  cin >> S >> T;

  bool is_settou = true;
  bool is_setubi = true;

  rep(i,0,N) {
    if (S.at(i) != T.at(i)) {
      is_settou = false;
    }
  }

  rep(i,0,N) {
    if (S.at(i) != T.at(i+M-N)) {
      is_setubi = false;
    }
  }

  if (is_settou && is_setubi) cout << 0 << endl;
  else if (is_settou && !is_setubi) cout << 1 << endl;
  else if (!is_settou && is_setubi) cout << 2 << endl;
  else cout << 3 << endl;
}
