#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

typedef vector<vector<int>> Graph;
double PI = 3.14159265359;

int main() {
  int N,x0,y0,xn2,yn2;
  cin >> N >> x0 >> y0 >> xn2 >> yn2;
  
  double theta = (2*PI)/N;
  
  double cenx = (double)(x0+xn2)/2;
  double ceny = (double)(y0+yn2)/2;
  
  double shiftx0 = x0 - cenx;
  double shifty0 = y0 - ceny;
  
  double x1tmp = shiftx0 * cos(theta) - shifty0 * sin(theta);
  double y1tmp = shiftx0 * sin(theta) + shifty0 * cos(theta);
  
  cout << fixed << setprecision(10) << x1tmp + cenx << " " << y1tmp + ceny << endl;
}

