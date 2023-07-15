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
  int N;
  cin >> N;
  set<string> st;
  rep(i,0,N) {
    string s;
    cin >> s;
    st.insert(s);
    reverse(s.begin(), s.end());
    st.insert(s);
  }

  int ans = 0;
  while (!st.empty()) {
    string s = *begin(st);
    st.erase(s);
    reverse(s.begin(), s.end());
    if (st.count(s)) {
      st.erase(s);
    }
    ans++;
  }
  cout << ans << endl;
}
