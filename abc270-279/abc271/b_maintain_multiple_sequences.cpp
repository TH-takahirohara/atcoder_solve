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
  int N, Q;
  cin >> N >> Q;
  vector<vector<int>> vec(N);

  rep(i,0,N) {
    int l;
    cin >> l;
    rep(j,0,l) {
      int a;
      cin >> a;
      vec.at(i).push_back(a);
    }
  }

  rep(i,0,Q) {
    int s, t;
    cin >> s >> t;
    s--; t--;
    cout << vec.at(s).at(t) << endl;
  }
}
