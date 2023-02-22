#include<iostream>
using namespace std;

bool check(int arr[],int n,int s){

    bool t[n+1][s+1];
    for(int i=0;i<n+1;i++)
        for(int j=0;j<s+1;j++){    
                    if(i==0)
                        t[n][j]=0;
                    else if(j==0)
                    t[n][j]==1; 
        }
    for(int i=1;i<n;i++){
        for(int j=1;j<s;j++){
            if(j<arr[i-1])
                t[i][j]=t[i-1][j];
            if(j>=arr[i-1])
            t[i][j]=t[i-1][j]||t[i-1][j-arr[i-1]];
        }

    }
}

int main(){


    int arr[5];
    int s;
    for(int i=0;i<5;i++)
    cin>>arr[i];
    cin>>s;
    cout<<check(arr,5,s);

    return 0;
}