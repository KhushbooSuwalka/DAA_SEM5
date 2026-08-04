// Implement a C program that processes an unsorted integer array and multiple search queries .First,sort the given array using a quick sort algorithm and then answer each Query by determining whether a given element exists in the array using binary search
#include <iostream>
using namespace std;

// void LinearSearch(int arr[],int n){
//     int target;
//     cout<<"Enter the target:";
//     cin>>target;

//     int found=0;

//     for(int i=0;i<n;i++){
//         if(arr[i]==target){
//             found=1;
//             break;
//         }
//     }

//     if(found==0){
//         cout<<"Not found\n";
//     }else{
//         cout<<"Found\n";
//     }
// }

bool BinarySearch(int arr[], int target,int n)
{
    int low = 0;
    int high = n - 1;
    
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == target)
        {
            return true; // Found the element
        }
        else if (arr[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return false; // Element not found
}

int partition(int arr[], int low, int high)
{
    int i = low - 1;
    int pivot = arr[high];
    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

void DisplayArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main()
{
    int n;
    cout << "Enter no. of elements in the array:";
    cin >> n;

    int arr[n];
    cout << "Enter the array elements:";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Original Array:\n";
    DisplayArray(arr, n);

    // LinearSearch(arr,n);

    // Sort the array using quick sort...
    quickSort(arr, 0, n - 1);

    cout << "Sorted Array:\n";
    DisplayArray(arr, n);

    // Binary Search...
    int q;
    cout << "Enter the no. of queries:";
    cin >> q;

    while (q--)
    {
        int target;
        cout << "Enter the target:";
        cin >> target;

        if (BinarySearch(arr, target,n))
        {
            cout << "Found the element." << endl;
        }
        else
        {
            cout << "Not Found the element." << endl;
        }
    }

    return 0;
}

// Run the code :-
// g++ Code1.cpp -o Code1.exe
// .\Code1.exe