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
  ll N;
  cin >> N;

  string ans = "";
  while (N > 0) {
    if (N % 2 == 0) {
      N /= 2;
      ans += 'B';
    } else {
      N -= 1;
      ans += 'A';
    }
  }

  reverse(ans.begin(), ans.end());
  cout << ans << endl;
}
