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
  int N;
  string S;
  cin >> N >> S;

  rep(i,0,N-2) {
    if (S.at(i) == 'A' && S.at(i+1) == 'B' && S.at(i+2) == 'C') {
      cout << i+1 << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}
