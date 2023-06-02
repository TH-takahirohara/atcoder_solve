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
  vector<string> vec(N);
  set<string> st;
  rep(i,0,N) {
    string s;
    cin >> s;
    
    vec.at(i) = s;
    st.insert(s);
  }

  rep(i,0,N) {
    string s = vec.at(i);
    if (s.at(0) == '!') continue;
    if (st.count('!' + s)) {
      cout << s << endl;
      return 0;
    }
  }
  cout << "satisfiable" << endl;
}
