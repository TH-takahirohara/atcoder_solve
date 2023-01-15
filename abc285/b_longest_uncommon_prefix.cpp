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

  rep(i,1,N) {
    int now = 0;
    rep(k,0,N-i) {
      if (S.at(k) == S.at(k+i)) {
        break;
      } else {
        now++;
      }
    }
    cout << now << endl;
  }
}
