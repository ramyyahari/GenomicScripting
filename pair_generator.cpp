/*
Script to convert given fastq file into a set of paired-end reads by labeling every second read's header as a pair.
To compile:
    g++ -std=c++11 pair_generator.cpp -o pair_generator
To run:
    ./pair_generator input_filename
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;


int main(int argv, char *argc[])
{
    string header;
    string read;
    string quality_score;
    string temp;
    string prev_header;

    fstream f;
    f.open(argc[1]);
    
    getline(f,header); 
    getline(f,read);
    getline(f,temp);
    getline(f,quality_score);
    
    prev_header = header;
    
    while(!f.eof()){	
        
        getline(f,header); 
        getline(f,read);
        getline(f,temp);
        getline(f,quality_score);
        
        prev_header = prev_header.replace( prev_header.find("1:Y"), 1 , "2");
        cout<< prev_header 
        		<< endl << read
            << endl << "+"
        		<< endl << quality_score << endl;
      prev_header = header;
    }
    
    f.close();
    return 0;
}


 
