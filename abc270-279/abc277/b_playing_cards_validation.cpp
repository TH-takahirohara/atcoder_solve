#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

bool check(char tar, vector<char> vec) {
  bool ans = false;
  rep(i,0,vec.size()) {
    if (tar == vec.at(i)) ans = true;
  }
  return ans;
}

int main() {
  int N;
  cin >> N;
  vector<string> S(N);
  rep(i,0,N) cin >> S.at(i);

  set<string> st;
  rep(i,0,N) st.insert(S.at(i));

  if (st.size() != N) {
    cout << "No" << endl;
    return 0;
  }

  bool can = true;
  rep(i,0,N) {
    char f = S.at(i).at(0);
    char s = S.at(i).at(1);
    bool flag1 = false;
    bool flag2 = false;
    if (f == 'H' || f == 'D' || f == 'C' || f == 'S') flag1 = true;
    flag2 = check(s, {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'});
    if (!flag1 || !flag2) can = false;
  }

  if (can) cout << "Yes" << endl;
  else cout << "No" << endl;
}
