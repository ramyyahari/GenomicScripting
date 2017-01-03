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
