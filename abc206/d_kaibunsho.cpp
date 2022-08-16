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

  vector<int> ch(2000000);
  rep(i,0,N+1) ch.at(i) = i;

  int ans = 0;
  rep(i,0,N/2) {
    int l = ch.at(A.at(i));
    int r = ch.at(A.at(N-1-i));
    if (l == r) continue;
    ch.at(A.at(N-1-i)) = l;
    ans++;
  }
  cout << ans << endl;
}
