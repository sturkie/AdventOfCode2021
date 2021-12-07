//Advent of Code: Day 1

/*
 * Part 1:
 * To do this, count the number of times a depth measurement increases from the previous measurement.
 * (There is no measurement before the first measurement.)
 *
 * Part 2:
 * Your goal now is to count the number of times the sum of measurements in this sliding window increases from the previous sum.
 * So, compare A with B, then compare B with C, then C with D, and so on.
 * Stop when there aren't enough measurements left to create a new three-measurement sum.
 */

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int calculate_windows(int index, vector<int>& depths){
	int window = 0;

	for(int i = index; i < index+3; i++){
		//cout << depths.at(i) << endl;
		window += depths.at(i);
	}

	//cout << "Window from index (" << index << "): " << window << endl;
	return window;
}

int calculate_window_increments(vector<int>& depths){
	int amount_of_increments = 0;
	int window_A = 0;
	int window_B = 0;

	//initial window
	for(int i = 0; i < 3; i++){
		window_A += depths.at(i);
	}
	//cout << window_A << endl;

	for(int i = 0; i < depths.size()-3; i++){
		window_A = calculate_windows(i, depths);
		window_B = calculate_windows(i+1, depths);
		if(window_A < window_B){
			amount_of_increments++;
		}
	}


	return amount_of_increments;
}

int calculate_increments(vector<int>& depths){
	int amount_of_increments = 0;
	int last_value = depths.at(0);


	for(int i = 1; i < depths.size(); i++){
		if(last_value < depths.at(i)){
			amount_of_increments++;
		}
		last_value = depths.at(i);
	}

	return amount_of_increments;
}

void process_file(string filename, vector<int> &depths){

	string value;

	ifstream myfile (filename);
	if(myfile.is_open()){
		while(getline(myfile,value)){

			depths.push_back(stoi(value));
		}
	}

	return;
}

int main(){

	string filename;
	int total = 0;
	vector<int> depths;


	cout << "Input filename: ";
	cin >> filename;

	process_file(filename, depths);
	total = calculate_window_increments(depths);

	cout << "Total increments: " << total << endl;

	return 0;
}
