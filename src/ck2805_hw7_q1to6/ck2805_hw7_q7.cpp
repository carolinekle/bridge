#include <iostream>
using namespace std;

int* findMissing(int arr[], int n, int& resArrSize){
    int counter=0;

    for(int i =0; i< n; i++){
        if(arr[i]==i){
            continue;
        }else{
            counter++;
        }
    }
    resArrSize=counter;
    int *NewArr;
    NewArr = new int[counter];

    return NewArr;

}


void printArray(int arr[], int arrSize) {
	int i;


	for (i = 0; i < arrSize; i++) {
		cout<<arr[i]<<' ';
	}
	cout<<endl;
}

int main(){
    int resArrSize;
    int arr1[10] = {3, 1, 3, 0, 6, 4};
	int arr1Size = 5;


    int* newArr=findMissing(arr1, arr1Size, resArrSize);
	printArray(arr1, arr1Size);
    return 0;
}