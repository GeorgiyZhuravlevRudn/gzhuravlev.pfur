#include <iostream>
#include<cmath>
#include<string>
#include "CalcHeader.h"
using namespace std;
//double fillVar(int variable_number) {
//	double a;
//	double b;
//	if (variable_number == 2) {
//		cout << "first variable: "; cin >> a;
//		cout << "second variable: "; cin >> b;
//	}
//	else {
//		variable
//	}
//}
void OperationTypes() {
	cout << "There are only few possible operations with ONE or TWO variables: \n";
	cout << "Basic: + ; -; * ; / ; pow.\nTrigonometric: sin; cos; tan.\n";
	cout << "Please, use only this operators, otherwise it won't work.\n";
}

double Calculate(int variable_number) {
	double a=0;
	double b=0;
	string operationCalc;
	if (variable_number == 2) {
	cout << "first variable: "; cin >> a;
	operationCalc = operation();
	cout << "second variable: "; cin >> b;
	}
	else if(variable_number==1){
		cout << "variable: "; cin >> a;
		operationCalc = operation();
	}
	else {
		cout << "wrong option, only  ONE or TWO variables";
		return 1;
	}
	double result; 
	if (operationCalc == "+") {
		result = a + b;
	}
	else if (operationCalc == "-") {
		result = a - b;
	}
	else if (operationCalc == "*") {
		result = a * b;
	}
	else if (operationCalc == "/") {
		if (b == 0) {
			cout << "that can't be done(doesn't exist)\n";
			return 1;
		}
		else {
			result = a / b;
		}
	}
	else if (operationCalc == "sin") {
		 result = sin(a);
	}
	else if (operationCalc == "cos") {
		result = cos(a);
	}
	else if (operationCalc == "tan") {
		if (cos(a) == 0) {
			cout << "that can't be done(doesn't exist)\n";
			return 1;
		}
		else {
			result = tan(a);
		}
	}
	else if (operationCalc == "pow") {
			int power;
			cout << "to power of: "; cin >> power;
			result = pow(a,power);

	}
	else {
		cout << "wrong option, operator is undefined ";
		return 1;
	}
	if (variable_number == 2) {
		cout << a <<" "<< operationCalc <<" "<< b << " = "<< result;
	}
	else{ 
		cout << operationCalc << "(" << a << ") = " << result;
	}
}
int NumofVar() {
	int VarNum;
	cout << "how many variables do you need?( 1 or 2): "; cin >> VarNum;
	return VarNum;
}


