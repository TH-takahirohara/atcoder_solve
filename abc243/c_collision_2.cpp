#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

int main() {
  ll N;
  cin >> N;
  
  vector<ll> X(N);
  vector<ll> Y(N);
  
  rep(i,0,N) {
    cin >> X.at(i) >> Y.at(i);
  }
  
  string S;
  cin >> S;
  
  bool ans = false;
  
  map<ll, pair<ll, ll>> col_map;
  
  rep(i,0,N) {
    if (!col_map.count(Y.at(i))) {
      if (S.at(i) == 'R') col_map[Y.at(i)] = make_pair(X.at(i), -1);
      if (S.at(i) == 'L') col_map[Y.at(i)] = make_pair(1000001000, X.at(i));
    } else {
      if (S.at(i) == 'R') col_map.at(Y.at(i)).first = min(col_map.at(Y.at(i)).first, X.at(i));
      if (S.at(i) == 'L') col_map.at(Y.at(i)).second = max(col_map.at(Y.at(i)).second, X.at(i));
      if (col_map.at(Y.at(i)).first < col_map.at(Y.at(i)).second) {
        ans = true;
        break;
      }
    }
  }
  
  if (ans) cout << "Yes" << endl;
  else cout << "No" << endl;
}
