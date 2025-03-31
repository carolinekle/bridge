#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Node{
    private:
        double paid;
        //double owed=0;
        string name;
    public:
        Node* next;
        friend class LinkedList;

};

class LinkedList {
    private:
        Node* head;

    public:
        LinkedList():head(nullptr){}
        ~LinkedList(){clear();}
        void addNode(double paid, string name);
        void saveToFile(const string& filname);
        void insertatEnd(double paid, string name);
        void insertatHead(double paid, string name);
        //void head_insert(Node*& head, double paid, double owed, string name);
        bool isEmpty();
        void clear();


};
void LinkedList::saveToFile(const string& filename) {
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Error opening output file.\n";
        return;
    }

    Node* temp = head;
    while (temp) {
        if (temp->paid >= 0) {
            outFile << temp->name << endl;
        }
        temp = temp->next;
    }

    outFile.close();
}
void LinkedList:: addNode(double paid, string name){
    Node* newNode = new Node(); 
    newNode->paid = paid; 
    newNode ->name = name;       
    newNode->next = head;      
    head = newNode;            
}
/*
bool LinkedList:: isEmpty(){
    if (head == nullptr){
        return true;
    }
}

void LinkedList ::insertatEnd(double paid, double owed, string name){

    Node* newNode = new Node(); 
    newNode->paid = paid; 
    newNode->owed = owed;
    newNode ->name = name;       
    newNode->next = nullptr;         
    if (!head) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }

    temp->next = newNode;

}

void LinkedList ::insertatHead(double paid, double owed, string name){
    Node* newNode = new Node(); 
    newNode->paid = paid; 
    newNode->owed = owed;
    newNode ->name = name;       
    newNode->next = head;      
    head = newNode;            
}



*/
void openFile(ifstream& inFile){

    string fileName;
    cout<<"enter your file name i guess"<<endl;
    cin>>fileName;

    inFile.open(fileName);

    while(!inFile){

        cout<<"something wrong happened.\n try inputting the filename again."<<endl;
        cin>>fileName;
        inFile.clear();
        inFile.open(fileName);

        
    }

};
//temp struct to test
struct Person{
    double paid;
    double owed;
    string name;
};

int main (){

    ifstream inFile;

    openFile(inFile);

    //vector<Person> vs;

    //Person temp;
    //init node list 

    //idk if it should int temp. nothign in either classes is int 
    LinkedList list;
    int paid;
    string name;

    while (inFile >> paid) {  
        inFile.ignore();  // Ignore newline left in buffer
        getline(inFile, name);
        list.addNode(paid, name);
    }


    ofstream outFile;

    list.saveToFile("outfile.txt"); 

    /*
    for(Person p : vs){
        if( p.paid >= 0){
            outFile<<p.name<< endl; 
        };
    }
*/
    //outFile<<"  "<< endl; 


    return 0;
}