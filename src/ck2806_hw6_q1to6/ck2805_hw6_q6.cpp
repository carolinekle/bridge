#include <iostream>
#include <string>
using namespace std;

string spliter(string str){
    string space =" ";
    for (int i = 0; i <=str.length()-1; i++) {

        if(static_cast<int>(str[i])>=48 && static_cast<int>(str[i])<=57){
            str[i]='x';
        }       
            
    }
        return str;
}



int main(){

    string str ="";    

    cout<<"enter a line of text: "<<endl;

    getline(cin, str);
    string blackout = spliter(str);

    cout<< blackout<<endl;


    return 0;
}