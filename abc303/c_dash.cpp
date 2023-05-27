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
  int N, M, H, K;
  string S;
  cin >> N >> M >> H >> K >> S;
  // vector<int> X(M), Y(M);
  // rep(i,0,M) cin >> X.at(i) >> Y.at(i);
  set<pair<int,int>> st;
  rep(i,0,M) {
    int x,y;
    cin >> x >> y;
    st.insert(make_pair(x,y));
  }

  string ans = "Yes";
  int x = 0, y = 0;
  rep(i,0,N) {
    H--;
    if (H < 0) {
      ans = "No";
      break;
    }

    char s = S.at(i);
    if (s == 'R') x++;
    else if (s == 'L') x--;
    else if (s == 'U') y++;
    else y--;

    if (H < K && st.count(make_pair(x,y))) {
      st.erase(make_pair(x,y));
      H = K;
    }
  }
  cout << ans << endl;
}
