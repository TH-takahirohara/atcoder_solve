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
  ll a,b,n;
  cin >> a >> b >> n;

  if (n < b-1) {
    cout << (a*n)/b - a*(n/b) << endl;
  } else {
    cout << (a*(b-1))/b - a*((b-1)/b) << endl;
  }
}
