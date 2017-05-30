/*
Script to identify ORF from fasta files.(Not completely functional)
To compile:
	g++ -std=c++11 identify_orf.cpp -o orf
To run:
	orf filename
*/
#include<iostream>
#include<string>
#include<algorithm>
#include<fstream>
#include<vector>

using namespace std;

struct fasta{
    string header,read;
    vector <size_t> start, stop;    
};


int main(int argc, char *argv[]){
    
    fstream f;

    f.open(argv[1]);
    cout<<"Start Base,Start Frame,Stop Base,Stop Frame,Sequence\n";
    
    while(!f.eof()){	
    fasta tmp;
    
        getline( f,tmp.header ); 
        getline( f,tmp.read );
    // Search for codons and record positions
    	int count = 0;
		while( count < tmp.read.length()- 2 ){
				string codon = tmp.read.substr(count, 3);
    		
    		if ( codon == "ATG" )
    			tmp.start.push_back( count );
    		if( codon == "TAA" || codon == "TAG" || codon == "TGA" )
				tmp.stop.push_back( count );
		count++;
		}
		int i = 0, j = 0;
		while( i < tmp.start.size() ){

			while ( j < tmp.stop.size() ){
				if( tmp.stop[j] >= tmp.start[i] + 90 ){
					cout << tmp.start[i] <<"," << tmp.start[i]%3 <<"," 
						<< tmp.stop[j] <<"," << tmp.stop[j]%3 <<","
						<< tmp.read.substr(tmp.start[i],tmp.stop[j] - tmp.start[i] +3)<< endl;
					i++;
					break;
					}
				j++;	
			}
		}
	}
    f.close();
    return 0;
}


 
