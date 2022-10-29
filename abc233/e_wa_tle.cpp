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
  string x;
  cin >> x;

  reverse(x.begin(), x.end());
  vector<int> vec(1000000);
  rep(i,0,x.size()) {
    vec.at(i) = (int)(x.at(i) - '0');
  }

  rep(i,1,x.size()) {
    rep(j,i,x.size()+1) {
      int pl = 0;
      if (j >= 0 && j < x.size()) pl = (int)(x.at(j) - '0');
      vec.at(j-i) += pl;
      if (vec.at(j-i) > 9)  {
        vec.at(j-i+1)++;
        vec.at(j-i) -= 10;
      }
    }
  }

  string ans = "";
  bool flag = false;
  rep(i,0,1000000) {
    if (vec.at(1000000-i-1) == 0 && !flag) continue;
    flag = true;
    ans += (char)(vec.at(1000000-i-1) + '0');
  }
  cout << ans << endl;
}
