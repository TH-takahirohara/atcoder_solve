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
  vector<int> A(N);
  rep(i,0,N) cin >> A.at(i);

  set<int> st;
  map<int,int> mp;
  rep(i,0,1500001) st.insert(i);

  rep(i,0,M) {
    if (st.count(A.at(i))) st.erase(A.at(i));
    mp[A.at(i)]++;
  }

  int ans = *begin(st);
  rep(i,0,N-M) {
    mp.at(A.at(i))--;
    if (mp.at(A.at(i)) == 0) st.insert(A.at(i));
    mp[A.at(i+M)]++;
    if (st.count(A.at(i+M))) st.erase(A.at(i+M));
    ans = min(ans, *begin(st));
  }

  cout << ans << endl;
}
