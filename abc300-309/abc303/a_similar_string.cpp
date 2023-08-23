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
  string S, T;
  cin >> S >> T;

  string ans = "Yes";
  rep(i,0,N) {
    char s = S.at(i);
    char t = T.at(i);

    if (s == t) continue;
    if ((s == '1' && t == 'l') || (s == 'l' && t == '1')) continue;
    if ((s == '0' && t == 'o') || (s == 'o' && t == '0')) continue;
    ans = "No";
  }
  cout << ans << endl;
}
