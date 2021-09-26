#include <iostream>	
#include <vector>
#include <string>

using namespace std;

/* Function takes a vector of numbers and 
 * returns the sum of those numbers 
 * (Reused from product-digit-sum.cpp) */
unsigned int sum_vector(vector<int> v){
	int sumVec = 0;
	
	for (unsigned int i = 0; i < v.size(); i++){
		sumVec += v.at(i);
	}
	return sumVec;
}

/* Function takes 2 numbers and returns the larger number */
unsigned int max(unsigned int num1, unsigned int num2){
	unsigned int max;
	 
	if (num1 < num2){
		max = num2;
	} else {
		max = num1;
	}
	return max;
}

/* Function takes a vector of integers and returns the smallest number */
unsigned int min(vector<int> num){
	unsigned int min = INT_MAX;			// use the largest integer as a starting point
	 
	for (unsigned int i = 0; i < num.size(); i++){
		if (num.at(i) < min){
			min = num.at(i);
		}
	}
	return min;
}

/* Function takes a vector of numbers and 
 * returns an "aesthetically pleasing" string representation
 * (Reused from product-digit-sum.cpp) */
string vec_to_string(vector<int> vec){
	string s = "[";
	for (unsigned int i = 0; i < vec.size(); i++){
		 if (i == vec.size() - 1){
			 s+= to_string(vec.at(i));
		 } else {
			s += to_string(vec.at(i)) + ", ";
		 }
	}
	s+= "]";
	return s;
}	

/* A recursive function that takes a vector of integers, splits it into M sub-lists, 
 * calculates the largest sum of each sub list and 
 * then returns the smallest number of the largest sums */
int split_vec(vector<int> vec, int m){
	vector<int> vecLeft;
	vector<int> vecRight;
	unsigned int sumLeft;
	unsigned int sumRight;
	vector<int> curMax;
	unsigned int minSum = INT_MAX;
	
	if (m == 1){				// base case: calculating the sum of the list and return it
		curMax.push_back(sum_vector(vec));
		return min(curMax);
	} 
	else {
			
		for (unsigned int i = 0; i < vec.size()-1; i++){
			vecLeft.push_back(vec.at(i));					// push number 1 by 1 to the vector
			vecRight.clear();								// clear vecRight before pushing new numbers using the loop
			sumLeft = sum_vector(vecLeft);					// call sum_vector to calculate the sum of the left vector
			
			for (unsigned int j = i+1; j < vec.size(); j++){
				vecRight.push_back(vec.at(j));				// push number into an empty right vector after the left vector done with pushing 
			}
			
			sumRight = sum_vector(vecRight);		
			
			//a recursive statement calculating the max of all sub-lists and pushing them into a vector
			//that is updated everytime a new wave of sub-list splits
			curMax.push_back(max(sumLeft, split_vec(vecRight, m-1)));		
		}
		minSum = min(curMax);			// calculate the minSum from the most updated maximum sum	
	}
	return minSum;
}

int main(){
	vector<int> vec;
	unsigned int num;
	unsigned int M;
	int result;
	
	cout << "Start testing..." << endl;
	//TEST 1: M = 1
	vector<int> alist = {2, 3, 4, 5, 6};
	int M1 = 1;
	cout << "input: " << vec_to_string(alist) << "   m: " << M1 << endl;
	cout << "ans: " << split_vec(alist, M1) << endl;
	
	//TEST 2: M = 2
	vector<int> blist = {7, 2, 5, 10, 8};
	int M2 = 2;
	cout << "input: " << vec_to_string(blist) << "   m: " << M2 << endl;
	cout << "ans: " << split_vec(blist, M2) << endl;
	
	cout << "input: " << vec_to_string(alist) << "   m: " << M2 << endl;
	cout << "ans: " << split_vec(alist, M2) << endl;
	
	
	//TEST 3: M = 3
	vector<int> clist = {1, 4, 4};
	int M3 = 3;
	cout << "input: " << vec_to_string(clist) << "   m: " << M3 << endl;
	cout << "ans: " << split_vec(clist, M3) << endl;
	
	//TEST 4: M = 4
	vector<int> dlist = {1, 3, 7, 2, 5};
	int M4 = 4;
	cout << "input: " << vec_to_string(dlist) << "   m: " << M4 << endl;
	cout << "ans: " << split_vec(dlist, M4) << endl;
	
	cout << "input: " << vec_to_string(clist) << "   m: " << M4 << endl;
	cout << "ans: " << split_vec(clist, M4) << endl;
	
	//TEST 5: M = 5
	vector<int> elist = {1, 3, 7, 2, 4, 6, 9};
	int M5 = 5;
	cout << "input: " << vec_to_string(elist) << "   m: " << M5 << endl;
	cout << "ans: " << split_vec(elist, M5) << endl;
	
	cout << "input: " << vec_to_string(alist) << "   m: " << M5 << endl;
	cout << "ans: " << split_vec(alist, M5) << endl;
	
	
	//TEST 6: M = -1
	vector<int> flist = {2, 3, 4, 5, 6, 7};
	int M6 = -1;
	cout << "input: " << vec_to_string(flist) << "   m: " << M6 << endl;
	cout << "ans: " << split_vec(flist, M6) << endl;
	
	// ALLOW USER INPUT FOR TESTING
	cout << "Please type in positive numbers for the vector (type -1 to quit): " << endl;
	cin >> num;
	
	while (num != -1){
		if (num > 0){
			vec.push_back(num);
		} else {
			cout << "Invalid Input!" << endl;
			return 1;
		}
		cin >> num;
	}
	
	cout << "Please type in a positive M: ";
	cin >> M;
	
	if (M < 1 || vec.size() < M){
		cout << "Invalid Input! M cannot be less than 0 or M cannot be larger than the list size! " << endl;
		return 1;
	}
	
	result = split_vec(vec, M);
	cout << "input: " << vec_to_string(vec) << "   m: " << M << endl;
	cout << "ans: " << split_vec(vec, M) << endl;
	
	return 0;
}
