#include <iostream>
#include <vector>

using std::vector;

using namespace std;

vector<int> Merge(vector<int> a, vector<int> b) {
    int i = 0, j = 0;
    vector<int> c;
    while (i < a.size() || j < b.size()) {
        if (a[i] <= b[j]) {
            c.push_back(a[i]);
            i++;
        }
        else {
            c.push_back(b[j]);
            j++;
        }
    }
    for (int k = i; k < a.size(); k++) {
        c.push_back(a[k]);
    }
    for (int k = j; k < b.size(); k++) {
        c.push_back(b[k]);
    }
    cout<<"Printing merged vaktor";
    for(int i = 0; i < c.size(); i++)
    {
        cout<<c[i]<<"\t";
    }
    cout<<endl;
    
    return c;
}

vector<int> MergeSort(vector<int> a, int start, int end)
{
    cout<<"Inside MERGESORT"<<endl;
    if (start >= end) {
        return a;
    }
    int mid = (start + end)/2;
    cout<<"mid = "<<mid<<endl;
    vector<int> left = MergeSort(a, start, mid);
    cout<<"left\n"<<endl;
    for (int i = 0; i < left.size(); i++)
    {
        cout<<left[i]<<"\t";
    }
    
    vector<int> right = MergeSort(a, mid + 1, end);
    cout<<"right\n"<<endl;
    for (int i = 0; i < right.size(); i++)
    {
        cout<<right[i]<<"\t";
    }
    
    return Merge(left, right);
}

// int kthSmallest(vector<int> a, int k, int l, int r)
// {
//     int min = 100000;
//     int minIndex;
//     while (k)
//     {

//         for (int i = 0; i <= r && i != minIndex; i++)
//         {
//             if (a[i] < min)
//             {
//                 minIndex = i;
//             }
//         }
//         k--;
//     }
//     min = a[minIndex];
//     return min;
// }

int main()
{
    int n, k;
    cout << "Enter Size of array: ";
    cin >> n;
    cout << "Enter K to find kth smallest: ";
    cin >> k;
    cout << "Enter Elements of array: " << endl;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> res = MergeSort(arr, 0, n - 1);
    cout << "Output:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}