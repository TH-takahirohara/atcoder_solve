// twitterで見かけた簡潔な解法
// stackに'('と英小文字を両方積み、')'が出てきたら'('が出てくるまでpopする。
// そして、popする際に出てくる英小文字を箱から削除する。
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

  stack<char> sta;
  string ans = "Yes";
  set<char> st; // 箱
  rep(i,0,S.size()) {
    if (S.at(i) == '(') {
      sta.push(S.at(i));
    } else if (S.at(i) == ')') {
      while (true) {
        char tp = sta.top();
        sta.pop();
        if (tp == '(') break;
        st.erase(tp);
      }
    } else { // 英小文字の場合
      if (st.count(S.at(i))) {
        ans = "No";
        break;
      } else {
        st.insert(S.at(i));
      }
      sta.push(S.at(i));
    }
  }
  cout << ans << endl;
}
