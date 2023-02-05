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
  vector<int> A(N);
  rep(i,0,N) cin >> A.at(i);

  set<int> st;
  rep(i,0,N) st.insert(A.at(i));

  map<int,int> mp;
  rep(i,0,N) {
    mp[A.at(i)]++;
  }

  vector<int> ans(N);
  int sz = st.size();
  rep(i,0,sz) {
    int tar = *begin(st);
    st.erase(tar);
    if (mp.count(tar)) ans.at(sz-i-1) = mp.at(tar);
    else ans.at(sz-i-1) = 0;
  }

  rep(i,0,N) {
    cout << ans.at(i) << endl;
  }
}
