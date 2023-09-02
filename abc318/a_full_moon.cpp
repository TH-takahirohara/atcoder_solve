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
  int N, M, P;
  cin >> N >> M >> P;

  if (N < M) {
    cout << 0 << endl;
  } else if (N == M) {
    cout << 1 << endl;
  } else {
    cout << (N - M) / P + 1 << endl;
  }
}
