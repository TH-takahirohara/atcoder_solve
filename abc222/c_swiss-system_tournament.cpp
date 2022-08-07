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
  int N,M;
  cin >> N >> M;
  vector<string> S(N*2);
  rep(i,0,2*N) cin >> S.at(i);
  
  vector<pair<int,int>> vec(2*N);
  rep(i,0,2*N) {
    vec.at(i) = make_pair(0, i);
  }
  
  rep(i,0,M) {
    rep(j,0,N) {
      auto one = &vec.at(2*j);
      auto two = &vec.at(2*j+1);
      char te1 = S.at(one->second).at(i);
      char te2 = S.at(two->second).at(i);
      if (te1 == 'G') {
        if (te2 == 'C') one->first--;
        else if (te2 == 'P') two->first--;
      } else if (te1 == 'C') {
        if (te2 == 'G') two->first--;
        else if (te2 == 'P') one->first--;
      } else if (te1 == 'P') {
        if (te2 == 'G') one->first--;
        else if (te2 == 'C') two->first--;
      }
    }
    sort(vec.begin(), vec.end());
  }
  
  rep(i,0,2*N) cout << vec.at(i).second + 1 << endl;
}

