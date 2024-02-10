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
  int a,b,d;
  cin >> a >> b >> d;

  int now = a;
  while (now <= b) {
    cout << now << " ";
    now += d;
  }
  cout << endl;
}
