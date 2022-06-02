// 075 O(√N)での素因数分解
// manyのテストケースがすべてWAしており、manyのうち１つのテストケースを見た後に自力でACした。
// 最初にやっていたやり方で合っていたが、別の箇所の間違いからそれとは別の考察をしてしまい、
// その考察が間違っていた。
#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

template<class T> bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  else return false;
}

int main() {
  ll N;
  cin>>N;
  ll iniN = N;
  
  ll all = 0;
  for (ll i=2; i*i <= iniN; i++) {
    if (N % i != 0) continue;
    ll cnt = 0;
    while (N % i == 0) {
      cnt++;
      N /= i;
    }
    all += cnt;
  }
  if (N != iniN && N != 1) all++;
  
  if (all == 0) {
    cout << 0 << endl;
  } else {
    ll ans = 0;
    all = all - 1;
    while (all > 0) {
      ans++;
      all /= 2;
    }
    cout << ans << endl;
  }
}
