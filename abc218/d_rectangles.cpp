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
  int N;
  cin >> N;
  
  vector<pair<int,int>> vec(N);
  set<pair<int,int>> st;
  set<vector<pair<int,int>>> ans_st;

  rep(i,0,N) {
    cin >> vec.at(i).first >> vec.at(i).second;
    st.insert(vec.at(i));
  }
  
  rep(i,0,N) {
    rep(j,0,N) {
      if (i==j) continue;
      auto p1 = vec.at(i);
      auto p2 = vec.at(j);
      
      if (p1.first == p2.first || p1.second == p2.second) continue;
      if (st.count(make_pair(p1.first, p2.second)) && st.count(make_pair(p2.first, p1.second))) {
        vector<pair<int,int>> ve = {p1, p2, make_pair(p1.first, p2.second), make_pair(p2.first, p1.second)};
        sort(ve.begin(), ve.end());
        ans_st.insert(ve);
      }
    }
  }
  
  cout << ans_st.size() << endl;
}

