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
  int N;
  cin >> N;
  vector<string> S(N);
  rep(i,0,N) cin >> S.at(i);

  vector<pair<int,int>> vec;
  rep(i,0,N) {
    int win = 0;
    rep(j,0,N) {
      if (j==i) continue;
      if (S.at(i).at(j) == 'o') win++;
    }
    vec.push_back(make_pair(win, -(i+1)));
  }

  sort(vec.begin(), vec.end());
  reverse(vec.begin(), vec.end());

  rep(i,0,vec.size()) {
    cout << -(vec.at(i).second) << " ";
  }
  cout << endl;
}
