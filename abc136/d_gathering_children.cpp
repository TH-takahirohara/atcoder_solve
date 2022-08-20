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
  string S;
  cin >> S;

  vector<pair<char,int>> vec;
  vec.emplace_back('R',1);
  rep(i,1,S.size()) {
    if (S.at(i) == vec.back().first) {
      vec.back().second++;
    } else {
      vec.emplace_back(S.at(i), 1);
    }
  }

  vector<int> arr;
  rep(i,0,vec.size()/2) {
    int rcnt = vec.at(2*i).second;
    int lcnt = vec.at(2*i+1).second;
    if ((rcnt + lcnt) % 2 == 0) {
      rep(j,0,rcnt-1) arr.push_back(0);
      arr.push_back((rcnt+lcnt)/2);
      arr.push_back((rcnt+lcnt)/2);
      rep(j,0,lcnt-1) arr.push_back(0);
    } else {
      int r, l;
      if (rcnt % 2 == 0) {
        r = (rcnt+lcnt)/2;
        l = (rcnt+lcnt)/2 + 1;
      } else {
        l = (rcnt+lcnt)/2;
        r = (rcnt+lcnt)/2 + 1;
      }
      rep(j,0,rcnt-1) arr.push_back(0);
      arr.push_back(r);
      arr.push_back(l);
      rep(j,0,lcnt-1) arr.push_back(0);
    }
  }
  rep(i,0,arr.size()) {
    cout << arr.at(i) << " ";
  }
}
