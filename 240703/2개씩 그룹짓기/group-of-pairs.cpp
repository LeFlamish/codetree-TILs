#include <iostream>
#include <algorithm>
using namespace std;
//inputArray에서 최댓값과 최솟값을 묶어서 원소 2개짜리 배열을 만들때 조건 만족
//삽입정렬을 통해서 inputArray의 원소들을 정렬할 계획
int main(){
    int N;
    cin>>N;
    int inputArray[2002];
    for(int i=0;i<2*N;i++){
        cin>>inputArray[i];
    }
    //inputArray 배열의 맨 처음 원소를 key라고 지정
    //key다음 원소값과 key값을 비교한다
    for(int x=1;x<2*N;x++){
        int key=inputArray[x];
        //key 다다음 원소=inputArray[2]값과 지금까지 정렬한 부분을 비교한다
        for(int y=x-1;y>=0;y--){
            if(inputArray[y]>key){ //key의 앞자리를 하나씩 비교
                inputArray[y+1]=inputArray[y]; //비교결과 앞자리가 작으면 한칸씩 밀어서 빈칸을 만들어준다
            }else{
                break;
            }
            inputArray[y]=key;//key값 업데이트
        }
        
    }
    int group_max=0;
    //intArray[0]+intArray[-1]하면 정의에 어긋남
    for(int i=0;i<2*N;i++){
        //i번째와 (2n-1-i)번째 원소 매칭 -> (5+5)경우의 수는 만들수 없음
        int group_sum=inputArray[i] + inputArray[2*N-1-i];
        if(group_sum>group_max)
            group_max=group_sum;
    }
    cout<<group_max;
}