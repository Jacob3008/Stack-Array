// Jacob Neuman 2/21/24

#include <iostream>
using namespace std;

const int STACK_SIZE = 4;

void push(string[], string);
void pop(string[]);
void display(string[]);
void validate(string&);
bool prompt(string[]);

int main() {
	string stack[STACK_SIZE];

	// repeate prompt until user exits
	while (prompt(stack))
		prompt(stack);

	return 0;
}

void push(string stack[], string val) {
	int sp = 0;

	// display error if stack is full
	if (stack[STACK_SIZE - 1] != "") {
		cout << "\nerror, overflow" << endl;
		return;
	}
	// find top of stack
	else {
		while (stack[sp] != "")
		{
			sp++;
		}
	}

	// assign top of stack to the new value
	validate(val);
	stack[sp] = val;
}

void pop(string stack[]) {
	int sp = 0;

	// display error if stack is empty
	if (stack[0] == "")
	{
		cout << "error, underflow" << endl;
		return;
	}
	// find top of the stack
	else if (stack[STACK_SIZE - 1] != "")
	{
		sp = STACK_SIZE - 1;
	}
	else {
		while (stack[sp + 1] != "")
		{
			sp++;
		}
	}

	// removes the value from the top of the stack
	cout << "Popped: " << stack[sp] << endl;
	stack[sp] = "";
}

void display(string stack[]) {
	int sp = 0;

	cout << "Stack Elements:";
	// loop through stack until all elements are displayed
	while (stack[sp] != "")
	{
		cout << " " << stack[sp];
		if (sp == STACK_SIZE - 1)
			break;
		sp++;
	}
	cout << endl;
}

void validate(string& val) {
	// makes sure string is 2 characters
	if (val.length() > 2) {
		val = val.substr(0, 2);
	}
	// add space if stack is 1 character
	else if (val.length() == 1)
	{
		val = val + ' ';
	}

	// changes value to uppercase or space
	for (int i = 0; i < val.length(); i++) {
		if (!isalpha(val.at(i))) {
			val.at(i) = ' ';
		}
		else {
			val.at(i) = toupper(val.at(i));
		}
	}
}

bool prompt(string stack[]) {
	int choice;

	cout << "1. Push" << endl;
	cout << "2. Pop" << endl;
	cout << "3. Display" << endl;
	cout << "4. Exit" << endl;
	cout << "Enter choice 1-4: "; cin >> choice;

	// validate choice
	while (choice > 4 || choice < 1) {
		cout << "Please enter a value 1-4: "; cin >> choice;
	}

	// push if choice is 1
	if (choice == 1) {
		string val;
		cout << "Enter value to push to the stack: "; cin >> val;
		push(stack, val);
		cout << endl;
		return true;
	}
	// pop if choice is 2
	else if (choice == 2) {
		cout << endl;
		pop(stack);
		cout << endl;
		return true;
	}
	// display if choice is 3
	else if (choice == 3) {
		cout << endl;
		display(stack);
		cout << endl;
		return true;
	}
	// exit
	else {
		return false;
	}
}