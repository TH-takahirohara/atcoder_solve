// 最初、コンテスト後に追加されたテストケース以外は通っていた。
// それが通らず、テストケースを見た。
// 条件3で2回動くケースについての考慮が漏れていたので、それに対応する処理（27-29行）を追加しAC。
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
  ll r1,c1,r2,c2;
  cin >> r1 >> c1 >> r2 >> c2;

  if (abs(r1 - r2) + abs(c1 - c2) == 0) {
    cout << 0 << endl;
    return 0;
  } else if (abs(r1 - r2) + abs(c1 - c2) <= 3) {
    cout << 1 << endl;
    return 0;
  } else if ((r1+c1 == r2+c2) || (r1-c1 == r2 - c2)) {
    cout << 1 << endl;
    return 0;
  } else if (abs(r1 - r2) + abs(c1 - c2) <= 6) {
    cout << 2 << endl;
    return 0;
  }

  if ((abs(r1 - r2) + abs(c1 - c2)) % 2 == 0) {
    cout << 2 << endl;
  } else {
    if (abs(abs(r1 - r2) - abs(c1 - c2)) <= 3) {
      cout << 2 << endl;
    } else {
      cout << 3 << endl;
    }
  }
}
