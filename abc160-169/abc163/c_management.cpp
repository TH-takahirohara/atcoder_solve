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
  vector<int> A(N-1);
  rep(i,0,N-1) cin >> A.at(i);

  vector<int> vec(N);
  rep(i,0,N-1) {
    vec.at(A.at(i) - 1)++;
  }
  rep(i,0,N) {
    cout << vec.at(i) << endl;
  }
}
