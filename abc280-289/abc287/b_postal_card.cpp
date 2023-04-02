#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
template<class T> bool chmin(T& a, T b) {if (a > b) {a = b; return true;} else return false;}
template<class T> bool chmax(T& a, T b) {if (a < b) {a = b; return true;} else return false;}
// 桁数指定： cout << fixed << setprecision(10)

int main() {
  int N, M;
  cin >> N >> M;
  vector<string> vec(N);
  rep(i,0,N) {
    string s;
    cin >> s;
    string ns = "";
    rep(j,3,6) {
      ns += s.at(j);
    }
    vec.at(i) = ns;
  }

  set<string> st;
  rep(i,0,M) {
    string s;
    cin >> s;
    st.insert(s);
  }

  int cnt = 0;
  rep(i,0,N) {
    if (st.count(vec.at(i))) cnt++;
  }
  cout << cnt << endl;
}
