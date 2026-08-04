//WAP to implememnt merge sort by using divide and conquer technique .

#include<iostream>
using namespace std;

void merge(int arr[],int low,int mid,int high){
    int temp[100];
    int i=low;
    int j=mid+1;
    int k=low;

    while(i<=mid && j<=high){
        if(arr[i]<=arr[j]){
            temp[k++]=arr[i++];
        }else{
            temp[k++]=arr[j++];
        }
    }

    while(i<=mid){
        temp[k++]=arr[i++];
    }

    while(j<=high){
        temp[k++]=arr[j++];
    }

    for(int i=low;i<= high;i++){
        arr[i]=temp[i];
    }
}

void mergeSort(int arr[],int low,int high){
    if(low < high){
        int mid = (low + high)/2 ;

        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);

        merge(arr,low,mid,high);
    }

}

void Display(int arr[],int n){
    for (int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n ;
    cout<<"Enter the no. of elements in array:";
    cin>>n;

    int arr[n];
    cout<<"Enter the elements:";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"Original array:";
    Display(arr,n);

    mergeSort(arr,0,n-1);
    cout<<"Array after sorting:";
    Display(arr,n);

    return 0;
}