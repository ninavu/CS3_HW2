#include <iostream>	

using namespace std;

unsigned long long pow(unsigned int a, unsigned int b){		// function calculates a^b
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
	int sumDigit = 0;
	
	cout << "a: ";
	cin >> a;
	
	cout << "b: ";
	cin >> b;
	
	if (a >= 0 && b >= 0){				// only calculate if the input is valid
		product = pow(a, b);			// call pow(a,b) function to calculate a^b
	
		cout << a << "^" << b << " = " << product << endl;
	
		//calculate the sum of the digits of the product
		while (product > 0){
			sumDigit += product % 10;	// add the last digit of the number to sum			
			product /= 10;				// remove last digit directly from product to calculate a new last digit			
		}
		
		cout << "Sum Of Digits: " << sumDigit << endl;
		
	} else {
		cout << "Invalid input!" << endl;
	}
	return 0;

}

// 0 times per day on average this thought has occured to me last week
