/*
Look at filter_reads_new.cpp
Same as above file, fewer filters.
*/
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    int header[2000000] = { 0 };
    string header_temp;
    string read;

    fstream f;
    f.open( "teest.fa" );
    
    while(!f.eof())
    {
    	getline( f , header_temp );
    	getline( f , read ); 
		
        size_t pos_bing = header_temp.find( "Bing" , 0 ) + 1;    
        size_t pos_sweetheart = header_temp.find( "Sweetheart" , 0 ) + 1;
       
        if( pos_bing || pos_sweetheart )
        	continue;
 		
 		size_t pos_CLocus = header_temp.find( "CLocus_" , 0 ) + 7;
 		size_t pos_CLocus_end = header_temp.find( "_" , pos_CLocus );
		int index = stoi( header_temp.substr ( pos_CLocus, pos_CLocus_end - pos_CLocus + 1) );		         
		
		if( header[index] == 1)
			continue;
		else{
			header[index] = 1;
			cout << header_temp << endl << read << endl;	
		}	
	}
	f.close();
	return 0;
}
