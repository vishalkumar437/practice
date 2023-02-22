#include<iostream>
using namespace std;
int t[6][6];

int knapsack(int w,int n,int wt[],int val[]){

    if(n==0||w==0)
        return 0;
    if(w>wt[n])
        return t[n][w]=max(val[n-1]+knapsack(w-wt[n-1],n-1,wt,val),knapsack(w,n-1,wt,val));
    else
        t[n][w]=knapsack(w,n-1,wt,val);

}
    int main(){
        int wt[5],val[5],w;
        int ans;
        for(int i=0;i<6;i++)
            {
                for(int j=0;j<6;j++)
                    t[i][j]=-1;
            }
        for(int i=0;i<5;i++)
            cin>>wt[i];
        for(int i=0;i<5;i++)
            cin>>val[i];
            cin>>w;
        ans=knapsack(w,5,wt,val);
            cout<<ans;

        return 0;
    }