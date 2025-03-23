#include <iostream>
using namespace std;

// sim must take vector of ants and doodlebugs ?
class Sim{
    private:
        int time;
        // array with world 
        char world [400];
        

    public:
        Sim();
        void fillWorld();// fill world with default '-' and bugs
        void displayWorld();// create sim
        char getWorld();
        char setWorld();

        ~Sim();

};
//figure out how to pass/get present version of world without fill world 
/*
void Sim::getWorld(){

    return 
}
*/

/* class Bug{
    private:

    public:
        int move();
        int breed();
        int timeSurvived();
        void update(); //update time and movement of organisms  

};

class Ant:public Bug{
    private:
    public:
    // must overide breed/time and move
    //getter and setter for bug location?
};

class Doodlebug:public Bug{
    private:

    public:
        int starve();
        int eat();
        // must overide breed/time and move
        //getter and setter for bug location?
}; */




void Sim::fillWorld(){
    

}

void Sim::displayWorld(){
    //create sim board 
    //must use generated bug data here. would render empty world

    cout << "World at time: "<<time<<endl;
    cout<<endl;
    for(int i =0; i <20; i++){
        for(int j=0; j<20; j++){
            cout<<world[i] << " ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<< "Press ENTER to continue."<<endl;

}

int main(){

    Sim Sim;

    Sim.fillWorld();
    Sim.displayWorld();


    return 0;
}