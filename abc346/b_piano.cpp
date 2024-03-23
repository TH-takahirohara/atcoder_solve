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
  int W, B;
  cin >> W >> B;

  string sp = "wbwbwwbwbwbw";
  int sz = sp.size();
  rep(st,0,sp.size()) {
    // cout << "st: " << st << endl;
    int cnt_w = 0;
    int cnt_b = 0;
    int start = st;
    while (cnt_w <= W && cnt_b <= B) {
      // cout << start << " ";
      if (sp.at(start % sz) == 'w') {
        cnt_w++;
      } else {
        cnt_b++;
      }
      if (cnt_w == W && cnt_b == B) {
        cout << "Yes" << endl;
        return 0;
      } else {
        start++;
      }
    }
    // cout << endl;
  }
  cout << "No" << endl;
}
