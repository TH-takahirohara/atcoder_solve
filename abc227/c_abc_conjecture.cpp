#include <bits/stdc++.h>
// #include <atcoder/segtree>
using namespace std;
// using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

int main() {
  ll N;
  cin >> N;
  
  ll ans = 0LL;
  for (ll a=1; a*a*a <= N; a++) {
    for (ll b=a; b*b <= N; b++) {
      if (N/(a*b) < b) break; 
      ans += N/(a*b) - b + 1;
    }
  }
  cout << ans << endl;
}

