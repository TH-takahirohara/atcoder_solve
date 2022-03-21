#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

int INF = 100000000;

int main() {
  vector<int> tetra(181);
  rep(i,1,181) {
    tetra.at(i) = i*(i+1)*(i+2)/6;
  }
  
  while (true) {
    int num;
    cin >> num;
    if (num==0) break;
    
    vector<int> dp(num+1, INF);
    vector<int> dp2(num+1, INF);
    dp.at(0) = 0; dp.at(1) = 1;
    dp2.at(0) = 0; dp2.at(1) = 1;
    
    rep(i,0,num+1) {
      for (int j=2; tetra.at(j) <= i; j++) {
        
        if (i-tetra.at(j) >= 0) {
          dp.at(i) = min(dp.at(i), dp.at(i-tetra.at(j))+1);
          if (tetra.at(j) % 2 == 1) {
            dp2.at(i) = min(dp2.at(i), dp2.at(i-tetra.at(j))+1);
          }
        }
      }
    }
    
    cout << dp.at(num) << " " << dp2.at(num) << endl;
  }
  return 0;
}
