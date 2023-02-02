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
  ll N,A,B;
  cin >> N >> A >> B;
  
  ll P,Q,R,S;
  cin >> P >> Q >> R >> S;
  
  for (ll r=P; r <= Q; r++) {
    for (ll c=R; c <= S; c++) {
      if (abs(r-A) == abs(c-B)) {
        if (r-A == c-B) {
          ll k = r-A;
          if (max(1-A,1-B) <= k && k <= min(N-A,N-B)) cout << "#";
          else cout << ".";
        } else {
          ll k = r-A;
          if (max(1-A,B-N) <= k && k <= min(N-A,B-1)) cout << "#";
          else cout << ".";
        }
      } else {
        cout << ".";
      }
    }
    cout << endl;
  }
}

