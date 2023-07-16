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
  vector<pair<int,vector<int>>> vec(N);
  rep(i,0,N) {
    int p, c;
    cin >> p >> c;
    vector<int> v(c);
    rep(j,0,c) {
      int f;
      cin >> f;
      v.at(j) = f;
    }
    vec.at(i) = make_pair(p, v);
  }
  sort(vec.begin(), vec.end());
  reverse(vec.begin(), vec.end());

  rep(i,0,N) {
    pair<int,vector<int>> v1 = vec.at(i);
    vector<int> v1fs = v1.second;
    rep(j,i+1,N) {
      pair<int,vector<int>> v2 = vec.at(j);
      vector<int> v2fs = v2.second;
      bool ov = true;
      rep(k,0,v1fs.size()) {
        int f1 = v1fs.at(k);
        bool is_in = false;
        rep(l,0,v2fs.size()) {
          if (f1 == v2fs.at(l)) is_in = true;
        }
        if (!is_in) ov = false;
      }

      if ((ov && v1.first > v2.first) || (ov && v1fs.size() < v2fs.size())) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
}
