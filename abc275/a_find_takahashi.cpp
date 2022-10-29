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
  int N;
  cin >> N;
  vector<int> vec(N);
  rep(i,0,N) cin >> vec.at(i);

  int tmp = 0;
  int idx = -1;
  rep(i,0,N) {
    if (vec.at(i) > tmp) {
      tmp = vec.at(i);
      idx = i;
    }
  }

  cout << idx + 1 << endl;
}
