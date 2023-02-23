#include<iostream>
using namespace std;

int count(int arr[],int n,int sum){
     int t[n+1][sum+1];
     for(int i=0;i<=n;i++)
        t[i][0]=1;
     for(int i=1;i<=sum;i++)
        t[0][i]=0;
     for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(j<arr[i-1])
                t[i][j]=t[i-1][j];
            else    
                t[i][j]=t[i-1][j]||t[i-1][j-arr[i-1]];
        }
     }
     return t[n][sum];
}




int main(){
    int arr[4];
    int diff;
    int sum=0;
    for(int i=0;i<4;i++){
        cin>>arr[i];
        }
        cin>>diff;
    for(int i=0;i<4;i++)
        sum=sum+arr[i];
    int ans=(diff+sum)/2;
    cout<<count(arr,4,ans);
}