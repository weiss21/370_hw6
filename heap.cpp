/*
 * Title: heap.cpp
 * Abstract:  Simple Max Heap. 
 * Author: Wais Robleh
 * ID: 1624
 * Date: 02/22/2020
 */

#include <bits/stdc++.h>

using namespace std;

bool isHeap (vector<int>& arr, int n){
    int left, right;
    int half = n/2;
    if (n%2 == 1)
    {
        half = n/2+1;
    }
    for (int i = half; i >= 1; i--)   {
        left = 2 * i;
        right = 2 * i + 1;
        if (left == n)
        {
            right = 0;
        }
        else if (right > n)
        {
            left = 0;
            right = 0;
        }

        if (arr[left] > arr[i] || arr[right] > arr[i])
        {
            return false;
        }
    }

return true;

}

void printHeap(vector<int> arr, int n){
    for (int i = 1; i < n+1; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

//Constructs a max heap
void makeHeap(vector<int>& arr, int n)
{
    int left, right, largest;
    while(!isHeap(arr, n))
    {
        for (int i = n/2; i >= 1 ; i--)
        {
            left = 2 * i;
            right = 2 * i + 1;
            if (left == n)
            {
                right = 0;
            }
            else if (right > n)
            {
                left = 0;
                right = 0;
            }
            //left child larger than right
            if (arr[left] > arr[right])
            {
                largest = left;
            }
            else //right child larger than largest
            {
                largest = right;
            }
            //if largest is not root
            if (arr[largest] > arr[i])
            {
                swap(arr[largest],arr[i]);
            }
        }
    }
}

void checkHeap(vector<int>& arr, int n){
    if(isHeap(arr, n))
    {
        cout << "This is a heap." << endl;
    } else {
        cout << "This is NOT a heap." << endl;
        cout << "Heap constructed: ";
        makeHeap(arr, n);
    }
}

//insert into heap
void insertHeap(vector<int>& arr, int& n, int value)
{
    n++;
    arr.push_back(value);
    makeHeap(arr, n);

}

//delete max from heap. always at 1
void deleteHeap(vector<int>& arr, int& n)
{
    arr[1] = arr[n];
    arr.resize(n);
    n--;

}

int main() {

    int inSize, num, insert, digit;
    bool quit = false;
    cout << "Input Size: ";
    cin >> inSize;
    cout << endl;
    
    vector<int> heap(inSize+1,0);//makes sure it starts at 0
    
    cout << "Enter numbers:";

    for (int i = 1; i < inSize+1; i++)
    {
        cin >> num;
        heap[i] = num;
    }

    checkHeap(heap,inSize);
    printHeap(heap, inSize);
    

    
    while(!quit){
        
        cout << "\nSelect an operation" << endl;
        cout << "1: Insert a number" << endl;
        cout << "2. Delete the max" << endl;
        cout << "3. Heapsort & Quit" << endl;
        
        
        cin >> digit;
        
        switch(digit){
        case 1:
            cout << "Enter a number: ";
            cin >> insert;
            insertHeap(heap, inSize, insert);
            cout << "Updated heap: " << endl;
            makeHeap(heap,inSize);
            printHeap(heap, inSize);
            break;
        case 2:
            deleteHeap(heap, inSize);
            cout << "Updated heap: ";
            makeHeap(heap,inSize);
            printHeap(heap,inSize);
            break;
        case 3:
        cout<< "Heapsort: ";
            makeHeap(heap,inSize);
            printHeap(heap,inSize);
            cout << "Bye!" << endl;
            quit = true;
            break;
        default:
                cout <<"Pick 1, 2 or 3!\n";
                break;
            
        }
    }
    return 0;
}