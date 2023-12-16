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

  vector<ll> vec;
  ll num = 0;
  for (int i=0; i<12; i++) {
    num = num * 10 + 1;
    vec.push_back(num);
  }

  set<ll> st;
  int sz = vec.size();
  for (int i=0; i<sz; i++) {
    for (int j=0; j<sz; j++) {
      for (int k=0; k<sz; k++) {
        ll tmp = vec.at(i) + vec.at(j) + vec.at(k);
        st.insert(tmp);
      }
    }
  }

  rep(i,0,N-1) {
    ll n = *begin(st);
    st.erase(n);
  }

  cout << *begin(st) << endl;
}
