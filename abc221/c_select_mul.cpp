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
  string str = to_string(N);
  sort(str.begin(), str.end());
  
  vector<char> vec;
  rep(i,0,str.size()) vec.push_back(str.at(i));
  
  int ans = 0;
  
  do {
    rep(i,1,str.size()) {
      string lef = "";
      string rig = "";
      rep(j,0,i) lef += vec.at(j);
      rep(j,i,str.size()) rig += vec.at(j);
      
      sort(lef.begin(), lef.end());
      reverse(lef.begin(), lef.end());
      sort(rig.begin(), rig.end());
      reverse(rig.begin(), rig.end());
      
      ans = max(ans, stoi(lef) * stoi(rig));
    }
  } while (next_permutation(vec.begin(), vec.end()));
  
  cout << ans << endl;
}

