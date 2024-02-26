#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
int rewritesplitwords(string, char);
string MFN(string stname, int thisyear);

struct Name {
    string stname;
    string gender;
    int year;
    string bname;
    int count;
} ;

int rewritesplitwords(string x, char delim) {
    ifstream ifs;
    ofstream ofs;
    string line, buff;
    stringstream ss;
    Name name;
    int fcnt;
    int cntr = 0;

    ifs.open(x);
    if(!ifs) {
        cerr << "FILE COOKED" << endl;
        exit(0);
    }

    ofs.open("split.txt");
    if(!ofs) {
        cerr << "FILE COOKED" << endl;
        exit(0);
    }

    while(getline(ifs, line)) {
        ss << line;
        fcnt = 0;
        while(getline(ss, buff, delim)) {
            switch(fcnt) {
                case 0:
                    name.stname = buff;
                    break;
                case 1:
                    name.gender = buff;
                    break;
                case 2:
                    name.year = stoi(buff);
                    break;
                case 3:
                    name.bname = buff;
                    break;
                case 4:
                    name.count = stoi(buff);
                    break;
                default:
                    cerr << "FCNT ERROR" << endl;
                    break;
            }
            fcnt++;
        }
        ofs << name.stname << "\t" << name.gender << "\t" << name.year << "\t" << name.bname << "\t" << name.count << endl;
        ss.clear();
        cntr++;
    }

    ifs.close();
    ofs.close();

    return cntr;
}

string MFN(string stname, int thisyear) {
    ifstream ifs;
    Name name;
    string maxName;
    int i, maxCnt;

    ifs.open("split.txt");
    if(!ifs) {
        cerr << "FILE COOKED" << endl;
        exit(0);
    }

    i = 0; maxCnt = 0;
    while(ifs >> name.stname >> name.gender >> name.year >> name.bname >> name.count) {
        if((name.stname == stname) && (name.year == thisyear)) {
            if(i == 0) {
                maxName = name.bname;
            }
            else if(maxCnt < name.count) {
                maxName = name.bname;
                maxCnt = name.count;
            }
        }
        i++;
    }

    ifs.close();

    return maxName;
}