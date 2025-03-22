#include <iostream>
#include <string>
using namespace std;

class Product{
	public:
		double productTotal();
		double updateQuantity;
		Product(string name, double price, int quantity): name(name), price(price), quantity(quantity){};
	private:
		int quantity;
		string inputName();
		double inputNums;
		string name;
		double price;
};

double Product::productTotal(){
	return price*quantity;
};

string Product::inputName(){
	cout<<"input the prduct name"<<endl;
	getline(cin, name);
	return name;
	
}



/* double Product::updateQuantity(){
	return y;
}; */

int main (){



return 0;
}
