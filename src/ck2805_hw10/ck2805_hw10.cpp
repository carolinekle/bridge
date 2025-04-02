#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Node{
    private:
        double paid;
        double owed=0;
        double payup=0;
        string* owedTo=nullptr;
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
        ~LinkedList(){}
        void addNode(double paid, string name);
        //void saveToFile(const string& filname);
        void insertatEnd(double paid, string name);
        void insertatHead(double paid, string name);
        double balance();
        void settle();
        int getSize(Node* head);
        //void head_insert(Node*& head, double paid, double owed, string name);
        bool isEmpty();
        //void clear();


};
/* void LinkedList::saveToFile(const string& filename) {
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Error opening output file.\n";
        return;
    }

    Node* temp = head;
    while (temp) {
        if (temp->paid >= 0) {
            outFile<<temp->name<<" "<<temp->owed<<" "<<temp->name<<endl;
        }
        temp = temp->next;
    }

    outFile.close();
} */

int LinkedList::getSize(Node* head){
    int count = 0;
    Node* current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
    
}

double LinkedList::balance(){

    Node* current = head;
    double totalPaid = 0;
    int count = 0;

    while (current != nullptr) {
        totalPaid += current->paid;
        count++;
        current = current->next;
    }

    double target = totalPaid / count;  

    current = head;

    while (current != nullptr) {
        current->owed = current->paid - target;
        current = current->next;
    }

    return target;
}

void LinkedList::settle() {
    vector<Node*> debtors, creditors;

    double target = balance();

    Node* current = head;
    while (current) {
        if (current->owed < 0) debtors.push_back(current);
        else if (current->owed > 0) creditors.push_back(current);
        current = current->next;
    }

    current = head;
    while (current) {
        if (current->owed == 0) {
            cout << current->name << ", you don't need to do anything." << endl;
        }
        current = current->next;
    }

    int i = 0, j = 0;
    while (i < debtors.size() && j < creditors.size()) {
        double amount = min(-debtors[i]->owed, creditors[j]->owed);



        cout << debtors[i]->name << ", you give " << creditors[j]->name 
             << " $" << amount << endl;

        debtors[i]->owed += amount;
        creditors[j]->owed -= amount;


        if (debtors[i]->owed == 0) i++;
        if (creditors[j]->owed == 0) j++;
    }

    cout << "\nIn the end, you should all have spent around $" << target << endl;
}



//now figure out who owes who lol so easy right ?

void LinkedList:: addNode(double paid, string name){
    Node* newNode = new Node(); 
    newNode->paid = paid; 
    newNode ->name = name;       
    newNode->next = head;      
    head = newNode;            
}

bool LinkedList:: isEmpty(){
    if (head == nullptr){
        return true;
    }
}

void LinkedList ::insertatEnd(double paid, string name){

    Node* newNode = new Node(); 
    newNode->paid = paid; 
    //newNode->owed = owed;
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

};

void LinkedList ::insertatHead(double paid, string name){
    Node* newNode = new Node(); 
    newNode->paid = paid; 
    //newNode->owed = owed;
    newNode ->name = name;       
    newNode->next = head;      
    head = newNode;            
};




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


int main (){

    ifstream inFile;

    openFile(inFile);

    LinkedList list;
    double paid;
    string name;

    while (inFile >> paid) {  
        inFile.ignore(); 
        getline(inFile, name);
        list.addNode(paid, name);
    }
    list.balance();
    list.settle();
    
    inFile.close();
    //list.getTarget(list);
    ofstream outFile;


    return 0;
}