#include <iostream>
using namespace std;
class Apple {
 string Variety;
 double weight;
 public:
	 Apple() {
		 Variety = " ";
		 weight = 0;
	 }
	 Apple (string fvariety, double fweight) {
		 Variety = fvariety;
		 weight = fweight;
		 
	 }
	 string getVariety() { return Variety; }
	 double getweight() { return weight; }
	


	 void Print() {
		 cout << "Variety:" << Variety << endl;
		 cout << "weight:" << weight << endl;

	 }

};
int main() {
	Apple apple("Br",15.0);
	apple.Print();
	Apple apple1("Uk", 5.f);
	apple1.Print();


	

	
	
}