#include<iostream>
#include<string>
using namespace std;

struct data
{
    int id;
    string date;
};

//Sorting List in increased order with InsertionSort Algorithm
void idsort(data a[],int n)
{
     data t;
     int i,j;
     for (i=1;i<n;i++)
	{
		t=a[i];
		j=i-1;
		while(a[j].id > t.id && j>=0)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=t;

	}

}
//display record of list
void display(data a[],int n){

    int i;
    for (i=0;i<n;i++)
	{
	    cout<<"\nid: ";
		cout<<a[i].id;
		cout<<"\ndate: ";
        cout<<a[i].date;
	}
}
//sorting list as per the date of renewal using selection sort
void ssort(data b[],int n){
    int i,j,min;
    data t;
    for (i=0;i<n;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(b[j].date<b[min].date)
			{
				min=j;
			}
		}
		t=b[i];
		b[i]=b[min];
		b[min]=t;
	}

}


int main()
{
	int i,j,n;
	data t;
	string day,month,year;
	data record[100],backup[100];
	cout<<"Enter Number of Records: "<<endl;
	cin>>n;
	for(i=0;i<n;i++)
    {
        cout<<"Enter details of Person "<<i+1<<endl;
        cout<<"Enter Id"<<endl;
        cin>>record[i].id;
        cout<<"Enter Day"<<endl;
        cin>>day;
        cout<<"Enter Month"<<endl;
        cin>>month;
        cout<<"Enter Year"<<endl;
        cin>>year;

        record[i].date.append(year);
        record[i].date.append(month);
        record[i].date.append(day);
    }
    //copy of records to sort using selection sort
    for(i=0;i<n;i++)
    {
        backup[i]=record[i];
    }
    cout<<endl<<endl<<"Sorting with ID using Insertion Sort"<<endl;
    cout<<"Date is in YYYYMMDD Format"<<endl;

    idsort(record,n);

	display(record,n);

    cout<<endl<<endl<<"Sorting with date using Selection Sort"<<endl;
	ssort(backup,n);

	display(backup,n);


}
