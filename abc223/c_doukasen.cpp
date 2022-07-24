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
  int N;
  cin >> N;
  
  vector<int> A(N), B(N);
  rep(i,0,N) cin >> A.at(i) >> B.at(i);
  
  double alltime = 0.0;
  rep(i,0,N) alltime += (double)A.at(i) / B.at(i);
  
  double time = alltime / 2;
  
  double dist = 0.0;
  rep(i,0,N) {
    double kyori = (double)A.at(i);
    double hayasa = (double)B.at(i);
    if (time < kyori / hayasa) {
      dist += hayasa * time;
      break;
    } else {
      dist += kyori;
      time -= kyori / hayasa;
    }
  }
  cout << fixed << setprecision(10) << dist << endl;
}

