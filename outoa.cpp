//
//  main.cpp
//  outoa
//
//  Created by 包雨薇 on 17/6/1.
//  Copyright © 2017年 包雨薇. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(int argc, const char * argv[]) {
    
    string filenm = argv[1];
    string outfnm = argv[2];

    
    ifstream infile;
    ofstream offile;
    infile.open(filenm.c_str());
    if (!infile.is_open()) {
        cout << "error opening infile" << endl;
        exit(1);
    }
    
    offile.open(outfnm.c_str(), std::ios_base::app);
    if (!offile.is_open()) {
        cout << "error opening outfile" << endl;
        exit(1);
    }
    
    string name;
    string seq;
    string coru;
    
    
    while (infile >> coru) {
        if (coru == "C") {
            infile >> name;
            string junk;
            getline(infile, junk);
            getline(infile, seq);
            offile << '>' << name << endl << seq << endl;

        } else {
            string junk;
            getline(infile, junk);
            getline(infile, junk);
        }
        
        
    }

    
    infile.close();
    offile.close();
    return 0;
}
