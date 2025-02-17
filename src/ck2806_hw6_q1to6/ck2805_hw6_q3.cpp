#include <iostream>
using namespace std;
//are we allowed to modify the array in removeOdd?
void reverseArray(int arr[], int arrSize) {
    int j=0;
	int newArr[arrSize];
	for(int i=arrSize-1; i>=0; i--) {

		newArr[j] = arr[i];
		j++;
	}
	for (int i =0; i<=arrSize-1; i++) {
		cout<<newArr[i]<<" ";
	}
	cout<<endl;
}

void removeOdd(int arr[], int& arrSize){
    int count=0;
    for(int i=0;i<=arrSize-1; i++){
        if (arr[i]%2==0){
            arr[count]=arr[i];
            count++;
        }
    }
    arrSize=count;
    
    for(int i=0;i<=arrSize-1;i++){
        cout<<arr[i]<< " ";
        
    }
    cout<<endl;

}

void splitParity(int arr[], int arrSize){
    int index=0;
    int newArr[arrSize];
    int j=arrSize-1;
    
    for(int i=0; i<=arrSize-1;i++){
        if(arr[i]==1||arr[i]%2!=0){
            newArr[index]=arr[i];
            index++;
        }
        if(arr[i]%2==0){
            newArr[j]=arr[i];
            j--;
        }
        
    }
    for(int i=0;i<=arrSize-1;i++){
        cout<<newArr[i]<< " ";
        
    }
    cout<<endl;
}

void printArray(int arr[], int arrSize);

int main() {
	int arr1[10] = {9, 2, 14, 12, -3};
	int arr1Size = 5;

	int arr2[10] = {21, 12, 6, 7, 14};
	int arr2Size = 5;

	int arr3[10] = {3, 6, 4, 1, 12};
	int arr3Size = 5;


	reverseArray(arr1, arr1Size);
	printArray(arr1, arr1Size);

	removeOdd(arr2, arr2Size);
	printArray(arr2, arr2Size);

	splitParity(arr3, arr3Size);
	printArray(arr3, arr3Size);

	return 0;

}

void printArray(int arr[], int arrSize) {
	int i;

	for (i = 0; i < arrSize; i++) {
		cout<<arr[i]<<' ';
	}
	cout<<endl;
}