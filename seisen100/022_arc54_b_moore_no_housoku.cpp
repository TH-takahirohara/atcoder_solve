#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

double P;

double keisan(double x) {
  return x + P / (pow(2, x/1.5));
}

int main() {
  cin >> P;
  
  double left = 0.0;
  double right = 100;
  
  rep(i, 0, 1000) {
    double c1 = (left + left + right) / 3.0;
    double c2 = (left + right + right) / 3.0;
    
    if (keisan(c1) <= keisan(c2)) right = c2;
    else left = c1;
  }
  
  cout << fixed << setprecision(10) << keisan(right) << endl;
}

