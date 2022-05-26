// 070 x,y独立に考える
// 解説後AC
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

  rep(i,0,N) {
    ll x,y;
    cin >> x >> y;
    X.at(i) = x;
    Y.at(i) = y;
  }
  
  sort(X.begin(), X.end());
  sort(Y.begin(), Y.end());
  
  ll midx_idx = (ll)X.size() / 2;
  ll midy_idx = (ll)Y.size() / 2;
  ll midx = X.at(midx_idx);
  ll midy = Y.at(midy_idx);
  
  ll sumx = 0, sumy = 0;
  rep(i,0,N) {
    sumx += abs(midx - X.at(i));
  }
  rep(i,0,N) {
    sumy += abs(midy - Y.at(i));
  }
  
  cout << sumx + sumy << endl;
}

