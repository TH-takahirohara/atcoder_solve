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
  vector<ull> A(N);
  rep(i,0,N) cin >> A.at(i);
  string S;
  cin >> S;

  vector<ull> m0rui(N), m1rui(N), m2rui(N), x0rui(N), x1rui(N), x2rui(N);
  rep(i,0,N) {
    if (i > 0) {
      m0rui.at(i) = m0rui.at(i-1);
      m1rui.at(i) = m1rui.at(i-1);
      m2rui.at(i) = m2rui.at(i-1);
    }
    if (S.at(i) != 'M') continue;
    if (A.at(i) == 0) m0rui.at(i)++;
    else if (A.at(i) == 1) m1rui.at(i)++;
    else m2rui.at(i)++;
  }

  rep(i,0,N) {
    if (i > 0) {
      x0rui.at(i) = x0rui.at(i-1);
      x1rui.at(i) = x1rui.at(i-1);
      x2rui.at(i) = x2rui.at(i-1);
    }
    if (S.at(N-i-1) != 'X') continue;
    if (A.at(N-i-1) == 0) x0rui.at(i)++;
    else if (A.at(N-i-1) == 1) x1rui.at(i)++;
    else x2rui.at(i)++;
  }

  ull ans = 0;
  rep(i,0,N) {
    if (S.at(i) != 'E') continue;
    if (i == 0 || i == N-1) continue;
    int idxg = N-i-2;
    if (A.at(i) == 0) {
      ans += m0rui.at(i-1) * (x0rui.at(idxg) + x1rui.at(idxg) * 2 + x2rui.at(idxg));
      ans += m1rui.at(i-1) * (x0rui.at(idxg) * 2 + x1rui.at(idxg) * 2 + x2rui.at(idxg) * 3);
      ans += m2rui.at(i-1) * (x0rui.at(idxg) + x1rui.at(idxg) * 3 + x2rui.at(idxg));
    } else if (A.at(i) == 1) {
      ans += m0rui.at(i-1) * (x0rui.at(idxg) * 2 + x1rui.at(idxg) * 2 + x2rui.at(idxg) * 3);
      ans += m1rui.at(i-1) * (x0rui.at(idxg) * 2);
      ans += m2rui.at(i-1) * (x0rui.at(idxg) * 3);
    } else {
      ans += m0rui.at(i-1) * (x0rui.at(idxg) + x1rui.at(idxg) * 3 + x2rui.at(idxg));
      ans += m1rui.at(i-1) * (x0rui.at(idxg) * 3);
      ans += m2rui.at(i-1) * (x0rui.at(idxg));
    }
  }
  cout << ans << endl;
}
