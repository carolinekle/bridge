#include <iostream>
#include<string>
using namespace std;

string lastName(string str, string& first){
    string last="";
    string space =" ";
    for (int i = str.length()-1; i >= 0; i--) {
        if (str[i] == space[0]) {
            last = str.substr(i + 1);
            first =str.substr(0, i);
            
            return last;
        }
    }
}

int main()
{
    string first="";
    string str="";
    cout<<"please enter your name"<<endl;
    getline(cin, str);

    cout<<lastName(str, first)<<", "<<first<< endl;

    return 0;
}