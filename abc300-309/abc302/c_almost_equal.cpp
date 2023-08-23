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
  vector<string> S(N);
  rep(i,0,N) cin >> S.at(i);

  sort(S.begin(), S.end());

  do {
    bool can = true;
    for (int i=0; i < N-1; i++) {
      int tigau = 0;
      rep(j,0,M) {
        if (S.at(i).at(j) != S.at(i+1).at(j)) tigau++;
      }
      if (tigau != 1) can = false;
    }
    if (can) {
      cout << "Yes" << endl;
      return 0;
    }
  } while(next_permutation(S.begin(), S.end()));

  cout << "No" << endl;
}
