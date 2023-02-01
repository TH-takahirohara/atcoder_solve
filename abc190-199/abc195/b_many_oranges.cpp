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
  int A,B,W;
  cin >> A >> B >> W;
  W *= 1000;

  int min_n = 2e9, max_n = 0;
  int num_a = 0, num_b = 0;
  int cnt = 0;
  bool flag = false;
  while (true) {
    cnt++;
    num_a += A;
    num_b += B;
    if (num_a <= W && W <= num_b) {
      min_n = min(min_n, cnt);
      max_n = max(max_n, cnt);
      flag = true;
    }
    if (num_a > W) break;
  }
  if (!flag) cout << "UNSATISFIABLE" << endl;
  else cout << min_n << " " << max_n << endl;
}
