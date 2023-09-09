#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

int gcd(int x, int y) { return (x % y)? gcd(y, x % y): y; }
int lcm(int x, int y) { return x / gcd(x, y) * y; }

int main() {
  int N;
  ll X, Y;
  cin >> N >> X >> Y;
  vector<ll> P(N-1);
  vector<ll> T(N-1);
  rep(i,0,N-1) {
    cin >> P.at(i) >> T.at(i);
  }
  int Q;
  cin >> Q;

  ll p1 = P.at(0);
  ll saikou = p1;
  rep(i,1,N-1) {
    saikou = lcm(saikou, P.at(i));
  }

  // cout << "saikou: " << saikou << endl;

  vector<ll> jikans(saikou);
  rep(ite,0,(int)saikou) {
    ll time = (ll)ite + X;
    rep(i,0,N-1) {
      ll amari = time % P.at(i);
      if (amari == 0) time += T.at(i);
      else time += (P.at(i) - amari) + T.at(i);
    }
    time += Y;
    jikans.at(ite) = time;
  }
  
  rep(i,0,Q) {
    ll q;
    cin >> q;
    ll ama = q % saikou;
    cout << q - ama + jikans.at(ama) << endl;
  }
}
