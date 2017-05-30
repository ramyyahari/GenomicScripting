/*
Script to identify barcodes(in header) from fastq files.
Modify lines 39, 40, 41 to add or remove barcodes, also change respective variables in line 43.
Modify input filename on line 26
To compile:
    g++ -std=c++11 fastq_barcode_splitter.cpp -o fastq_barcode_splitter
To run:
    fastq_barcode_splitter
*/
#include<iostream>
#include<string>
#include<algorithm>
#include<fstream>
#include<vector>

using namespace std;

struct fastq_read{
public:
    string header,read,quality_score;
};

int main(){
    fastq_read read;
    string tmp;
    fstream f;
    f.open("GA0030-2013.single.fastq");
    
    while(!f.eof()){	
        //read header
        getline(f,tmp); 
        read.header=tmp;  
        //read the actual read
        getline(f,tmp);
        read.read=tmp;
        //read +
        getline(f,tmp);
        //read quality score
        getline(f,tmp);
        read.quality_score=tmp;
        if(tmp.empty())
            continue;
        
        size_t barcode_1=read.read.find("TTCGTGATTC");
        size_t barcode_2=read.read.find("TTGGAGTGTC");
        size_t barcode_3=read.read.find("TTGGCATCTC");
        
            if(barcode_1==0||barcode_2==0||barcode_3==0)
            cout<<read.header<<"\n"<<read.read<<"\n+\n"<<read.quality_score<<endl;
    }
    f.close(); 
}


 
