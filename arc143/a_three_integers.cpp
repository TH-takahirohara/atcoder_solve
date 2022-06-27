// 全ての数を等しい値にできればOK。そのためには、2つの数を1減らすという操作の回数をxとした時、
// (2番目に大きい値と最小値の差) + 2x = (最大値と最小値の差) + x が成り立つ0以上のxが存在すれば良い。
// (できる等しい値をyとした時、最大値をyにするまでの操作回数と、最小値および2番目の数をyにするまでの操作回数の和が等しければ良いため)
// つまり、(最大値と最小値の差) - (2番目に大きい値と最小値の差) が、最小値以上であればOK
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
  ll a,b,c;
  cin >> a >> b >> c;
  
  vector<ll> vec = {a, b, c};
  
  sort(vec.begin(), vec.end());
  
  ll narasi = (vec.at(2) - vec.at(0)) - (vec.at(1) - vec.at(0));
  
  if (narasi < 0) {
    cout << -1 << endl;
  } else if (narasi > vec.at(0)) {
    cout << -1 << endl;
  } else {
    cout << vec.at(2) << endl;
  }
  return 0;
}

