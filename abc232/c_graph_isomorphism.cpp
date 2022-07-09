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
  
  map<int,vector<int>> mp;
  map<int,set<int>> mp2;
  rep(i,0,M) {
    int a,b;
    cin >> a >> b;
    a--;b--;
    mp[a].push_back(b);
    mp[b].push_back(a);
  }
    
  rep(i,0,M) {
    int c,d;
    cin >> c >> d;
    c--;d--;
    mp2[c].insert(d);
    mp2[d].insert(c);
  }
  
  vector<int> vec(N);
  rep(i,0,N) vec.at(i) = i;
  
  string ans = "No";
  do {
    bool can = true;
    rep(i,0,N) {
      if (mp[i].size() == 0) continue;
      for (auto v : mp[i]) {
        if (!mp2[vec.at(i)].count(vec.at(v))) can = false;
      }
    }
    if (can) ans = "Yes";
  } while(next_permutation(vec.begin(), vec.end()));
  
  cout << ans << endl;
}

