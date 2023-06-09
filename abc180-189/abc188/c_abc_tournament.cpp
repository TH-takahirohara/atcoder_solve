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
  int ninzuu = 1;
  rep(i,0,N) ninzuu *= 2;
  vector<pair<int,int>> A(ninzuu);
  rep(i,0,ninzuu) {
    int a;
    cin >> a;
    A.at(i) = make_pair(a,i+1);
  }

  vector<pair<int,int>> vec = {};
  rep(i,0,N-1) {
    rep(j,0,ninzuu/2) {
      if (A.at(2*j).first < A.at(2*j+1).first) vec.push_back(A.at(2*j+1));
      else vec.push_back(A.at(2*j));
    }
    A = vec;
    vec = {};
    ninzuu /= 2;
  }

  if (A.at(0).first < A.at(1).first) cout << A.at(0).second << endl;
  else cout << A.at(1).second << endl;
}
