#include<iostream>
#include<string>

using namespace std;

int main(){
	// attributes for characters 1 and 2:
  	string ch1 = " "; // ch1 mean character 1
	int ch1_health, ch1_attack, ch1_defense = 0;

	string ch2 = " ";
	int ch2_health, ch2_attack, ch2_defense = 0;

	// data entry from the console:
	cout << "Enter character 1 name: "; getline(cin, ch1);
	cout << "Enter character 2 name: "; getline(cin, ch2);

	cout << "\nEnter the attributes for " << ch1 << ":" << endl;
	cout << "Health: "; cin >> ch1_health;
	cout << "Attack: "; cin >> ch1_attack;
	cout << "Defense: "; cin >> ch1_defense;

	cout << "\nNow enter the attributes for " << ch2 << ":" << endl;
	cout << "Health: "; cin >> ch2_health;
	cout << "Attack: "; cin >> ch2_attack;
	cout << "Defense: "; cin >> ch2_defense;

	cout << "\n--- Checking the status... ---\n";
	

	if (ch1_health <= 0 || ch2_health <= 0) {
		cout << "No way, someone is already dead! ┐(￣ヘ￣;)┌" << endl;
		return 0;
	}

	cout << "Both look healthy! Starting fight...\n" << endl;

	if (ch1_attack > ch2_defense) {
		cout << "CRITICAL HIT!!! ٩(ˊᗜˋ )و " << ch1 << " wins the fight!" << endl;
	} else if (ch2_attack > ch1_defense) {
		cout << "UNBELIEVABLE!!! (˶ˆᗜˆ˵) " << ch2 << " wins the fight!" << endl;
	} else {
		cout << "It's a draw! Both are too strong. ヽ(≧Д≦)ノ" << endl;
	}

	cout << "Let's start again! (˶˃ ᵕ ˂˶)" << endl;

	return 0;
}