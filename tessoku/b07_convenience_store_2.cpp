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
  int T, N;
  cin >> T >> N;
  vector<int> rui(T+1);
  rep(i,0,N) {
    int l, r;
    cin >> l >> r;
    rui.at(l)++;
    rui.at(r)--;
  }

  rep(i,0,T) rui.at(i+1) += rui.at(i);
  rep(i,0,T) {
    cout << rui.at(i) << endl;
  }
}
