#include<iostream>
#include<string>

using namespace std;

int main(){
	
	string greeting = "Hello everyone ";
	string message = "My name's Mauro I'm learning cpp from scratch";
	string main_message = greeting + message;
	string current_day = "day one of three hundred and sixty-five";
	string show_main_message = main_message + "\n" + "It is " + current_day;

	string name = "Mauro";
	int age = 28;
	float current_time = 20.00;
	char initial = 'M';
	bool beginner_cpp = true;

	string show_user = "My username: " + name + " the initial is " + initial;	

	cout << "--- My journal day 1 ---" << endl;
	cout << show_main_message << endl;
	
	cout << show_user << endl;
	cout << "My age " << age << endl;
	cout << "I'm begginer " << beginner_cpp << endl;
	cout << "Current time logged " << current_time << endl;
	cout << "--- End day 1 ---" << endl; 

	return 0;
}