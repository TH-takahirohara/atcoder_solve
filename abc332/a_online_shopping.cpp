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
  int N, S, K;
  cin >> N >> S >> K;
  vector<int> P(N), Q(N);
  rep(i,0,N) cin >> P.at(i) >> Q.at(i);
  int shou = 0;
  rep(i,0,N) {
    shou += (P.at(i) * Q.at(i));
  }

  if (shou >= S) {
    cout << shou << endl;
  } else {
    cout << shou + K << endl;
  }
}
