#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int randomGen(){
	return (rand() % 10);
}

void createArray(int num, int user[]) {
    for(int i = 4; i >= 0; i--) {
        user[i] = num % 10;
        num /= 10;
    }
}

bool verifyPass(int pin[], int user[]){
    int newArr[5];
    
    for(int i=0; i<6;i++){
        newArr[i]=user[i];
    }
    for(int i=0; i<6;i++){
        if(user[i]==newArr[i]){
            return true;
        }
    }
    
    return true;
}

int main(){
    
	srand(time(0));
    
    int pin[10]={0,1,2,3,4,5,6,7,8,9};
    int mapping[10];
    

    for (int i = 0; i < 10; i++) {
        mapping[i] = randomGen();
    }
    
    
    cout<<"PIN: ";
    for (int i=0; i<10;i++){
	    cout<<pin[i]<<" ";
	}
	cout<<endl;
	cout<<"NUM: ";
    for (int i=0; i<10;i++){
	    cout<<mapping[i]<<" ";
	}
	cout<<endl;
	
	cout<<"enter your pin: "<<endl;
	int num;
    cin>> num;

    int user[5];
    createArray(num, user);

	if(verifyPass(pin, user)){
	    cout<<"your pin is correct"<<endl;
	}else{
	    cout<<"your pin is not correct"<<endl;
	}
	

	return 0;
}