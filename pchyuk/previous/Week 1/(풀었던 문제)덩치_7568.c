// 나의 풀이 - 박찬혁

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int weight;
    int height;
    int rank;
} Person; // Person이라는 구조체를 만들고, 멤버 변수로 키, 몸무게 그리고 덩치 등수를 저장한다.

int main(){
    int n;
    scanf("%d", &n);

    Person p[n];
    for(int i=0; i<n; i++){
        scanf("%d %d", &p[i].weight, &p[i].height); // 각 사람별 몸무게와 키를 입력받고
        p[i].rank = 1; // 덩치 등수를 1등으로 초기화한다.
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){ // 반복문을 돌면서
            if(p[i].weight < p[j].weight && p[i].height < p[j].height){ // 자신보다 몸무게도 무겁고 키도 큰 사람이 있다면
                p[i].rank++; // rank값을 1 증가시킨다.(덩치 등수가 1 하락한다.)
            }
        }
    }

    for(int i=0; i<n; i++){
        printf("%d ", p[i].rank); // i번째 사람의 덩치 등수를 출력한다.
    }
    printf("\n");
    return 0;
}
