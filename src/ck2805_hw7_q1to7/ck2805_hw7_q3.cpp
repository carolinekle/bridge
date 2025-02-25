#include <iostream>
using namespace std;
//swap not working?

void oddsKeepEvensFlip(int arr[], int arrSize){
    int indexOO=0; int indexE=0;
    int *odds =new int [arrSize];
    int *evens = new int [arrSize];
        for(int i=0; i<arrSize; i++){
            if(arr[i]%2==1){
                odds[indexOO]= arr[i];
                indexOO++;
            }else{
                evens[indexE]= arr[i];
                indexE++;
            }
        }
        cout<<"odd"<<endl;
        for(int i =0; i<=arrSize-1;i++){
            
            cout<<odds[i];
        }
        cout<<endl;


        for(int i =0; i<= indexE;i++){
            if(evens[indexE]>evens[i]){
                int temp =evens[i];
                evens[i]=evens[indexE];
                evens[indexE]= temp;
            }
            indexE--;
        }


        int index =0;
        for (int j = 0; j < indexOO; j++)
            arr[index++] = odds[j];


        for (int j = 0; j < indexE; j++)
            arr[index++] = evens[j];

delete odds;
delete evens;

}


int main(){
    int arrSize;
    cout<<"Enter your array size"<<endl;
    cin>>arrSize;

    int arr[arrSize];

    cout<<"Enter the numbers you want for your array"<<endl;

    for(int i =0; i<=arrSize-1;i++)
        cin>>arr[i];

    oddsKeepEvensFlip(arr, arrSize);

    //print
    for(int i =0; i<=arrSize-1;i++)
        cout<<arr[i]<<", ";
    cout<<endl;

    return 0;
}