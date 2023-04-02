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

  map<string,int> mp_irijisuu;
  map<string,string> mp;
  set<string> st;
  rep(i,0,N) {
    string s, t;
    cin >> s >> t;
    st.insert(s);
    st.insert(t);

    if (!mp_irijisuu.count(s)) {
      mp_irijisuu[s] = 0;
    }
    
    if (!mp_irijisuu.count(t)) {
      mp_irijisuu[t] = 1;
    } else {
      mp_irijisuu.at(t)++;
    }
    mp[s] = t;
  }

  queue<string> que;
  for (auto p : mp_irijisuu) {
    auto key = p.first;
    auto v = p.second;
    if (v==0) {
      que.push(key);
    }
  }

  vector<string> vec;
  while (!que.empty()) {
    string now = que.front();
    vec.push_back(now);
    que.pop();
    if (mp.count(now)) {
      string nx = mp.at(now);
      mp_irijisuu.at(nx)--;
      if (mp_irijisuu.at(nx) == 0) {
        que.push(nx);
      }
    }
  }

  if (vec.size() == st.size()) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
