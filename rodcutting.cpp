#include<iostream>
using namespace std;
int cutRod(int price[], int n) {
        int length[n];
        for(int i=0;i<=n;i++)
            length[i]=i+1;
        int dp[n+1][n+1];
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i==0||j==0)
                dp[i][j]=0;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(j>=length[i-1])
                    dp[i][j]=max(price[i-1]+dp[i][j-length[i-1]],dp[i-1][j]);
                else
                    dp[i][j]=dp[i-1][j];
            }
            
        }
        return dp[n][n];
    }

int main(){

    int price[5];
    for(int i=0;i<5;i++)
        cin>>price[i];
    
    cout<<cutRod(price,5);

    return 0;
}
    