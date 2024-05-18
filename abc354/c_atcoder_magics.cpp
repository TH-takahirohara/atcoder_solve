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
  vector<pair<int,pair<int,int>>> vec(N); // a, c, i
  set<int> st;
  map<int,int> mp; // コスト -> 同じコストの個数
  rep(i,0,N) {
    int a, c;
    cin >> a >> c;
    vec.at(i) = make_pair(a,make_pair(c,i+1));
    st.insert(c);
    mp[c] += 1;
  }

  sort(vec.begin(), vec.end());

  vector<int> anses;
  rep(i,0,N) {
    auto v = vec.at(i);
    auto p2 = v.second;
    int c = p2.first;
    int ite = p2.second;

    if (i == N-1) {
      anses.push_back(ite);
      break;
    }

    mp.at(c) -= 1;
    if (mp.at(c) == 0) {
      st.erase(c);
    }
    int saishou = *begin(st);
    if (saishou < c) {
      continue;
    } else {
      anses.push_back(ite);
    }
  }

  sort(anses.begin(), anses.end());

  cout << anses.size() << endl;
  rep(i,0,anses.size()) {
    cout << anses.at(i) << " ";
  }
  cout << endl;
}
