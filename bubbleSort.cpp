#include<iostream>
#include<stdlib.h>
#include<omp.h>
using namespace std;

void bubble(int *, int);
void swap(int &, int &);


void bubble(int *a, int n)
{
    for(  int i = 0;  i < n;  i++ )   
     {  	 	 

   	 #pragma omp parallel for shared(a,first)
   	 for(  int j = 0;  j < n-i-1;  j++  )
   	   {  	 
   		 if(  a[ j ]  >  a[ j+1 ]  )
   		  {  	 
     			 //swap(  a[ j ],  a[ j+1 ]  );
                 int temp = a[j];
                 a[j] = a[j+1];
                 a[j+1] = temp;
   		  }  	 
   		   }  	 
     }
}


void swap(int &a, int &b)
{

    int temp;
    temp=a;
    a=b;
    b=temp;

}

int main()
{

    int *a,n;
    cout<<"\n enter total no of elements: ";
    cin>>n;
    a = new int[n];
    cout<<"\n enter elements=>";
    for(int i=0;i<n;i++)
    {
   	 cin>>a[i];
    }
    
    bubble(a,n);
    
    cout<<"\n sorted array is: ";
    for(int i=0;i<n;i++)
    {
   	 cout<<a[i]<<" ";
    }


return 0;
}
