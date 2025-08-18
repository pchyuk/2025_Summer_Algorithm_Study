#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    int c, b;
    cin >> c >> b;
    if(c%b==0) cout << c/b << "\n";
    else printf("%.10lf\n", (double)c/b);
    return 0;
}