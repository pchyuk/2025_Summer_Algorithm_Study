#include <iostream>
using namespace std;

int main(){
    double num[2][2];
    cin >> num[0][0] >> num[0][1];
    cin >> num[1][0] >> num[1][1];
    
    double result[4];
    for(int i=0; i<4; i++){
        int tmp;
        result[i] = num[0][0]/num[1][0] + num[0][1]/num[1][1];
        tmp = num[0][0];
        num[0][0] = num[1][0];
        num[1][0] = num[1][1];
        num[1][1] = num[0][1];
        num[0][1] = tmp;
    }
    int rotate = 0;
    double max = result[0];
    for(int i=0; i<4; i++){
        if(max < result[i]){
            max = result[i];
            rotate = i;
        }
    }
    cout << rotate << "\n";
    return 0;
}