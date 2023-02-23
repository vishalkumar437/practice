#include<iostream>
using namespace std;
 void check(int arr[],int n,int sum){
        bool t[n+1][sum+1];
        for (int i = 0; i <= n; i++)
        t[i][0] = true;
        for (int i = 1; i <= sum; i++)
        t[0][i] = false;

        for(int i=1;i<n;i++){
            for(int j=1;i<sum;j++){

                if(j<arr[i-1]){
                    t[i][j]=t[i-1][j];

                }
                else if(j>=arr[i-1]){
                    t[i][j]=t[i-1][j]||t[i-1][j-arr[i-1]];
                }

            }
        }
        cout<<t[n][sum];
 }
 int main(){

    int arr[4];
    int s;

    for(int i=0;i<4;i++)    
        cin>>arr[i];
for(int i=0;i<4;i++)
    s=s+arr[i];
    cout<<s;
    if(s%2!=0)
    cout<<"false";
    else
        check(arr,4,s/2);

    return 0;
 }