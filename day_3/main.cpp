#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

//gamma is most common
//epsilon is least common
void calculate(vector<string>& report, int& gamma, int& epsilon){

	char zero = '0';
	char one = '1';

//	for(int i=0; i < report.size(); i++){
//		for(int j=0; j<report.at(i).size(); j++){
//
//		}
//	}

	for(int i=0; i < report.at(0).size()-1; i++){
		int total_0s = 0;
		int total_1s = 0;
		for(int j=0; j<report.size(); j++){
			//cout << (report.at(j)).at(i) << endl;
			char curr = (report.at(j)).at(i);
			if(curr == zero){
				//cout << "found 0\n";
				total_0s++;
			}
			else if(curr == one){
				//cout << "found 1\n";
				total_1s++;
			}
		}
		if(total_0s < total_1s){
			gamma = gamma << 1;
			gamma += 0x01;

			epsilon = epsilon << 1;
		}
		else{
			gamma = gamma << 1;
			gamma += 0x00;

			epsilon = epsilon << 1;
			epsilon += 0x01;
		}
	}

	return;
}

void process_data(string filename, vector<string>& report){

	string line;

	ifstream myfile(filename);
	if(myfile.is_open()){
		while(getline(myfile, line)){
			report.push_back(line);
		}
	}
	return;
}

int main(){

	vector<string> report;
	string filename;
	int gamma = 0x00;
	int epsilon = 0x00;

	cout << "Input filename: ";
	cin >> filename;

	process_data(filename, report);
	calculate(report, gamma, epsilon);


	cout << "Gamma: " << gamma << "\nEpsilon: " << epsilon << "\nPower Consumption (Gamma * Epsilon): " << (gamma*epsilon) << "\n";

//	for(int i=0;i<report.size();i++){
//		cout << report.at(i) << endl;
//	}

	return 0;
}
