#include<iostream>
using namespace std;

int count(int coins[],int n,int sum){
        int t[n+1][sum+1];
        for(int i=0;i<=n;i++)  
            t[i][0]=1;
        for(int i=1;i<=sum;i++)
            t[0][i]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if(j>=coins[i-1])
                    t[i][j]=t[i-1][j]+t[i][j-coins[i-1]];
                else
                     t[i][j]=t[i-1][j];
            }
        }
        t[n][sum];
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