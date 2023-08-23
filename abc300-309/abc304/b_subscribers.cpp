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

  if (N <= 1000 - 1) {
    cout << N << endl;
  } else if (N <= 10000 - 1) {
    cout << N / 10 * 10 << endl;
  } else if (N <= 100000 - 1) {
    cout << N / 100 * 100 << endl;
  } else if (N <= 1000000 - 1) {
    cout << N / 1000 * 1000 << endl;
  } else if (N <= 10000000 - 1) {
    cout << N / 10000 * 10000 << endl;
  } else if (N <= 100000000 - 1) {
    cout << N / 100000 * 100000 << endl;
  } else {
    cout << N / 1000000 * 1000000 << endl;
  }
}
