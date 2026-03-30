#include <stdio.h>

//백트래킹 과정과 재귀함수를 거친다.
int arr[14];
int arr2[14];
int K;

void DFS(int Start, int Depth)
{
    int i;
    if(Depth==6){
        for(i=0;i<6;i++){
            printf("%d ",arr2[i]);
            
        }
        printf("\n");
    }
    else{
        for(i=Start;i<K;i++){
            arr2[Depth]=arr[i];//현재 깊이에 숫자 하나를 찜한다.
            DFS(i+1,Depth+1);//다른칸을 채우기 위해 더 깊이 들어간다.
        }
        //*중요:DFS가 끝나고 돌아오면, 다음루프i++에서 자연스럽게 다른 숫자로 덮어씌워진다
    }
}

int main(){
    int i;
    while(1){
        scanf("%d",&K);
        if(K==0)
            break;
        for(i=0;i<K;i++)
            scanf("%d",&arr[i]);
        DFS(0,0);
        //DFS(0,0)시작->arr2=1저장
        DFS(1,1)호출->arr2=2ㅈ저장..계속 파고들어 arr=6까지 채움
        printf("\n");
    }
}