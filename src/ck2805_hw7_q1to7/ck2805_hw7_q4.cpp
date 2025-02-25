#include <iostream>
#include <string>
using namespace std;

string* createWordsArray(string sentence, int&outWordsArrSize){
    int count=0;
    int start=0;
    int index=0;

    for (int i = 0; i <= sentence.length(); i++){
        if(sentence[i] == ' '){
            count++;
        }
    }
    outWordsArrSize=count+1;

    string* words=new string[outWordsArrSize];


    for (int i = 0; i <= sentence.length(); i++) {
        if (i == sentence.length() || sentence[i] == ' ') { 
            if (i > start) { 
                string word = sentence.substr(start, i - start);
                words[index] = word;
                index++;
            }
            start = i + 1;
        }
    } 
    return words;
}

int main(){
    string sentence="";
    int outWordsArrSize;

    cout<<"enter a sentence"<<endl;
    getline(cin, sentence);

    string* words =createWordsArray(sentence, outWordsArrSize);

    for (int i = 0; i < outWordsArrSize; i++) {
        cout << "\""<<words[i]<<"\""<<" ";
    }
    cout<< endl;

    delete[] words;

    return 0;
}