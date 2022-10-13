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
  int N;
  cin >> N;
  vector<int> A(N);
  rep(i,0,N) cin >> A.at(i);

  vector<int> cnts(1000005);
  rep(i,0,N) {
    cnts.at(A.at(i))++;
  }

  vector<bool> candiv(1000005);
  rep(i,1,1000001) {
    if (cnts.at(i) == 0) continue;
    for (int j=2*i; j<=1000000; j+=i) {
      candiv.at(j) = true;
    }
  }

  int ans = 0;
  rep(i,0,N) {
    if (cnts.at(A.at(i)) > 1) continue;
    if (!candiv.at(A.at(i))) ans++;
  }
  cout << ans << endl;
}
