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

    int letters[26]={0};

    for(int i=0; i< str.length(); i++){
       char letter = str[i];
       if (letter >= 'a'&& letter<='z'||letter >= 'A'&& letter<='Z'){
        if(letter >= 'A'&& letter<='Z'){
            
            letter=letter+32;
            letters[letter -'a']++;
        }else{
            letters[letter -'a']++;
        }

       }

    }


    cout<<count<<" words."<<endl;
    char alpha = 'a';
    for (int i = 0; i < 26; i++) {

        if (letters[i]==0){
            alpha++;
            continue;
            
        }

            cout<<alpha<<"\t"<<letters[i]<<endl;
            alpha++;
        
		
	}
      

    return 0; 
}
