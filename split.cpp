
#include <iostream>
#include <fstream>
#include <string>

#ifdef _WIN32
#include <windows.h>
#define SYSERROR()  GetLastError()
#else
#include <errno.h>
#define SYSERROR()  errno
#endif

using namespace std;

int main(int argc, char* argv[])
{
    //cout << argv[1]<<endl ;
    fstream f;
    f.open(argv[1]);
    string input=argv[1],col,row,score,read;
    size_t pos=input.find("_"),pos2,pos3;
    string name=input.substr(0,pos);
    name[input.find("-")]='_';
    //cout<<name;
    row="rowlist_"+name;
    col="collist_"+name;
    score="scorelist_"+name;
    
    ofstream rlist(row.c_str()),clist(col.c_str()),slist(score.c_str());
    
    if(rlist.is_open()&&clist.is_open()&&slist.is_open())
    {
   
    	while(!f.eof())
    	{
    		getline(f,read);
    		pos=read.find(",");
    		rlist << read.substr(0,pos)<<endl;
    		pos2=read.find_last_of(",");
    		clist << read.substr(pos+1,pos2-pos-1)<<endl;
    		if(!read.length())
    			break;
    		slist << read.substr(pos2+1,read.length()-pos2)<<endl;
    	}
    rlist.flush();
    clist.flush();
    slist.flush();
    rlist.close();
    clist.close();
    slist.close();
    }
    else
    {
        std::cerr<<"Failed to open file : "<<SYSERROR()<<std::endl;
        return -1;
    }

    f.close();
    return 0;
}

	