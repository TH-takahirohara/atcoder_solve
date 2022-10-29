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

  vector<int> rui(x.size()+1);
  rep(i,0,x.size()) {
    rui.at(i + 1) = rui.at(i) + (int)(x.at(i) - '0');
  }

  vector<int> vec(1000000);
  rep(i,0,x.size()) {
    vec.at(i) = rui.at(x.size() - i);
  }

  rep(i,0,x.size()) {
    int v = vec.at(i);
    vec.at(i+1) += v / 10;
    vec.at(i) = v % 10;
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
