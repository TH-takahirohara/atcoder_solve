// 085 役数の個数は少ない 工夫した全探索／約数列挙の復習
// 分からず、解説を見た。解説に実装例が載っており、
// 解説を見た次の日にそれを思い出しながら書いてACした。
#include <bits/stdc++.h>
#include <atcoder/segtree>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint1000000007;
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
  ll K;
  cin >> K;
  
  vector<ll> vec;
  for (ll i=1; i*i<=K; i++) {
    if (K % i != 0) continue;
    vec.push_back(i);
    if (K/i != i) vec.push_back(K/i);
  }
  
  sort(vec.begin(), vec.end());
  
  ll ans = 0LL;
  rep(i,0,(int)vec.size()) {
    rep(j,i,(int)vec.size()) {
      if ((K/vec.at(i)) < vec.at(j)) continue;
      if (K % (vec.at(i) * vec.at(j)) != 0) continue;
      if (vec.at(j) <= K / (vec.at(i) * vec.at(j))) ans++;
    }
  }
  cout << ans << endl;
}

