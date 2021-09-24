#include <iostream>	
#include <vector>
#include <string>
#include <cassert>

using namespace std;

unsigned int sum_vector(vector<int> v){
	int sumVec = 0;
	
	for (unsigned int i = 0; i < v.size(); i++){
		sumVec += v.at(i);
	}
	return sumVec;
}

int max(int num1, int num2){
	int max;
	 
	if (num1 < num2){
		max = num2;
	} else {
		max = num1;
	}
	return max;
}

int min(vector<int> num){
	int min = INT_MAX;
	
	for (unsigned int i = 0; i < num.size(); i++){
		if (num.at(i) < min){
			min = num.at(i);
		}
	}
	return min;
}

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

int split_vec(vector<int> vec, int m){
	vector<int> vecLeft;
	vector<int> vecRight;
	int sumLeft;
	int sumRight;
	vector<int> curMax;
	int minSum = INT_MAX;
	
	if (m < 1){
		return 1;
	}
	
	if (m == 1){
		return sum_vector(vec);
	} 
	
	else {//if (m == 2){
		
		//for (unsigned int i = 1; i < m; i++){
			
		for (unsigned int i = 0; i < vec.size()-1; i++){
			vecLeft.push_back(vec.at(i));
			cout << "lhs: " << vec_to_string(vecLeft) << endl;			//COMMENT OUT
			vecRight.clear();
			sumLeft = sum_vector(vecLeft);
			for (unsigned int j = i+1; j < vec.size(); j++){
				vecRight.push_back(vec.at(j));
			}
			split_vec(vecRight, m-1);
			
			sumRight = sum_vector(vecRight);
			cout << "rhs: " << vec_to_string(vecRight) << endl;			//COMMENT OUT
			
			//split_vec(vecRight, m-1);
			curMax.push_back(max(sumLeft, sumRight));
			minSum = min(curMax);
				
			cout << "max sum: " << vec_to_string(curMax) << endl;			//COMMENT OUT
			cout << "min val: " << minSum << endl;				//COMMENT OUT
			}
		
	}
	minSum = min(curMax);
	return minSum;
}

int main(){
	
	//TEST 1: M = 1
	vector<int> alist = {2, 3, 4, 5, 6};
	int M1 = 1;
	cout << "input: " << vec_to_string(alist) << "   ";
	cout << "m: " << M1 << endl;
	cout << "ans: " << split_vec(alist, M1) << endl;
	
	//TEST 2: M = 2
	vector<int> blist = {2, 3, 4, 5, 6};
	int M2 = 2;
	cout << "input: " << vec_to_string(blist) << "   ";
	cout << "m: " << M2 << endl;
	cout << "ans: " << split_vec(blist, M2) << endl;
	
	//TEST 3: M = 3
	vector<int> clist = {2, 3, 4, 5, 6};
	int M3 = 3;
	cout << "input: " << vec_to_string(alist) << "   ";
	cout << "m: " << M3 << endl;
	cout << "ans: " << split_vec(clist, M3) << endl;
	
	//return invalid if m = 0 or alist equals 
	
	
	return 0;
}
