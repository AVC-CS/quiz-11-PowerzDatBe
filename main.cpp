#include "main.hpp"

int main()
{
	string filename = "allstates.txt";
	string state, name, MFName;
	char gen;
	int year, cnt;
	ifstream ifs;
	int count;
	char delimiter = ',';

	count = rewritesplitwords(filename, delimiter);

	ifs.open("split.txt");
	while (ifs >> state >> gen >> year >> name >> cnt)
		cout << state << "\t" << gen << "\t" << year << "\t" << name << "\t" << cnt << endl;
	cout << "the total number of lines is " << count << endl;

	MFName = MFN("IN", 2018);
	cout << "The Most frequently used name in IN, 2018 " << MFName << endl;
	MFName = MFN("DE", 2018);
	cout << "The Most frequently used name in DE, 2018 " << MFName << endl;
}
