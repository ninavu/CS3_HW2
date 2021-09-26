#include <iostream>	
#include <vector>
#include <string>
#include <cassert>

using namespace std;

/* Function calculates a^b */
unsigned long long pow(unsigned int a, unsigned int b){		
	unsigned long long result = 1;		
	
	for (unsigned int i = 0; i < b; i++){
		result *= a;
	}
	
	return result;
}	

/* Function takes a single number and 
 * creates a vector of the digits in that number */
vector<unsigned short> vectorize_digits(unsigned long long n){
	vector<unsigned short> allDigit;
	int temp;								//a variable storing digits temporarily
	
	while (n > 0){
		allDigit.push_back(n % 10);			// add each last digit to the vector
		n /= 10;							// remove last digit directly from product to calculate a new last digit
	}
	
	for (unsigned int i = 0; i < allDigit.size()/2; i++){		//reverse the vector using loop
		temp = allDigit.at(i);
		allDigit.at(i) = allDigit.at(allDigit.size()-i-1);
		allDigit.at(allDigit.size()-i-1) = temp;
	}
	return allDigit;
}

/* Function takes a vector of numbers and 
 * returns the sum of those numbers */
unsigned int sum_vector(vector<unsigned short> digits){
	int sumDigits = 0;
	
	for (unsigned int i = 0; i < digits.size(); i++){
		sumDigits += digits.at(i);
	}
	return sumDigits;
}

/* Function takes a vector of numbers and 
 * returns an "aesthetically pleasing" string representation */
string vec_to_string(vector<unsigned short> v){
	string s = "[";
	for (unsigned int i = 0; i < v.size(); i++){
		 if (i == v.size() - 1){
			 s+= to_string(v.at(i));
		 } else {
			s += to_string(v.at(i)) + ", ";
		 }
	}
	s+= "]";
	return s;
}

void tests(){
	assert(sum_vector(vectorize_digits(pow(2,15))) == 26);			//TRUE
	assert(sum_vector(vectorize_digits(pow(3, 0))) == 1);			//TRUE
	assert(sum_vector(vectorize_digits(pow(2, 64))) == 0);			//TRUE due to overflow	(test for ver large number)
	assert(sum_vector(vectorize_digits(pow(1, 20))) == 2);			//FALSE (test for wrong result)
	assert(sum_vector(vectorize_digits(pow(5, -2))) == 10);			//FALSE (test for negative b)
	assert(sum_vector(vectorize_digits(pow(2, -3))) == 10);			//FALSE	(test for negative a)
	assert(sum_vector(vectorize_digits(pow(-5, -2))) == 10);		//FALSE (test for negative a and b)
}

int main(){
	int a;
	int b;
	unsigned long long product;
	
	//tests();
	
	cout << "a: ";
	cin >> a;
	
	cout << "b: ";
	cin >> b;
	
	if (a >= 0 && b >= 0){				// only calculate if the input is valid
		product = pow(a, b);			// call pow(a,b) function to calculate a^b
	
		cout << a << "^" << b << " = " << product << endl;
		
		vector<unsigned short> allDigits = vectorize_digits(product);
		unsigned int sumDigit = sum_vector(allDigits);
		
		cout << "Sum Of Digits: " << sumDigit << endl;
		
	} else {
		cout << "Invalid input!" << endl;
		return 1;
	}
	
	return 0;
}

// 0 times per day on average this thought has occured to me last week and last last week
