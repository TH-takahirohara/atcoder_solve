// 1回の操作で幸福である人数は最大2人増やせる。それは、操作後に操作した端部の人の方向が変わることで幸せになるケース。
// LR, RLかRL, LRの組があればそれぞれを端部として入れ替えれば良い気がするが、入れ替えによって操作する内側のLR, RLが
// 全て入れ替えになるのをうまく解消する実装が思いつかなかった。
// -> 解説を見ると、LR, RLの組はそれぞれ交互にしか存在し得ないことに着目して解いていた。その方法を踏襲してACした。
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
  int N,K;
  cin >> N >> K;
  string S;
  cin >> S;

  int num_happy = 0;
  rep(i,0,N) {
    if (i == 0 && S.at(i) == 'L' || i == N-1 && S.at(i) == 'R') continue;
    if (S.at(i) == 'L' && S.at(i-1) == 'L' || S.at(i) == 'R' && S.at(i+1) == 'R') num_happy++;
  }

  int num_l_r = 0, num_r_l = 0;
  rep(i,0,N-1) {
    if (S.at(i) == 'L' && S.at(i+1) == 'R') num_l_r++;
    if (S.at(i) == 'R' && S.at(i+1) == 'L') num_r_l++;
  }

  if (num_l_r == num_r_l) {
    cout << num_happy + 2 * min(num_l_r, K) << endl;
  } else {
    int min_num = min(num_l_r, num_r_l);
    int max_num = max(num_l_r, num_r_l);
    if (K <= min_num) {
      cout << num_happy + 2 * K << endl;
    } else {
      cout << num_happy + 2 * min_num + 1 << endl;
    }
  }
}
