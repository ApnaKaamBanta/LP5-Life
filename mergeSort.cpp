#include<stdio.h>
#include<iostream>
#include<omp.h>

using namespace std;

void mergeSort(int *, int, int);
void merge(int *, int, int, int);


void merge(int *arr, int low, int mid, int high){
    int temp[1000];
    int left = low;
    int right = mid+1;
    int tmp_ptr = 0;
    while(left <= mid && right <= high){
        if(arr[left] <= arr[right]){
            temp[tmp_ptr] = arr[left];
            left++;
            tmp_ptr++;
        }
        else{
            temp[tmp_ptr] = arr[right];
            right++;
            tmp_ptr++;
        }
    }

    while(left <= mid){
        temp[tmp_ptr] = arr[left];
        left++;
        tmp_ptr++;
    }

    while(right <= high){
        temp[tmp_ptr] = arr[right];
        right++;
        tmp_ptr++;
    }

    for(int i=low; i<= high; i++){
        arr[i] = temp[i - low];
    }

}


void mergeSort(int *arr, int low, int high){    
    //cout<<"Hi";
    int mid;
    if(low< high)
    {

    mid = (low+high) / 2;

    #pragma omp parallel sections
    {
        #pragma omp section
        {
            mergeSort(arr, low, mid);
        }

    #pragma omp section
    {
        mergeSort(arr, mid+1, high);      
    }

    }  

    merge(arr, low, mid, high);
    }
}



int main(){

    int *a, n;
    cout<<"Enter no. of elements in array: ";
    cin>>n;
    cout<<"Enter elements: ";
    a = new int[n];
    for(int i=0; i<n;i++){
        cin>>a[i];
    }

    #pragma omp...
    mergeSort(a, 0, n-1);

    cout<<"Sorted array is: ";
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    return 0;
}


