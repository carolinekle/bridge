#include <iostream>
using namespace std;

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

        cout<<"even"<<endl;
        for(int i =0; i<=arrSize-1;i++){
            cout<<evens[i];
        }
        cout<<endl;

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
        cout<<arr[i];
    cout<<endl;

    return 0;
}