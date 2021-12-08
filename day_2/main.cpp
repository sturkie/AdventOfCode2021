#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

void calculate_position(vector<string>& steps, int& depth, int& horizontal, int& aim){

	string forward = "forward";
	string up = "up";
	string down = "down";
	int value = 0;

	for(int i = 0; i<steps.size();i++){
		if(steps.at(i).find(forward) != string::npos){
			value = stoi(steps.at(i).substr(steps.at(i).length()-2));
			horizontal += value;
			depth += aim*value;
		}
		else if(steps.at(i).find(up) != string::npos){
			value = stoi(steps.at(i).substr(steps.at(i).length()-2));
			aim -= value;
		}
		else if(steps.at(i).find(down) != string::npos){
			value = stoi(steps.at(i).substr(steps.at(i).length()-2));
			aim += value;
		}
	}

	return;
}

void process_file(vector<string>& steps, string filename){

	string line;
	ifstream myfile(filename);

	if(myfile.is_open()){

		while(getline(myfile,line)){
			steps.push_back(line);
		}
	}

	return;
}


int main(){

	string filename;
	int depth = 0;
	int horizontal = 0;
	int aim = 0; //part 2
	vector<string> steps;

	cout << "Enter filename: ";
	cin >> filename;

	process_file(steps, filename);
	calculate_position(steps, depth, horizontal, aim);
	cout << "Results\n============================\nDepth: " << depth << "\nHorizontal: " << horizontal << "\nAim: " << aim << "\nDepth * Horizontal: " << (depth*horizontal) << "\n";

//	for(int i = 0; i < steps.size(); i++){
//		cout << steps.at(i) << endl;
//	}


}



