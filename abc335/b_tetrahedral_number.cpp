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
  cin >> N;

  rep(i,0,N+1) {
    rep(j,0,N+1) {
      rep(k,0,N+1) {
        if (i+j+k<=N) {
          cout << i << " " << j << " " << k << endl;
        }
      }
    }
  }
}
