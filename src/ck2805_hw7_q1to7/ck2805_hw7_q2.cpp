#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool comp(const array<int, 26>& letters1, const array<int, 26>& letters2){
    for(int i =0; i<=26; i++){
        if(letters1[i] != letters2[i]){
            return false;
        }
    }
    return true;
}


array<int, 26> createAlpha(vector<char> v){
    array<int, 26> letters = {0};
    for(int i=0; i<= v.size()-1; i++){
        char letter = v[i];
        if (letter >= 'a'&& letter<='z'||letter >= 'A'&& letter<='Z'){
         if(letter >= 'A'&& letter<='Z'){
             letter=letter+32;
             letters[letter -'a']++;

         }else{
             letters[letter -'a']++;
         }
 
        }
 
     }
     return letters;
     
} 

vector<char> breakDown(string str){
    vector<char> v;
    int start =0;
    string subString="";

    for (int i = 0; i <= str.length()-1; i++) {
        if (str[i] == ' ') { 
            continue;
        }

        v.push_back(str[i]);
    }

    return v;

}

int main(){
    string str="";
    string str2="";

    cout<<"insert a string"<<endl;
    getline(cin, str);

    cout<<"insert another string"<<endl;
    getline(cin, str2);

    vector<char> v1 = breakDown(str);
    vector<char> v2 = breakDown(str2);


    array<int, 26> arr1 = createAlpha(v1);
    array<int, 26> arr2 = createAlpha(v2);

    if (comp(arr1,arr2)){
        cout<<"it is an anagram"<<endl;
    }else{
        cout<<"it is not an anagram"<<endl;
    }



    return 0;
}