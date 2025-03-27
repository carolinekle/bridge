#include <iostream>
#include <ctime>
#include <typeinfo>

using namespace std;

class Bug {
    private:
        Sim* sim;
    
    public:
        virtual ~Bug() {}
        virtual void move(Bug* world[20][20])=0;
        virtual void breed(Bug* world[20][20])=0;
        virtual int getSimTime();
        virtual bool isStarved();
 
};

void Bug::move(Bug* world[20][20]) {}
void Bug::breed(Bug* world[20][20]) {}
int Bug::getSimTime(){
    return sim->getTime();
}
bool Bug::isStarved() { return false; }


class Ant : virtual public Bug {
    private:
        int timeSurvived=0;
    
    public:
        Ant();
        ~Ant();
        void move(Bug* world[20][20]) override;
        void breed (Bug* world[20][20])override;
        //void timeSurvived ()override;
};
Ant::Ant() {}
Ant::~Ant() {}

void Ant:: move(Bug* world[20][20]){
    int direction = rand() % 4;
    int newX = -1, newY = -1;

    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            if (world[i][j] == this) { // Find this doodlebug in the grid
                if (direction == 0 && i > 0) newX = i - 1, newY = j;
                if (direction == 1 && i < 19) newX = i + 1, newY = j;
                if (direction == 2 && j > 0) newX = i, newY = j - 1;
                if (direction == 3 && j < 19) newX = i, newY = j + 1;

                if (newX != -1 && world[newX][newY] == nullptr) {
                    world[newX][newY] = this;
                    // HOW TO NOT EAT DODOELBUG 
                }
                return; // Stop after moving
            }
        }
    }
}

void Ant::breed(Bug* world[20][20]){
    int time = getSimTime();
    //get time?
    if(time!= 0 && timeSurvived%3==0){
        int direction = rand() % 4;
        int newX = -1, newY = -1;
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 20; j++) {
                if (world[i][j] == this) {
                    int direction = rand() % 4;

                    if (direction == 1 && i < 19) newX = i + 1, newY = j;
                    if (direction == 2 && j > 0) newX = i, newY = j - 1;
                    if (direction == 3 && j < 19) newX = i, newY = j + 1;

                    if (newX != -1 && world[newX][newY] == nullptr) {
                    world[newX][newY] = new Doodlebug;
                
                    } 
                    return;
                }
            }
        }
    }
}

class Doodlebug : public Bug {
    private:
        int noFood; 
        int timeSurvived =0;

    public:
        void move(Bug* world[20][20]) override;
        void breed (Bug* world[20][20]) override;
        void starve (Bug* world[20][20]);

}; 

void Doodlebug::move(Bug* world[20][20]){
    int direction = rand() % 4;
    int newX = -1, newY = -1;

    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            if (world[i][j] == this) { // find this doodlebug in the grid
                if (direction == 0 && i > 0) newX = i - 1, newY = j;
                if (direction == 1 && i < 19) newX = i + 1, newY = j;
                if (direction == 2 && j > 0) newX = i, newY = j - 1;
                if (direction == 3 && j < 19) newX = i, newY = j + 1;

                if (newX != -1 && world[newX][newY] == nullptr) {
                    world[newX][newY] = this;
                    world[i][j] = nullptr;
                    this->timeSurvived++;
                }
                return; // Stop after moving
            }
        }
    }
};

void Doodlebug::breed(Bug* world[20][20]){
    int time = getSimTime();
    //get time?
    if(time!= 0 && timeSurvived%8==0){
        int direction = rand() % 4;
        int newX = -1, newY = -1;
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 20; j++) {
                if (world[i][j] == this) {
                    int direction = rand() % 4;

                    if (direction == 1 && i < 19) newX = i + 1, newY = j;
                    if (direction == 2 && j > 0) newX = i, newY = j - 1;
                    if (direction == 3 && j < 19) newX = i, newY = j + 1;

                    if (newX != -1 && world[newX][newY] == nullptr) {
                    world[newX][newY] = new Doodlebug;
                
                    } 
                    return;
                }
            }
        }
    }
}

void Doodlebug:: starve(Bug* world[20][20]){
    int time = getSimTime();
    //get time?
    if(time!= 0 && timeSurvived%3==0){
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 20; j++) {
                if (world[i][j] == this) {
                    world[i][j]== nullptr;
                }
            }
        }
    }
}

class Sim {
    private:
        Bug* world[20][20]; // array of bugs 
        int time=0;

    public:
        Sim(); // constructor
        ~Sim(); // destructor

        void updateWorld();
        void setTime(int time);
        int getTime();
        void fillWorld(); // fill world with ants and doodlebugs
        void displayWorld(); // display the simulation
        

};

// Constructor
Sim::Sim() {
    //time = 0;
    for (int i = 0; i < 20; i++) {
        for(int j =0; j< 20; j++)
            world[i][j] = nullptr;
    }
}

// Destructor
Sim::~Sim() {
    for (int i = 0; i < 20; i++) {
        for(int j =0; j< 20; j++)
            delete world[i][j];
        
    }
}

void Sim::setTime(int time){
    this->time=time;
};

int Sim::getTime(){
    return time;
}

void Sim::fillWorld() {
    int antsPlaced = 0, doodles = 0;
    

    for (int i = 0; i < 20; i++) {
        for(int j=0; j<20;j++){
            world[i][j] = nullptr;
        }

    }

    while (antsPlaced < 100) {
        int x = rand() % 20;
        int y = rand() % 20;

        if (world[x][y] == nullptr) { 
            world[x][y] = new Ant(); 
            antsPlaced++;
        }
    }

    while (doodles < 5) {
        int x = rand() % 20;
        int y = rand() % 20;
        if (world[x][y] == nullptr) { 
            world[x][y] = new Doodlebug(); 
            doodles++;
        }
    }
}

void Sim::updateWorld(){
    // move dooodle bugs first and they eat 

    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            if (world[i][j] != nullptr && typeid(*world[i][j]) == typeid(Doodlebug)) {
                world[i][j]->move(world);
            }
        }
    }

    //then move ants


    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            if (world[i][j] != nullptr && typeid(*world[i][j]) == typeid(Ant)) {
                world[i][j]->move(world);
            }
        }
    }
    time++;

};

void Sim::displayWorld() {
    cout << endl;
    cout << "World at time: " << time << endl;
    cout << endl;

    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {

    
            if (world[i][j] == nullptr) {
                cout << "- ";
            } else if (typeid(*world[i][j]) == typeid(Ant)) {
                cout << "o ";
            } else if (typeid(*world[i][j]) == typeid(Doodlebug)) {
                cout << "X ";
            } 
        }
        cout << endl;
    }
    cout << endl;
    cout << "Press ENTER to continue." << endl;
    char temp;
    cin.get(temp);

    if (temp =='\n'){
        updateWorld();
        displayWorld();
    }else{
        cout<<temp<<endl;
    }

}



int main() {
    srand(time(0));

    Sim sim;

    sim.fillWorld();
    sim.displayWorld();
   
    return 0;
}
