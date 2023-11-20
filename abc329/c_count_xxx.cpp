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
  string S;
  cin >> S;

  int num = -1;
  char tmp_c;
  set<pair<char,int>> st;
  rep(i,0,N) {
    if (i == 0) {
      tmp_c = S.at(i);
      num = 1;
      st.insert(make_pair(tmp_c, num));
    } else {
      if (S.at(i) != tmp_c) {
        tmp_c = S.at(i);
        num = 1;
        st.insert(make_pair(tmp_c, num));
      } else {
        num++;
        st.insert(make_pair(tmp_c, num));
      }
    }
  }

  cout << st.size() << endl;
}
