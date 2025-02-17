#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string str){
    
    string newString="";
    
    for(int i=str.length()-1; i>=0;i--){
        newString += str[i];

    }

    
    for(int i=0; i<str.length()-1;i++){
        if(newString[i]==str[i]){
            return true;
        }else{
            return false;
        }
        
    }
}

int main(){
    
    string str = "";
    
    cout<<"enter a string"<<endl;
    getline(cin, str);
    
    if(isPalindrome(str)){
        cout<<str<<" is a palindrome!"<<endl;
    }else{
         cout<<str<<" is not a palindrome!"<<endl;
    }

    
    
    return 0;
}