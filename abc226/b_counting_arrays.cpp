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
  
  map<int, set<vector<int>>> mp;
  
  rep(iter,0,N) {
    int l;
    cin >> l;
    vector<int> vec(l);
    rep(i,0,l) {
      cin >> vec.at(i);
    }
    
    mp[l].insert(vec);
  }
  
  vector<int> keys;
  for (auto it = mp.begin(); it != mp.end(); it++) {
    keys.push_back(it->first);
  }
  
  int ans = 0;
  for (auto key : keys) {
    ans += mp[key].size();
  }
  cout << ans << endl;
}

