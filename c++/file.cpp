#include<fstream>
#include<iostream>
using namespace std;
int main() {

	ofstream fout;
	ifstream fin;
	fin.open("ÊäÈë.txt");
	fout.open("Êä³ö.txt", ofstream::app);
	int ch1, ch2;
	while(1){
		if (fin.eof())
			break;
		fin >> ch1 >> ch2;
		fout << ch1 + ch2 << endl;

	}
	fin.close();
	fout.close();
	return 0;
}
