#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

double calc(double x) {
  return x * x * x + x;
}

int main() {
  double N;
  cin >> N;

  double left = 0.0;
  double right = 10000.0;
  rep(i,0,50) {
    double mid = (left + right) / 2;
    if (N <= calc(mid)) right = mid;
    else left = mid;
  }
  cout << fixed << setprecision(10) << right << endl;
}
