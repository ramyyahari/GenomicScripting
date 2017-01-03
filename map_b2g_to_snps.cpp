#include <iostream>
#include <string.h>
#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

int main(){

	//int clocus[100000]={0};
    vector <string> clocus; 
    fstream f;
    string tmp;
    size_t pos_start;
    
    f.open("TRAPseq_GvS_b2g_table.csv");
    getline(f,tmp);        
    
    clocus.resize(100000);

    while(!f.eof()){	
        getline(f,tmp); 
        if ( !tmp.find("_",0))
        	break;
        pos_start=tmp.find("_",0);
        size_t pos_end=tmp.find("_",pos_start+1);
        //cout<< tmp.substr(pos_start+1,pos_end-pos_start-1)<<endl;
    	clocus[stoi(tmp.substr(pos_start+1,pos_end-pos_start-1))] = tmp;
    	//cout << clocus[stoi(tmp.substr(pos_start+1,pos_end-pos_start-1))];
        int c = f.peek();
    	if ( c == EOF)
    		break;
	}
    f.close(); 
    
    //cout<<"indexed\n";
    
    f.open("TRAPseq_Glory_v_staccato_SNPs.csv");
    getline(f,tmp);        
    cout<<tmp<<endl;
    while(!f.eof()){	
        getline(f,tmp); 
        pos_start=tmp.find("_",0);
        if( clocus[stoi(tmp.substr(0,pos_start))] != "\0" )
        cout<< tmp<<","<<clocus[stoi(tmp.substr(0,pos_start))] << endl;
    }
    f.close(); 
    
    return 0;
}