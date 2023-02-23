#include<iostream>
using namespace std;

void check(int arr[],int n,int s){

    bool t[n+1][s+1];
    for (int i = 0; i <= n; i++)
        t[i][0] = true;
    for (int i = 1; i <= s; i++)
        t[0][i] = false;
    for(int i=1;i<n;i++){
        for(int j=1;j<s;j++){
            if(j<arr[i-1])
                t[i][j]=t[i-1][j];
            if(j>=arr[i-1])
            t[i][j]=t[i-1][j]||t[i-1][j-arr[i-1]];
        }

    }
    for(int i=0;i<n;i++){
        for(int j=0;j<s;j++){
            cout<<t[i][j]<<"   ";
        }
        cout<<endl;
    }
            
    cout<<t[n][s];
}

int main(){


    int arr[6];
    int s;
    for(int i=0;i<6;i++)
    cin>>arr[i];
    cin>>s;
    check(arr,6,s);

    return 0;
}