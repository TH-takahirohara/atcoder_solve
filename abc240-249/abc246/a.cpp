#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

int main() {
  vector<int> x(3);
  vector<int> y(3);
  int x1, y1;
  int x2, y2;
  int x3, y3;
  
  rep(i,0,3) {
    cin >> x.at(i);
    cin >> y.at(i);
  }
  
  int leftx = -100000; int rightx = 1000000;
  int topy = 100000; int downy = -100000;
  
  map<int,int> mx, my;
  
  rep(i,0,3) {
    if (mx.count(x.at(i))) {
      mx.at(x.at(i))++;
    } else {
      mx[x.at(i)] = 1;
      if (leftx == -100000) leftx = x.at(i);
      else rightx = x.at(i);
    }
    
    if (my.count(y.at(i))) {
      my.at(y.at(i))++;
    } else {
      my[y.at(i)] = 1;
      if (topy == 100000) topy = y.at(i);
      else downy = y.at(i);
    }
  }
  
  if (mx.at(leftx) == 2 && my.at(topy) == 2) {
    cout << rightx << " " << downy;
  } else if (mx.at(leftx) == 2 && my.at(topy) == 1) {
    cout << rightx << " " << topy;
  } else if (mx.at(leftx) == 1 && my.at(topy) == 2) {
    cout << leftx << " " << downy;
  } else {
    cout << leftx << " " << topy;
  }
}
