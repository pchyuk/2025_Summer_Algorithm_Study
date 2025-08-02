#include <iostream>
#include <string>
using namespace std;
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    string board;
    cin >> board;
    int len = board.length();
    int count = 0;

    for(int i=0; i<=len; i++){
        if(board[i] == 'X') count++;
        else {
            if(count % 2 != 0){
                printf("-1\n");
                return 0;
            }
            else if(board[i-1] == 'X'){
                int tmp;
                while(count>=4){
                    tmp = i-count;
                    for(int j=tmp; j<tmp+4; j++){
                        board[j] = 'A';
                    }
                    count -= 4;
                }
                if(count == 2){
                    tmp = i-count;
                    for(int j=tmp; j<tmp+2; j++){
                        board[j] = 'B';
                    }
                    count -= 2;
                }
            }
        }
    }

    cout << board << "\n";
    return 0;
}