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

  vector<pair<int,int>> vec;
  stack<int> st;
  vector<vector<int>> vec3(30, vector<int>(300005));
  rep(i,0,S.size()) {
    char now = S.at(i);
    if (now == '(') {
      st.push(i);
    } else if (now == ')') {
      int p_n = st.top();
      st.pop();
      vec.push_back(make_pair(p_n, i));
    } else { // 英小文字
      vec3.at((int)(now - 'a')).at(i)++;
    }
  }

  rep(i,0,27) {
    rep(j,1,300002) {
      vec3.at(i).at(j) += vec3.at(i).at(j-1);
    }
  }

  vector<int> vc(30);
  int idx = 0;
  string ans = "Yes";
  rep(i,0,S.size()) {
    int id = (int)(S.at(i) - 'a');
    if (S.at(i) == '(') continue;
    if (S.at(i) != ')') {
      if (vc.at(id) > 0) {
        ans = "No";
        break;
      } else {
        vc.at(id) += 1;
      }
    } else { // )の場合
      auto p = vec.at(idx);
      int l = p.first;
      int r = p.second;
      rep(j,0,26) {
        int num = vec3.at(j).at(r) - vec3.at(j).at(l);
        if (num > 0) {
          vc.at(j) = 0;
        }
      }
      idx++;
    }
  }
  cout << ans << endl;
}
