#include <bits/stdc++.h>
// #include <atcoder/segtree>
using namespace std;
// using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

int main() {
  int N,M;
  cin >> N >> M;
  
  vector<int> A(N);
  rep(i,0,N) cin >> A.at(i);
  
  set<int> st;
  
  rep(i,0,N) {
    int x = A.at(i);
    for (int j=1; j*j<=x; j++) {
      if (x % j == 0) {
        st.insert(j);
        st.insert(x / j);
      }
    }
  }
  
  vector<int> vec;
  vec.push_back(1);
  
  rep(i,2,M+1) {
    bool can = true;
    for (int j=2; j*j<=i; j++) {
      if (i % j == 0 && (st.count(j) || st.count(i/j))) can = false;
    }
    if (st.count(i)) can = false;
    
    if (can) vec.push_back(i);
  }
  
  cout << vec.size() << endl;
  rep(i,0,vec.size()) cout << vec.at(i) << endl;
}
