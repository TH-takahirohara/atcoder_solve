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
  int N, M;
  cin >> N >> M;
  vector<int> A(M);
  rep(i,0,M) cin >> A.at(i);
  vector<string> S(N);
  rep(i,0,N) cin >> S.at(i);

  vector<int> goukei(N);
  rep(i,0,N) {
    int sum = 0;
    rep(j,0,M) {
      if (S.at(i).at(j) == 'o') sum += A.at(j);
    }
    sum += (i+1);
    goukei.at(i) = sum;
  }

  rep(i,0,N) {
    vector<int> mada;
    rep(j,0,M) {
      if (S.at(i).at(j) == 'x') mada.push_back(A.at(j));
    }
    sort(mada.begin(), mada.end());
    reverse(mada.begin(), mada.end());

    int hoka_max = 0;
    rep(j,0,N) {
      if (j==i) continue;
      hoka_max = max(hoka_max, goukei.at(j));
    }

    int cnt = 0;
    int toku = goukei.at(i);
    if (toku > hoka_max) {
      cout << 0 << endl;
    } else {
      rep(j,0,mada.size()) {
        toku += mada.at(j);
        cnt++;
        if (toku > hoka_max) {
          cout << cnt << endl;
          break;
        }
      }
    }
  }
}
