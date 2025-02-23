#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main(){
    
    string str = "";
    vector<string> words;
    string space = " ";
    string word = "";
    int count;
 
    cout<<"insert a string"<<endl;
    cin>>str;


    for(int i=0; i<=str.length()-1;i++){
        if (str[i] == space[0]) { 
            word = str.substr(i + 1);
            cout<<"word:"<<word<<endl;
            words.insert(words.begin(), word);
            count++;
        }
    }

    cout<< "count: " << count<<endl;

    return 0; 
}