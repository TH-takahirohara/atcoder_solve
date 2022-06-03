// 076 円環を列にして二倍にする
// しゃくとり法にqueueを使って解いた。かなり楽に書けた。
// 参考：https://qiita.com/keroru/items/6e0a22e8c9bf2a24dc68
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
  vector<ll> A(N);
  ll sum = 0;
  rep(i,0,N) {
    ll a;
    cin>>a;
    
    A.at(i) = a;
    sum += a;
  }
  
  if (sum % 10 != 0) {
    cout << "No" << endl;
    return 0;
  }
  
  vector<ll> vec;
  rep(i,0,N) vec.push_back(A.at(i));
  rep(i,0,N) vec.push_back(A.at(i));
  
  queue<ll> que;
  ll div10 = sum / 10;
  ll tmp = 0;
  ll can = false;
  for (auto v : vec) {
    que.push(v);
    tmp += v;
    
    if (tmp == div10) can = true;
    
    while (tmp > div10) {
      tmp -= que.front();
      que.pop();
    }
  }
  if (can) cout << "Yes" << endl;
  else cout << "No" << endl;
}

