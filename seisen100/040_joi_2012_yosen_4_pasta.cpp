#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

int main() {
  int N,K;
  cin >> N >> K;

  map<int,int> days;
  rep(i,0,K) {
    int d,p;
    cin >> d >> p;
    d--;p--;
    days[d] = p;
  }

  vector<vector<vector<int>>> dp(N, vector<vector<int>>(3, vector<int>(3, 0)));

  if (days.count(0) && days.count(1)) {
    dp.at(1).at(days.at(0)).at(days.at(1)) = 1;
  } else if (days.count(0)) {
    rep(i,0,3) dp.at(1).at(days.at(0)).at(i) = 1;
  } else if (days.count(1)) {
    rep(i,0,3) dp.at(1).at(i).at(days.at(1)) = 1;
  } else {
    rep(i,0,3) rep(j,0,3) dp.at(1).at(i).at(j) = 1;
  }

  rep(day,2,N) {
    if (days.count(day)) {
      rep(i,0,3) {
        rep(j,0,3) {
          if (i==days.at(day) && j==days.at(day)) continue;
          dp.at(day).at(j).at(days.at(day)) += dp.at(day-1).at(i).at(j);
          dp.at(day).at(j).at(days.at(day)) %= 10000;
        }
      }
    } else {
      rep(i,0,3) {
        rep(j,0,3) {
          if (i==j) {
            dp.at(day).at(j).at((j+1) % 3) += dp.at(day-1).at(i).at(j);
            dp.at(day).at(j).at((j+1) % 3) %= 10000;
            dp.at(day).at(j).at((j+2) % 3) += dp.at(day-1).at(i).at(j);
            dp.at(day).at(j).at((j+2) % 3) %= 10000;
          } else {
            dp.at(day).at(j).at(0) += dp.at(day-1).at(i).at(j);
            dp.at(day).at(j).at(0) %= 10000;
            dp.at(day).at(j).at(1) += dp.at(day-1).at(i).at(j);
            dp.at(day).at(j).at(1) %= 10000;
            dp.at(day).at(j).at(2) += dp.at(day-1).at(i).at(j);
            dp.at(day).at(j).at(2) %= 10000;
          }
        }
      }
    }
  }

  int sum = 0;
  rep(i,0,3) {
    rep(j,0,3) {
      sum += dp.at(N-1).at(i).at(j);
      sum %= 10000;
    }
  }

  cout << sum << endl;
}
