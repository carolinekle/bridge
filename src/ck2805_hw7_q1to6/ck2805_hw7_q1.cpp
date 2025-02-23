#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main(){
    
    string str = "";
    vector<string> words;
    string space = " ";
    string word = "";
    int count=0;
    int start = 0;
 
    cout<<"insert a string"<<endl;
    getline(cin, str);


    for (int i = 0; i <= str.length(); i++) {
        if (i == str.length() || str[i] == ' ') { 
            if (i > start) { 
                word = str.substr(start, i - start);
                words.insert(words.end(), word);
                count++;
            }
            start = i + 1;
        }
    }



    for (int i = 0; i < words.size(); ++i) {
        cout << words[i] << " "<<endl;
      }
      

    return 0; 
}

/*for(int i=0; i<=str.length()+1;i++){
    if (str[i] == space[0]) { 
        word = str.substr(index, i);
        rest = str.substr(i, str.length());
        cout<<"word:"<<word<<endl;
        words.insert(words.end(), word);
        str=rest;
        index=i;
        count++;
    }
}*/