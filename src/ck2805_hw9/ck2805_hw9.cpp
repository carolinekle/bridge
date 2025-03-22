#include <iostream>
using namespace std;

class Organism{
    public:
        int move();
        int breed();
    private:

};

class Ant:public Organism{

};

class Doodlebug:public Organism{
    public:
        int starve();
    private:

};

int main(){


    return 0;
}