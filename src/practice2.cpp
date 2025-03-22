#include <iostream>
using namespace std;

int maxZeroLength(int arr[], int size, int start){
	if(start == size){
        return 0;
    }else{
	for (int i=start; i<size;i++){
        if(arr[i] != 0){
            return start++;
        }else{
            return maxZeroLength(arr, size, start++);
        }
    }
}
}

int main(){

int arr[]={0,0,1,0,0,0};
int size =6;
int start = 0;

int result = maxZeroLength(arr, size, start);
cout<< result<<endl;


return 0;
}
