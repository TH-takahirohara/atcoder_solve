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
  char p, q;
  cin >> p >> q;

  vector<int> vec(7);
  vec.at(0) = 0;
  vec.at(1) = 3;
  vec.at(2) = 4;
  vec.at(3) = 8;
  vec.at(4) = 9;
  vec.at(5) = 14;
  vec.at(6) = 23;

  int pint = int(p - 'A');
  int qint = int(q - 'A');
  cout << abs(vec.at(pint) - vec.at(qint)) << endl;
}
