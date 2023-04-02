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
  int N, P, Q, R, S;
  cin >> N >> P >> Q >> R >> S;
  P--; Q--; R--; S--;
  vector<int> A(N), B(N);
  rep(i,0,N) cin >> A.at(i);

  rep(i,0,N) {
    if (i >= P && i <= Q) {
      B.at(i) = A.at(R+(i-P));
    } else if (i >= R && i <= S) {
      B.at(i) = A.at(P+(i-R));
    } else {
      B.at(i) = A.at(i);
    }
  }
  rep(i,0,N) {
    cout << B.at(i) << " ";
  }
}
