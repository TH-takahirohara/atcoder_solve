#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

typedef vector<vector<int>> Graph;
double PI = 3.14159265359;
ll MOD = 1000000007LL;

void add(ll &x, ll y) {
  x += y;
  x %= MOD;
}

int main() {
  ll S;
  cin >> S;
  
  vector<ll> dp(2001);
  
  rep(i,3,2001) {
    rep(j,3,i-2) {
      add(dp.at(i), dp.at(j));
    }
    add(dp.at(i), 1);
  }
  
  cout << dp.at(S) << endl;
}

