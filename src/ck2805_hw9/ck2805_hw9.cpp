#include <iostream>
#include <ctime>
#include <typeinfo>

using namespace std;

class Sim;

class Bug {
    private:
        int age;
        int x, y;
    public:
        Bug() : age(0) {}
        virtual ~Bug() {}
        virtual void starve(Bug* world[20][20]) {}
        virtual void move(Bug* world[20][20])=0;
        virtual void breed(Bug* world[20][20])=0;

        void setPosition(int newX, int newY) { x = newX; y = newY; }
        int getX() const { return x; }
        int getY() const { return y; }
        void incrementAge() { age++; }
        int getAge() const { return age; }
};

void Bug::move(Bug* world[20][20]) {}
void Bug::breed(Bug* world[20][20]) {}



class Ant : virtual public Bug {
    private:
    public:
        Ant();
        ~Ant();
        void move(Bug* world[20][20]) override;
        void breed (Bug* world[20][20])override;    
};
Ant::Ant() {}
Ant::~Ant() {}

void Ant::move(Bug* world[20][20]) {
    int x=getX();
    int y =getY();
    int direction = rand() % 4;
    int newX = x, newY = y;

    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            if (world[i][j] == this) {
                if (direction == 0 && x > 0) newX = x - 1; // up
                if (direction == 1 && x < 19) newX = x + 1; // down
                if (direction == 2 && y > 0) newY = y - 1; // left
                if (direction == 3 && y < 19) newY = y + 1; // right

                if (world[newX][newY] == nullptr) {
                    world[newX][newY] = this;
                    world[x][y] = nullptr;
                    setPosition(newX, newY);
                }

            }
        }
    }
}



void Ant::breed(Bug* world[20][20]){
//get time?
    if (this->getAge() % 3 == 0) {
        int direction = rand() % 4;
        int newX = -1, newY = -1;

        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 20; j++) {
                if (world[i][j] == this) {
                if (direction == 0 && i > 0) newX = i - 1, newY = j;
                if (direction == 1 && i < 19) newX = i + 1, newY = j;
                if (direction == 2 && j > 0) newX = i, newY = j - 1;
                if (direction == 3 && j < 19) newX = i, newY = j + 1;

                    if (newX != -1 && world[newX][newY] == nullptr) {
                            Ant* newAnt = new Ant();
                            newAnt->setPosition(newX, newY);
                            world[newX][newY] = newAnt;
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

    public:
        Doodlebug() : noFood(0) {}
        void move(Bug* world[20][20]) override;
        void breed (Bug* world[20][20]) override;
        bool eat(Bug* world[20][20]);
        void starve (Bug* world[20][20]);

};

bool Doodlebug::eat(Bug* world[20][20]) {
    int x=getX();
    int y =getY();
    int direction = rand() % 4;
    int newX = x, newY = y;

    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            if (world[i][j] == this) {
            if (direction == 0 && x > 0) newX = x - 1; // up
            if (direction == 1 && x < 19) newX = x + 1; // down
            if (direction == 2 && y > 0) newY = y - 1; // left
            if (direction == 3 && y < 19) newY = y + 1; // right

                if (world[newX][newY] != nullptr && dynamic_cast<Ant*>(world[newX][newY])) {

                delete world[newX][newY];
                world[newX][newY] = dynamic_cast<Ant*>(world[newX][newY]);
                world[x][y] = nullptr;
                setPosition(newX, newY);
                noFood = 0;
                return true;
                }
            }
        }
    }

    noFood++;
    return false;
}

void Doodlebug::starve(Bug* world[20][20]) {
    if (noFood >= 3) {
        int x = getX();
        int y = getY();
        world[x][y] = nullptr;
        delete this;
    }
}


void Doodlebug::move(Bug* world[20][20]){
    int x=getX();
    int y =getY();
    int direction = rand() % 4;
    int newX = x, newY = y;

    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            if (world[i][j] == this) {
                if (direction == 0 && x > 0) newX = x - 1; // up
                if (direction == 1 && x < 19) newX = x + 1; // down
                if (direction == 2 && y > 0) newY = y - 1; // left
                if (direction == 3 && y < 19) newY = y + 1; // right

                if (world[newX][newY] == nullptr) {
                    world[newX][newY] = this;
                    world[x][y] = nullptr;
                    setPosition(newX, newY);
                }

            }
        }
    }
}

void Doodlebug::breed(Bug* world[20][20]){
    if (this->getAge() % 8 == 0) {
        int direction = rand() % 4;
        int newX = -1, newY = -1;

    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            if (world[i][j] == this) {

                if (direction == 0 && i > 0) newX = i - 1, newY = j;
                if (direction == 1 && i < 19) newX = i + 1, newY = j;
                if (direction == 2 && j > 0) newX = i, newY = j - 1;
                if (direction == 3 && j < 19) newX = i, newY = j + 1;

                if (newX != -1 && world[newX][newY] == nullptr) {
                        Ant* newAnt = new Ant();
                        newAnt->setPosition(newX, newY);
                        world[newX][newY] = newAnt;
                    }
                    return;
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


Sim::Sim() {
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            world[i][j] = nullptr;
        }
    }
}


Sim::~Sim() {
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            if (world[i][j] != nullptr) {
                delete world[i][j];
                world[i][j] = nullptr;
            }
        }
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
        for (int j = 0; j < 20; j++) {
            if (world[i][j] != nullptr) {
                delete world[i][j];
                world[i][j] = nullptr;
            }
        }
    }

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
                world[x][y]->setPosition(x,y);
                antsPlaced++;
            }
    }

    while (doodles < 5) {
        int x = rand() % 20;
        int y = rand() % 20;
            if (world[x][y] == nullptr) {
                world[x][y] = new Doodlebug();
                world[x][y]->setPosition(x,y);
                doodles++;
            }
        }
}

void Sim::updateWorld() {

// move doodlebugs
for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 20; j++) {
        if (world[i][j] != nullptr && dynamic_cast<Doodlebug*>(world[i][j])) {
            world[i][j]->incrementAge();
            world[i][j]->starve(world);
            world[i][j]->breed(world);
            world[i][j]->move(world);

        }
    }
}

// move ants
for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 20; j++) {
        if (world[i][j] != nullptr && dynamic_cast<Ant*>(world[i][j])) {
            world[i][j]->incrementAge();
            world[i][j]->breed(world);
            world[i][j]->move(world);

            }
        }
    }

    time++;
}


void Sim::displayWorld() {
    cout << endl;
    cout << "World at time: " << time << endl;
    cout << endl;

    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            if (world[i][j] == nullptr) {
                cout << "- ";
            } else if (dynamic_cast<Ant*>(world[i][j])) {
                cout << "o ";
            } else if (dynamic_cast<Doodlebug*>(world[i][j])) {
                cout << "X ";
            }
        }
        cout << endl;
    }
}




int main() {
    srand(time(0));

    Sim sim;
    sim.fillWorld();

    for (int step = 0; step < 50; step++) {
        sim.displayWorld();
        cout << "Press ENTER to continue." << endl;

        string input;
        getline(cin, input);

        sim.updateWorld();
    }

    return 0;
}