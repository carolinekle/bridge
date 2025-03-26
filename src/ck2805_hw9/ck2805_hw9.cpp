#include <iostream>
#include <ctime>
#include <typeinfo>

using namespace std;

class Bug {
    private:
    
    public:
        virtual ~Bug() {}
        virtual void move(Bug* world[20][20]);
        virtual void breed(Bug* world[20][20]);
        virtual void timeSurvived();
        virtual bool isStarved();
 
};



class Ant : virtual public Bug {
    private:

    
    public:
        void move(Bug* world[20][20])override;
        void breed (Bug* world[20][20])override;
        void timeSurvived ()override;
};
class Doodlebug : public Bug {
    private:
        int noFood; 

    public:
        void move(Bug* world[20][20])override;
        void breed (Bug* world[20][20])override;
        void timeSurvived ()override;

}; 

void Doodlebug:: move(Bug* world[20][20]){
    int x = rand() % 4;
    int direction = rand() % 4;
    int newX = -1, newY = -1;
    
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            
            if (direction == 0 && i > 0) newX = i - 1, newY = j;
            if (direction == 1 && i < 19) newX = i + 1, newY = j;
            if (direction == 2 && j > 0) newX = i, newY = j - 1;
            if (direction == 3 && j < 19) newX = i, newY = j + 1;
        
            if (newX != -1 && world[newX][newY] == nullptr) {
                world[newX][newY] = this; // Move to new position
                world[i][j] = nullptr;    // Clear old position
                i = newX;
                j = newY;
            }
        }
    }
};

class Sim {
    private:
        int time;
        Bug* world[20][20]; // array of bugs 

    public:
        Sim(); // constructor
        ~Sim(); // destructor

        void fillWorld(); // fill world with ants and doodlebugs
        void displayWorld(); // display the simulation
        void updateWorld();

};

// Constructor
Sim::Sim() {
    time = 0;
    for (int i = 0; i < 400; i++) {
        for(int j =0; j< 20; j++)
            world[i][j] = nullptr;
    }
}

// Destructor
Sim::~Sim() {
    for (int i = 0; i < 400; i++) {
        for(int j =0; j< 20; j++)
            delete world[i][j];
        
    }
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

    //updateworld()   
}

void Sim::updateWorld(){

    // move dooodle bugs first and they eat 

    //world[i]->move;

};

int main() {
    srand(time(0));

    Sim sim;

    sim.fillWorld();
    sim.displayWorld();

    return 0;
}
