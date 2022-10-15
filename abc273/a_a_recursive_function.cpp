#include <bits/stdc++.h>
// #include <atcoder/segtree>
using namespace std;
// using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

int f(int k) {
  if (k==0) return 1;
  return k*f(k-1);
}

int main() {
  int N;
  cin >> N;
  
  cout << f(N) << endl;
}
