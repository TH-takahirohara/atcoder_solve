#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

int main() {
  ll N,Q;
  cin >> N >> Q;
  vector<ll> X(N), Y(N);
  rep(i,0,N) {
    ll x,y;
    cin >> x >> y;
    X.at(i) = x-y;
    Y.at(i) = x+y;
  }
  
  vector<ll> XORIG = X;
  vector<ll> YORIG = Y;
  
  sort(X.begin(), X.end());
  sort(Y.begin(), Y.end());
  
  ll xmin = X.at(0);
  ll xmax = X.at(N-1);
  ll ymin = Y.at(0);
  ll ymax = Y.at(N-1);
  
  rep(i,0,Q) {
    ll q;
    cin >> q;
    q--;
    
    cout << max({abs(XORIG.at(q) - xmin), abs(XORIG.at(q) - xmax), abs(YORIG.at(q) - ymin), abs(YORIG.at(q) - ymax)}) << endl;
  }
}
