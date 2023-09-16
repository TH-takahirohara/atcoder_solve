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
  int M;
  cin >> M;
  vector<string> S(3);
  rep(i,0,3) {
    cin >> S.at(i);
  } 
  vector<vector<int>> vec(10, vector<int>(M));
  rep(i,0,3) {
    rep(j,0,M) {
      int n = (int)(S.at(i).at(j) - '0');
      vec.at(n).at(j)++;
    }
  }

  bool can = false;
  vector<int> nums;
  vector<vector<bool>> ch(3, vector<bool>(10));
  rep(i,0,3) {
    rep(j,0,M) {
      int n = (int)(S.at(i).at(j) - '0');
      ch.at(i).at(n) = true;
    }
  }
  rep(j,0,10) {
    if (ch.at(0).at(j) && ch.at(1).at(j) && ch.at(2).at(j)) {
      can = true;
      nums.push_back(j);
    }
  }
  if (!can) {
    cout << -1 << endl;
    return 0;
  }

  int ans = 10000000;
  rep(i,0,nums.size()) {
    int tar = nums.at(i);
    vector<int> narabi = {0,1,2};
    do {
      int t = 0;
      while (true) {
        if ((int)(S.at(narabi.at(0)).at(t % M) - '0') == tar) break;
        t++;
      }
      t++;
      while (true) {
        if ((int)(S.at(narabi.at(1)).at(t % M) - '0') == tar) break;
        t++;
      }
      t++;
      while (true) {
        if ((int)(S.at(narabi.at(2)).at(t % M) - '0') == tar) break;
        t++;
      }
      ans = min(ans, t);
    } while (next_permutation(narabi.begin(), narabi.end()));
  }
  
  cout << ans << endl;
}
