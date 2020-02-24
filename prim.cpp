/*
 * Title: prim.cpp
 * Abstract:  Implementation of Prim's algorithm using txt files as input.
 * Author: Wais Robleh
 * ID: 1624
 * Date: 02/23/2020
 */

#include <bits/stdc++.h>

using namespace std;


int minKey(int* key, bool* mstSet, int vertices) 
{ 
    int min = 99999, min_index; 
  
    for (int i = 0; i < vertices; i++) 
        if (mstSet[i] == false && key[i] < min) 
            min = key[i], min_index = i; 
  
    return min_index; 
} 


int main() {
    int vertices, edges, startingVertex;
    string fileName;
    
    cout << "Enter input file name: ";
    cin >> fileName;
    cout << "Enter the first vertex to start: ";
    cin >> startingVertex;
    cout << endl;
    
    ifstream inStream(fileName.c_str());
    
   
    inStream >> vertices;
    inStream >> edges;
    
    int arr[vertices][vertices];
    
    for(int i=0; i<vertices; i++){    
		for(int j=0; j<vertices; j++){
			arr[i][j] = 0;
		}
	}
	
	for(int i=0; i<edges; i++){
	    int x, y, weight; 
	    inStream >> x;
	    inStream >> y;
	    inStream >> weight;
	    arr[x-1][y-1] = weight;
	    arr[y-1][x-1] = weight;
	}
	inStream.close();
	
    int parent[vertices]; 
    int key[vertices]; 
    bool mstSet[vertices]; 
  
    for (int i=0; i<vertices; i++) 
        key[i] = 99999, mstSet[i] = false; 
  
    key[startingVertex-1] = 0; 
    parent[startingVertex-1] = -1;  
  
    for (int count=0; count<vertices-1; count++) { 
        int i = minKey(key, mstSet, vertices); 
  
        mstSet[i] = true; 
  
        for (int j=0; j<vertices; j++) 
  
            if (arr[i][j] && mstSet[j] == false && arr[i][j] < key[j]) 
                parent[j] = i, key[j] = arr[i][j]; 
    } 
  
    for (int i = 1; i < vertices; i++) 
        cout << "(" << i << ") New edge: " << parent[i]+1 << "," << i+1 << " -- cost " << arr[i][parent[i]] << endl;
}