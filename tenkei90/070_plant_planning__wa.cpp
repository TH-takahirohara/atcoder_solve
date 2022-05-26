// 070 x,y独立に考える
// x,y独立に考えるというところまではたどり着いた。
// ただ、三分探索の要領で解こうとしたが、4WAが出て結局諦めた。
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

ll INF = 1000000000000000000;

ll calc(vector<ll> arr, ll val) {
  ll res = 0;
  rep(i,0,(int)arr.size()) {
    res += abs(val - arr.at(i));
  }
  return res;
}

int main() {
  int N;
  cin>>N;
  vector<ll> X(N), Y(N);
  ll x_max = -INF, x_min = INF;
  ll y_max = -INF, y_min = INF;

  rep(i,0,N) {
    ll x,y;
    cin >> x >> y;
    X.at(i) = x;
    Y.at(i) = y;
    x_max = max(x_max, X.at(i));
    x_min = min(x_min, X.at(i));
    y_max = max(y_max, Y.at(i));
    y_min = min(y_min, Y.at(i));
  }
  
  ll right = x_max;
  ll left = x_min;
  rep(i,0,100) {
    ll c1 = (left+left+right) / 3;
    ll c2 = (left+right+right) / 3;
    
    if (calc(X, c1) <= calc(X, c2)) right = c2;
    else left = c1;
  }
  
  ll yright = y_max;
  ll yleft = y_min;
  rep(i,0,100) {
    ll c1 = (yleft+yleft+yright) / 3;
    ll c2 = (yleft+yright+yright) / 3;
    
    if (calc(Y, c1) <= calc(Y, c2)) yright = c2;
    else yleft = c1;
  }
  
  cout << calc(X, left+1) + calc(Y, yleft+1) << endl;
}

