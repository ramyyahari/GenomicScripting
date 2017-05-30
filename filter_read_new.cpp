/*
Extracting reads from Stacks output
This was used to identify reads that belong to certain popoulation using flags
The identifiers on line 35, 37, 39, 41 were based on the names given to stacks for the population map.
Output: Line numbers of matching Loci
If you'd prefer the reads instead of line numbers, uncomment line 49 and comment line 53
Change input file name on line 29
Compile:
	g++ -std=c++11 filter_read_new.cpp -o filter_stacks
Run:
	./filter_stacks
*/
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

struct flags{
    bool stac,sweet,bing,kim,glory,brk;
};

int main(){

    flags header[1200000];
    string header_temp;
    string read;
    int n=0; 

    fstream f;
    f.open( "batch_2.fa" );
    
    while(!f.eof()){
    	getline( f , header_temp );
    	getline( f , read ); 
		
        size_t pos_CLocus = header_temp.find( "CLocus_" , 0 ) + 7;
 		size_t pos_CLocus_end = header_temp.find( "_" , pos_CLocus );
		int index = stoi( header_temp.substr ( pos_CLocus, pos_CLocus_end - pos_CLocus + 1) );		         
		
        if(header_temp.find("Bing")+1)
            header[index].bing = true;
        else if(header_temp.find("Glory")+1)
            header[index].glory = true;
        else if(header_temp.find("Staccato")+1)
            header[index].stac = true;
        else if(header_temp.find("Sweetheart")+1)
            header[index].sweet = true;
        else
            header[index].kim = true;	
	    
       if(header[index].stac && header[index].sweet && header[index].bing && header[index].glory && header[index].kim && !header[index].brk){
          //cout << header_temp << endl << read << endl;    
          header[index].brk= true;
       }
       n++;
     cout<<"\nline number" << n;
    
    }

	f.close();    
   return 0;
}
