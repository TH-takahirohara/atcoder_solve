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
  int x,y;
  cin >> x >> y;
  if (y > x) {
    if (y-x<=2) cout << "Yes";
    else cout << "No";
    // cout << (y - x <= 2) ? "Yes" : "No" << endl;
  } else {
    if (x-y<=3) cout << "Yes";
    else cout << "No";
    
    // cout << (x - y <= 3) ? "Yes" : "No" << endl;
  }
  cout << endl;
}
