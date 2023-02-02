#include <bits/stdc++.h>
// #include <atcoder/segtree>
using namespace std;
// using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

ll a, N;
ll ans = 10000000000LL;

vector<bool> seen(100000000, false);

void rec(ll x, ll kai) {
  if (x > 10000000LL) return;
  if (x == N) {
    ans = min(ans, kai);
    return;
  }
  
  if (seen.at(x)) return;
  seen.at(x) = true;
  
  rec(x*a, kai+1);
  
  string xstr = to_string(x);
  if (x >= 10 && xstr.at(xstr.size()-1) != '0') {
    char matsu = xstr.at(xstr.size()-1);
    rec(stoll(matsu + xstr.substr(0, xstr.size()-1)), kai+1);
  }
}

int main() {
  cin >> a >> N;
  
  rec(1,0);
  if (ans < 10000000000LL/2) cout << ans << endl;
  else cout << -1 << endl;
}

