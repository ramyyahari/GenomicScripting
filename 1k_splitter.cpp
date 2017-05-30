/*
Script to filter fastq reads with certain inline barcodes(found at the start of the read)
To modify barcodes add or remove them from line 31
    Eg. To add more barcodes add 
        if(barcode=="TTCGTGATTC"||barcode=="TTGGAGTGTC"||barcode=="TTGGCATCTC" || barcode="TTTTTTTTTT" )
        to remove barcode
        if(barcode=="TTCGTGATTC"||barcode=="TTGGAGTGTC")
The current code looks for barcodes of base 10 to modify that change line 33 
    Eg. If I wanted to look for barcodes of length 8
        string barcode=read.substr(0,8)    
Compile the code:  "g++ 1k_splitter.cpp -o splitter"
To run: "./splitter name_and_location_file_to_process"
*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

using namespace std;


int main(int argc, char * argv[]) {
    fstream f,f1;
    string header,read,qscore,temp;
    int count=0;

    f.open(argv[1]);
    
        
    while(!f.eof()){

    	getline(f,header);
    	getline(f,read);
        getline(f,temp);
        getline(f,qscore);
        string tmp=header.substr(header.length()-2,2);
        string barcode=read.substr(0,10);
            

        if(barcode=="TTCGTGATTC"||barcode=="TTGGAGTGTC"||barcode=="TTGGCATCTC")
            count++;
    cout<<count<<endl;
    }
    cout<<count;
    f.close();
    
    return 0;
}
