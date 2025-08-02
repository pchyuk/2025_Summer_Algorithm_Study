#include <iostream>
using namespace std;

int main(){

    int h, m, d;
    int a, b, c;

    int valid_md = 0, valid_dm = 0;
    int n;

    cin >> h >> m >> d;
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> a >> b >> c;
        switch(d){
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                if(d > 31) valid_md++;
                break;
            case 4: case 6: case 9: case 11:
                if(d > 30) valid_md++;
                break;
            case 2:
                if(h%4==0 && d > 29) valid_md++;
                else if(h%4!=0 && d > 28) valid_md++;
                break;
            
        }
    }
}