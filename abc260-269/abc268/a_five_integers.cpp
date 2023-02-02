#include <bits/stdc++.h>
// #include <atcoder/segtree>
using namespace std;
// using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

int main() {
  vector<int> vec(101);
  rep(i,0,5) {
    int tmp; cin >> tmp;
    vec.at(tmp)++;
  }
  int cnt = 0;
  rep(i,0,101) if (vec.at(i) > 0) cnt++;
  cout << cnt << endl;
}
