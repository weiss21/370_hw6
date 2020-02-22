/*
 * Title: heap.cpp
 * Abstract:  When the program starts, it should read a set of numbers from a 
 * user and store them in an array in the order the numbers are entered. 
 * Author: Wais Robleh
 * ID: 1624
 * Date: 02/22/2020
 */

#include <bits/stdc++.h>

using namespace std;

bool isHeap(vector<int> arr,  int n) 
{ 
    // Start from root and go till the last internal 
    // node 
    for (int i=1; i<=(n-1)/2; i++) 
    { 
        // If left child is greater, return false 
        if (arr[2*i +1] > arr[i]) 
                return false; 
  
        // If right child is greater, return false 
        if (2*i+2 < n && arr[2*i+2] > arr[i]) 
                return false; 
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
    
    if(isHeap(heap, inSize))
    {
        cout << "This is a heap." << endl;
    } else {
        cout << "This is NOT a heap." << endl;
        cout << "Heap constructed: ";
        makeHeap(heap, inSize);
        
    }
    
    printHeap(heap, inSize);
    /*
    for (int i = 1; i < inSize+1; i++)
    {
        cout << heap[i] << endl;
    }
    */
    
    return 0;
}