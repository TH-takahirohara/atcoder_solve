#include <bits/stdc++.h>
// #include <atcoder/segtree>
using namespace std;
// using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

ll rui(int k) {
  ll res = 1;
  rep(i,0,k) {
    res *= 10;
  }
  return res;
}

int main() {
  ll X;
  int K;
  cin >> X >> K;
  // int tmpx = X;

  rep(i,0,K) {
    ll tmpx = X;
    rep(j,0,i) {
      tmpx /= 10;
    }
    ll tar = tmpx % 10; 
    // cout << "tar: " << tar << endl;
    if (tar >= 5) {
      X += rui(i+1);
      X -= tar * rui(i);
    } else {
      X -= tar * rui(i);
    }
    // X /= 10;
    // cout << X << endl;
  }
  cout << X << endl;
}
