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
  int l1,r1,l2,r2;
  cin >> l1 >> r1 >> l2 >> r2;
  
  vector<int> vec(101, 0);
  rep(i,l1,r1) vec.at(i) = 1;
  rep(i,l2,r2) if (vec.at(i) == 1) vec.at(i) = 2;
  
  int ans = 0;
  rep(i,0,101) if (vec.at(i) == 2) ans++;
  cout << ans << endl;
}

