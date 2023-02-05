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
  rep(i,0,N) {
    int tmp; cin >> tmp;
    A.at(i) = tmp;
  }

  vector<int> ans(2*N+2);
  rep(i,0,N) {
    int v = A.at(i);
    if (2*(i+1) <= 2*N + 1) ans.at(2*(i+1)) = ans.at(v) + 1;
    if (2*(i+1) + 1 <= 2*N + 1) ans.at(2*(i+1)+1) = ans.at(v) + 1;
  }

  rep(i,1,2*N+2) {
    cout << ans.at(i) << endl;
  }
}
