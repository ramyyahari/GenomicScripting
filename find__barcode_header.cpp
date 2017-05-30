/*
Script to identify barcodes in header from fastq files
To compile: 
    g++ -std=c++11 -o header_barode_fastq
To run:
    header_barcode_fastq filename
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

string process_header(string header){
    size_t pos = header.find("_",0)+1 ;
    pos = header.find("_",pos);
}

int main(int argv, char *argc[])
{
    string temp;

    fstream f;
    f.open(argc[1]);
    
    while(!f.eof()){	
        getline(f,temp); 
        int i=0;
            
        if(temp[0]=='@'){
            size_t pos = temp.find("_",0)+1 ;
            pos = temp.find("_",pos) +1  ;
            size_t pos2 = temp.find("_",pos);
            cout << temp.substr(pos, pos2-pos);     
        }    
            
    }
    f.close();
    return 0;
}


 
