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

  string ans = "";
  rep(i,0,10) {
    if (N % 2 == 0) ans = '0' + ans;
    else ans = '1' + ans;
    N /= 2;
  }

  cout << ans << endl;
}
