#include<bits/stdc++.h>
using namespace std;

int count(int coins[],int n,int sum){
    
    int t[n+1][sum+1];
    for(int i=0;i<=n;i++)
        t[i][0]=0;
    for(int i=1;i<=sum;i++)
        t[0][i]=INT_MAX-1;
    for(int i=1,j=1;j<=sum;j++)
        {
            if(j%coins[0]==0)
                t[i][j]=j/coins[0];
            else
                t[i][j]=INT_MAX-1;
        }

    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=sum;j++){
            if(j>=coins[i-1])
                t[i][j]=min(1+t[i][j-coins[i-1]],t[i-1][j]);
            else    
                t[i][j]=t[i-1][j];
        }
    }
    return t[n][sum];

}



int main(){
    
    int coins[4];
    int sum;

    for(int i=0;i<4;i++)
        cin>>coins[i];
        cin>>sum;
    cout<<count(coins,4,sum);


    return 0;
}