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

    int half = n/2;
    if (n%2 == 1)
    {
        half = n/2+1;
    }
    for (int i = 1; i < half; i++)   {
        if (arr[2*i] > arr[i] || arr[2*i+1] > arr[i]){
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
void makeHeap(vector<int>& heap, int inputSize)
{
    int left, right, largest;
    while(!isHeap(heap, inputSize))
    {
        for (int i = inputSize/2; i >= 1 ; i--)
        {
            left = 2 * i;
            right = 2 * i + 1;
            if (left == inputSize)
            {
                right = 0;
            }
            else if (right > inputSize)
            {
                left = 0;
                right = 0;
            }
            //left child larger than right
            if (heap[left] > heap[right])
            {
                largest = left;
            }
            else //right child larger than largest
            {
                largest = right;
            }
            //if largest is not root
            if (heap[largest] > heap[i])
            {
                swap(heap[largest],heap[i]);
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

int main() {

    int inSize, num;
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
    /*
    if(isHeap(heap, inSize))
    {
        cout << "This is a heap." << endl;
    } else {
        cout << "This is NOT a heap." << endl;
        cout << "Heap constructed: ";
        makeHeap(heap, inSize);
        
    }
    */
    checkHeap(heap,inSize);
    printHeap(heap, inSize);
    cout << "\nSelect an operation" << endl;
    cout << "1: Insert a number" << endl;
    cout << "2. Delete the max" << endl;
    cout << "3. Heapsort & Quit" << endl;

    
    
    return 0;
}