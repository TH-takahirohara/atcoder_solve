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
  ll sum = 0LL;
  vector<ll> vec(N);
  rep(i,0,N) {
    ll a,b;
    cin >> a >> b;
    vec.at(i) = 2*a+b;
    sum -= a;
  }
    
  sort(vec.begin(), vec.end());
  reverse(vec.begin(), vec.end());
  
  int ans = 0;
  rep(i,0,N) {
    ans++;
    sum += vec.at(i);
    if (sum > 0) break;
  }
  cout << ans << endl;
}

