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

  stack<string> st;
  int i = 0;
  while (i < S.size()) {
    char c = S.at(i);

    if (st.empty()) {
      string s = "";
      s += c;
      st.push(s);
    } else {
      string tp = st.top();
      if (tp == "A" && c == 'B') {
        st.pop();
        st.push("AB");
      } else if (tp == "AB" && c == 'C') {
        st.pop();
      } else {
        string s = "";
        s += c;
        st.push(s);
      }
    }

    i++;
  }

  string ans = "";
  while (!st.empty()) {
    string tp = st.top();
    st.pop();
    ans = tp + ans;
  }
  cout << ans << endl;
}
