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
  vector<ll> A(N);
  rep(i,0,N) cin >> A.at(i);
  vector<string> S(N);
  rep(i,0,N) cin >> S.at(i);
  int Q;
  cin >> Q;
  vector<int> U(Q), V(Q);
  rep(i,0,Q) {
    int u,v;
    cin >> u >> v;
    u--; v--;
    U.at(i) = u;
    V.at(i) = v;
  }

  vector<vector<int>> keiro(N, vector<int>(N, 1e9));
  vector<vector<ll>> kati(N, vector<ll>(N));

  rep(i,0,N) {
    rep(j,0,N) {
      if (S.at(i).at(j) == 'Y') keiro.at(i).at(j) = 1;
    }
  }
  rep(i,0,N) {
    rep(j,0,N) {
      if (S.at(i).at(j) == 'Y') {
        kati.at(i).at(j) = A.at(i);
      }
    }
  }
  rep(k,0,N) {
    rep(i,0,N) {
      rep(j,0,N) {
        if (keiro.at(i).at(j) > (keiro.at(i).at(k) + keiro.at(k).at(j))) {
          keiro.at(i).at(j) = keiro.at(i).at(k) + keiro.at(k).at(j);
          kati.at(i).at(j) = kati.at(i).at(k) + kati.at(k).at(j);
        } else if (keiro.at(i).at(j) == (keiro.at(i).at(k) + keiro.at(k).at(j))) {
          if (kati.at(i).at(j) < kati.at(i).at(k) + kati.at(k).at(j)) {
            kati.at(i).at(j) = kati.at(i).at(k) + kati.at(k).at(j);
          }
        }
      }
    }
  }

  rep(i,0,Q) {
    if (keiro.at(U.at(i)).at(V.at(i)) > (5e8)) {
      cout << "Impossible" << endl;
    } else {
      cout << keiro.at(U.at(i)).at(V.at(i)) << " " << kati.at(U.at(i)).at(V.at(i)) + A.at(V.at(i)) << endl;
    }
  }
}
