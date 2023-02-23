#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int mindiff(int arr[],int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
        sum=sum+arr[i];
    bool t[n+1][sum+1];

    for(int i=0;i<=n;i++)
        t[i][0]=true;
    for(int i=1;i<= sum;i++)
        t[0][i]=false;
    
    for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=sum;j++){
                if(j<arr[i-1]){
                    t[i][j]=t[i-1][j];
                }
                else
                    t[i][j]=t[i-1][j]||t[i-1][j-arr[i-1]];
            }
        }

    int diff=INT_MAX;
    for(int j=sum/2;j>=0;j--){
        if(t[n][j]==true){
            diff=sum-2*j;
            break;
        }
    }
    return diff;

}


int main(){

    int arr[4];
    for(int i=0;i<4;i++){
        cin>>arr[i];
    }

    cout<<mindiff(arr,4);

    return 0;
}