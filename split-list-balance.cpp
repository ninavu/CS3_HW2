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
	int minSum;
	
	if (m < 1){
		return 0;
	}
	
	if (m == 1){
		curMax.push_back(sum_vector(vec));
		return min(curMax);
	} 
	
	else {
			
		for (unsigned int i = 0; i < vec.size()-1; i++){
			vecLeft.push_back(vec.at(i));
			cout << "lhs: " << vec_to_string(vecLeft) << endl;			//COMMENT OUT
			vecRight.clear();
			sumLeft = sum_vector(vecLeft);
			for (unsigned int j = i+1; j < vec.size(); j++){
				vecRight.push_back(vec.at(j));
			}
			//split_vec(vecRight, m-1);
			
			sumRight = sum_vector(vecRight);
			cout << "rhs: " << vec_to_string(vecRight) << endl;			//COMMENT OUT
		
			curMax.push_back(max(sumLeft, split_vec(vecRight, m-1)));
				
			cout << "max sum: " << vec_to_string(curMax) << endl;			//COMMENT OU
		}
		minSum = min(curMax);
		cout << "min val: " << minSum << endl;				//COMMENT OUT
	}
	return minSum;
}

int main(){
	
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
	
	
	
	//return invalid if m = 0 or alist.size() equals m
	
	
	return 0;
}
