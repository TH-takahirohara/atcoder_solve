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

  if (N % 5 == 0) {
    cout << N << endl;
  } else if (N % 5 < 3) {
    cout << N - (N % 5) << endl;
  } else {
    cout << N - (N % 5) + 5 << endl;
  }
}
