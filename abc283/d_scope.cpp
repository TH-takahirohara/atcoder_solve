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
  // map<char,vector<int>> mp;
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
      // if (!mp.count(now)) {
      //   mp[now] = {i};
      // } else {
      //   mp.at(now).push_back(i);
      // }
    }
  }

  // vector<vector<int>> vec3(30, vector<int>(300005));
  rep(i,0,27) {
    rep(j,1,300002) {
      vec3.at(i).at(j) += vec3.at(i).at(j-1);
    }
  }
  // for (auto p : mp) {
  //   auto key = p.first;
  //   // cout << key << endl;
  //   auto ve = p.second;
  //   rep(i,0,ve.size()) {
  //     vec3.at((int)(key - 'a')).at(ve.at(i))++;
  //   }
  //   rep(i,1,300002) {
  //     vec3.at((int)(key - 'a')).at(i) += vec3.at((int)(key - 'a')).at(i-1);
  //   }
  // }

  // set<char> stc; // 箱
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
      // for (auto pa : mp) {
      //   auto key = pa.first;
      //   auto ve = pa.second;
      //   int num = vec3.at((int)(key - 'a')).at(r) - vec3.at((int)(key - 'a')).at(l);
      //   if (num > 0) { // ()内にkeyの文字がある場合、箱から削除する
      //     vc.at(key - 'a') = 0;
      //   }
      // }
      idx++;
    }
  }
  cout << ans << endl;
}
