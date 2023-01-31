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
  int N, M;
  cin >> N >> M;
  // map<int,pair<bool,int>> mp;
  vector<bool> isAc(N);
  vector<int> was(N);

  int ac = 0, wa = 0;
  rep(i,0,M) {
    int p;
    string s;
    cin >> p >> s;
    p--;

    if (isAc.at(p)) continue; // すでに正解している場合は次へ
    // ↓ まだ当該問題に正解していない場合
    if (s == "AC") { // 正解した場合
      ac++;
      wa += was.at(p);
      isAc.at(p) = true;
    } else { // 不正解だった場合
      was.at(p)++;
    }
  }

  cout << ac << " " << wa << endl;
}
