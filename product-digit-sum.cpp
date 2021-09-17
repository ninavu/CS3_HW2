#include <iostream>	

using namespace std;

unsigned long long pow(int a, int b){
	unsigned long long result = 1; 
	
	for (int i = 0; i < b; i++){
		result *= a;
	}
	
	return result;
}	

int main(){
	int a;
	int b;
	unsigned long long product;
	int sum = 0;
	
	cout << "a: ";
	cin >> a;
	
	cout << "b: ";
	cin >> b;
	
	while (a < 0 || b < 0){				//keep prompting the user for positive integers input
		cout << "You dumb dumb! Positive integers only!" << endl;
		cout << "a: ";
		cin >> a;
		cout << "b: ";
		cin >> b;
	}
	
	product = pow(a, b);			//call pow(a,b) function to calculate a^b
	
	cout << a << "^" << b << " = " << product << endl;
	
	/* calculate the sum of the digits of the product by
	 * adding last digit of each number (after dividing by 10)
	 * to the sum */
	while (product > 0){	
		sum += product % 10;					
		product /= 10;						
	}
	
	cout << "Sum Of Digits: " << sum << endl;
	return 0;

}
