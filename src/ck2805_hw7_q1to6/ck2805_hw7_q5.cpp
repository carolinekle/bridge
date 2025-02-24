#include <iostream>
#include <vector>
using namespace std;



//no vector --  maybe for loop?

//vector
int main2(vector<int> v, int search){
    

}

int main(){
    int num;
    vector<int> numbers;

    cout<<"Please enter a sequence of positive integers, each in a seperate line.\nEnd your input by typing -1."<<endl;
    int index =0;
    bool endInput;
    while(endInput == false){
        cin>>num;
        if(num == -1){
            endInput= true; 
        }else{
            numbers.insert(numbers.end(), num);
            index++;
        }
    }
    int search;
    cout<<"Please enter number you want to search: "<<endl;
    cin>> search;

    main2(numbers, search);
    

    for(int i =0; i<=index-1;i++){
        cout<<numbers[i];
    }
    cout<<endl;


    return 0; 
}