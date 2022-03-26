#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

int main() {
  ll N,K;
  cin >> N >> K;
  vector<ll> A(N,0), B(N,0);
  rep(i,0,N) cin >> A.at(i);
  rep(i,0,N) cin >> B.at(i);
  
  bool ans = true;
  vector<ll> tmp = {};
  tmp.push_back(A.at(0));
  tmp.push_back(B.at(0));
  
  rep(i,1,N) {
    set<ll> now_s;
    
    rep(j,0,tmp.size()) {
      if (abs(A.at(i) - tmp.at(j)) <= K) now_s.insert(A.at(i));
      if (abs(B.at(i) - tmp.at(j)) <= K) now_s.insert(B.at(i));
    }
    
    tmp = {};
    while (!now_s.empty()) {
      ll now_num = *begin(now_s);
      now_s.erase(now_num);
      tmp.push_back(now_num);
    }
    
    if (tmp.size() == 0) {
      ans = false;
      break;
    }
  }
  
  if (ans) cout << "Yes" << endl;
  else cout << "No" << endl;
}
