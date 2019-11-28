
//http://lanian.tistory.com/239

#include <iostream>
 
using namespace std;
 
int main()
{
    int i,j,k,s,e,min,n=8;
    int path[8],path_cnt=0;
    // unconnect
    const int U=static_cast<unsigned int>(-1)/2;
    int data[8][8] = {
        {0,2,U,U,U,3,U,U},
        {2,0,4,1,U,U,U,U},
        {U,4,0,U,3,U,U,U},
        {U,1,U,0,3,U,2,U},
        {U,U,3,3,0,U,U,4},
        {3,U,U,U,U,0,6,U},
        {U,U,U,2,U,6,0,4},
        {U,U,U,U,4,U,4,0}};
    bool v[8];
    int distance[8],via[8];
 
    // 출발, 도착 정점
    s=0,e=7;
 
    // 초기화
    for(i=0;i<n;i++)
    {
        v[i]=false;
        distance[i]=U;
    }
    distance[s]=0;
 
    // 찾기
    for(i=0;i<n;i++)
    {
        min=U;
        for(j=0;j<n;j++)
        {
            if(v[j]==false && distance[j]<min)
            {
                k=j;
                min=distance[j];
            }
        }
        v[k]=true;
        if(min==U)
            break;
        for(j=0;j<n;j++)
        {
            if(distance[k]==U || data[k][j]==U)
                continue;
            if(distance[j]>distance[k]+data[k][j])
            {
                distance[j]=distance[k]+data[k][j];
                via[j]=k;
            }
        }
    }
    // 최단 비용
    cout << distance[e] << endl;
    // 최단 경로
    k=e;
    while(true)
    {
        path[path_cnt++]=k;
        if(k==s)
            break;
        k=via[k];
    }
    for(i=path_cnt-1;i>=1;i--)
        cout << path[i] << " -> ";
    cout << path[i] << endl;
 
    return 0;
}