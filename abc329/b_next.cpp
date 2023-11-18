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
  set<int> st;
  rep(i,0,N) {
    int a;
    cin >> a;
    st.insert(a);
  }

  int ma = *rbegin(st);
  st.erase(ma);

  cout << *rbegin(st) << endl;
}
