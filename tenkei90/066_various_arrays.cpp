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
  int N;
  cin >> N;
  vector<double> L(N), R(N);
  rep(i,0,N) cin >> L.at(i) >> R.at(i);
  
  double ans = 0.0;
  rep(i,0,N) {
    rep(j,i+1,N) {
      double l1 = L.at(i), r1 = R.at(i);
      double l2 = L.at(j), r2 = R.at(j);
      
      double sum = 0.0;
      rep(num,l1,r1+1) {
        if (num - l2 > 0) sum += min(num - l2, r2 - l2 + 1);
      }
      ans += sum / ((r1 - l1 + 1.0) * (r2 - l2 + 1.0));
    }
  }
  
  cout << fixed << setprecision(10);
  cout << ans << endl;
}

