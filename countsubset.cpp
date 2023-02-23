#include<iostream>
using namespace std;

int count(int arr[],int n,int sum){
        int t[n+1][sum+1];

            t[0][0]=1;
        for(int j=0;j<sum;j++)
            t[0][j]=0;

        for(int i=1;i<n;i++)
        {
            for(int j=1;j<sum;j++){
                if(j>=arr[i-1]){
                    t[i][j]=t[i-1][j]+t[i-1][j-arr[i-1]];
                }
                else
                    t[i][j]=t[i-1][j];
            }
        }
        return t[n][sum];


}



int main(){

    int arr[4];
    int sum;
    for(int i=0;i<4;i++)
        cin>>arr[i];    
    cin>>sum;

    cout<<count(arr,4,sum);


    return 0;
}