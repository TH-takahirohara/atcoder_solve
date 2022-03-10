#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

int N;
vector<int> X, Y;
vector<int> P;

double kyori(int x1, int y1, int x2, int y2) {
  return sqrt((x1-x2) * (x1-x2) + (y1-y2) * (y1-y2));
}

int main() {
  cin >> N;
  X.assign(N, 0); Y.assign(N, 0);
  rep(i, 0, N) {
    cin >> X.at(i) >> Y.at(i);
  }
  
  // 順列全探索用配列
  rep(i, 0, N) {
    P.push_back(i);
  }
    
  double sum = 0;
  int cnt = 0;
  // 順列全探索
  do {
    double tmp_sum = 0;
    rep(i, 1, N) {
      tmp_sum += kyori(X.at(P.at(i)), Y.at(P.at(i)), X.at(P.at(i-1)), Y.at(P.at(i-1)));
    }
    sum += tmp_sum;
    cnt++;
  } while(next_permutation(P.begin(), P.end()));
  
  double ans = sum / cnt;
  
  cout << fixed << setprecision(8) << ans << endl;
}
