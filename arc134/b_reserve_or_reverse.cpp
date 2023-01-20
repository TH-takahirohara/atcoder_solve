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

vector<stack<int>> vec(26);

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;

  rep(i,0,N) {
    int tar = (int)(S.at(i) - 'a');
    vec.at(tar).push(i);
  }

  int back = N;
  rep(ite,0,N) {
    if (ite >= back) break;
    int now = (int)(S.at(ite) - 'a');

    int tmp = now;
    int nx = 1000000;
    for (int i=now-1; i >= 0; i--) {
      if (vec.at(i).size() == 0) continue;
      int top = vec.at(i).top(); // 当該アルファベットが最後に出てくるindex
      if (top > ite && top < back) {
        tmp = i;
        nx = top;
      }
    }

    if (tmp < now) {
      swap(S.at(ite), S.at(nx));
      back = nx;
      for (int i=0; i<=25; i++) {
        while (true) {
          if (vec.at(i).size() == 0) break;
          if (vec.at(i).top() >= nx) {
            vec.at(i).pop();
          } else {
            break;
          }
        }
      }
    } else {
      continue;
    }
  }
  cout << S << endl;
}
