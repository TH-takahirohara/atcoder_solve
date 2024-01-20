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
  int taka = 0;
  int aoki = 0;

  rep(i,0,N) {
    int x,y;
    cin >> x >> y;
    taka += x;
    aoki += y;
  }

  if (taka > aoki) {
    cout << "Takahashi" << endl;
  } else if (aoki > taka) {
    cout << "Aoki" << endl;
  } else {
    cout << "Draw" << endl;
  }
}
