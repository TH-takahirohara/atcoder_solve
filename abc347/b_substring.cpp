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
  string S;
  cin >> S;

  set<string> st;
  rep(i,0,S.size()) {
    string s = "";
    s += S.at(i);
    st.insert(s);
    rep(j,i+1,S.size()) {
      s += S.at(j);
      st.insert(s);
    }
  }
  cout << st.size() << endl;
}
