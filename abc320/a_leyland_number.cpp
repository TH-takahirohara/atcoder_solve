#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

int main() {
  int a, b;
  cin >> a >> b;
  int ans = 0;
  int sai1 = 1;
  int sai2 = 1;
  rep(i,0,b) {
    sai1 *= a;
  }
  rep(i,0,a) {
    sai2 *= b;
  }

  cout << sai1 + sai2 << endl;
}
