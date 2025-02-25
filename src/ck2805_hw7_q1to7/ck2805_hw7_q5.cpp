#include <iostream>
using namespace std;

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize) {
    int counter = 0;

    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            counter++;
        }
    }

    outPosArrSize = counter;
    int* NewArr = new int[counter]; 
    int index = 0;

    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            NewArr[index] = arr[i];
            index++;
        }
    }

    return NewArr;
}

int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr) {
    int counter = 0;

    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            counter++;
        }
    }

    *outPosArrSizePtr = counter;
    cout << "Size of new array: " << *outPosArrSizePtr << endl;

    int* NewArr = new int[counter];
    int index = 0;

    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            NewArr[index] = arr[i];
            index++;
        }
    }

    return NewArr;
}

void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize){
    int counter = 0;

    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            counter++;
        }
    }

    outPosArrSize = counter;

    outPosArr=new int [outPosArrSize];
    int index = 0;

    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            outPosArr[index] = arr[i];
            index++;
        }
    }


}

void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr) {
    int counter = 0;

    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            counter++;
        }
    }

    *outPosArrSizePtr = counter; 

    *outPosArrPtr = new int[counter];  
    int index = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            (*outPosArrPtr)[index] = arr[i];
            cout << "Pointer index: " << (*outPosArrPtr)[index] << endl;
            index++;
        }
    }
}


int main() {

    cout<<"section a"<<endl;
    int outPosArrSize1;
    int arr1[] = {-3, 1, 3, -4, 6, -7};
    int arrSize1 = 6; 

    int* posArr1 = getPosNums1(arr1, arrSize1, outPosArrSize1);

    cout << "pointer address: " << posArr1 << endl;
    cout << "new array size: " << outPosArrSize1 << endl;
    cout << "new array: ";

    for (int i = 0; i < outPosArrSize1; i++) {
        cout << posArr1[i] << " ";
    }
    cout << endl;

    delete[] posArr1;





    cout<<"\nsection b"<<endl;

    int outPosArrSize2;
    int arr2[] = {-3, 1, 3, -4, 6, -7};
    int arrSize2 = 6; 

    int* posArr2 = getPosNums1(arr2, arrSize2, outPosArrSize2);

    cout << "pointer address: " << posArr2 << endl;
    cout << "new array size: " << outPosArrSize2 << endl;
    cout << "new array: ";

    for (int i = 0; i < outPosArrSize2; i++) {
        cout << posArr2[i] << " ";
    }
    cout << endl;

    delete[] posArr2;




    cout<<"section c"<<endl;

    int outPosArrSize3;
    int arr3[] = {-3, 2, 9, -4, 6, -7};
    int arrSize3 = 6; 

    int* ptrArr;

    getPosNums3(arr3,arrSize3, ptrArr, outPosArrSize3);

    cout<<"new array size: "<<outPosArrSize3<<endl;
    cout<<"ptr address: "<< ptrArr<<endl;
    cout << "new array: "<<endl;

    for (int i = 0; i < outPosArrSize3; i++) {
        cout << ptrArr[i] << " ";
    }
    cout << endl;

    cout<<"section d"<<endl;

    int arr4[] = {-3, 2, 9, -4, -6, 0};
    int arrSize4 = 6; 
    int* ptr1=nullptr;
    int** ptrArr2=&ptr1;
    int outPosArrSize4;

    getPosNums4(arr4,arrSize4, ptrArr2, &outPosArrSize4);

    cout<<"new array size: "<<outPosArrSize4<<endl;
    cout<<"ptr address: "<< ptrArr2<<endl;
    cout << "new array: "<<endl;

    for (int i = 0; i < outPosArrSize4; i++) {
        cout << (*ptrArr2)[i] << " ";
    }
    cout << endl;




    return 0;
}
