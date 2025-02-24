#include <iostream>
#include <vector>
#include <string>
using namespace std;



void main1(string str, int search2){
    int index=0;
    int arr[str.length()-1];

    for(int i=0; i<=str.length()-1; i++){

        if(search2==static_cast<int>(str[i]-48)){
            arr[index]=i+1;
            index++;
        }else{
            arr[index]=0;
            index++;
        }
    }

    cout<<"new array"<<endl;
    for(int i =0; i<=str.length()-1;i++){
        if(arr[i]==0){
            continue;
        }else{
            cout<<arr[i]<<" ";
        }
        
    }
    cout<<endl;


} 

vector<int> main2(vector<int> v, int search){
    int index=0;
    vector<int> result;
    for(int i =0; i <v.size(); i++){
        if(v[i]==search){
            result.insert(result.end(), i+1);
            index++;
        }else{
            continue;
        }
    }
    return result;

}

int main(){
/*     int num;
    vector<int> numbers;
    cout<<"section b, with vector: "<<endl;

    cout<<"Please enter a sequence of positive integers, each in a seperate line.\nEnd your input by typing -1."<<endl;
    int index =0;
    bool endInput= false;
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

    vector<int> result =main2(numbers, search);
    cout<< search<<" shows in line(s) ";
    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<" ";

    }
    cout<<endl;
 */
    cout<<"section a, without vector: "<<endl;

    string str ="";
    string input="";
    bool endWhile = false;
    
    cout<<"Please enter a sequence of positive integers, each in a seperate line.\nEnd your input by typing -1."<<endl;
    
    bool endInput= false;
    while(endInput == false){
        cin>>input;
        if(input == "-1"){
            endInput= true; 
        }else{
            str +=input;
        }
        input="";

    }


    int search2;
    cout<<"Please enter number you want to search: "<<endl;
    cin>> search2;

    main1(str, search2);


 /*
    

     for(int i =0; i<=index-1;i++){
        cout<<numbers[i];
    }
    cout<<endl; */


    return 0; 
}