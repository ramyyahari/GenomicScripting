#include<iostream>
#include<string>
#include<algorithm>
#include<fstream>
#include<vector>

using namespace std;


int main()
{
    int i=-1,j=0,scaff[100];
    string tmp;
    fstream f;
    f.open("SweetCherry_Bing_09082015.fasta");
    

    while(!f.eof())
    {	
        getline(f,tmp); 
        i++;
        s.push_back(tmp);
        int count=0;
        
        if(tmp[0]=='>')
            scaff[j++]=i;
        while(count<80)
        {
            size_t pos=tmp.find("CATG",count+4);
            if(pos==-1)
                break;
            temp.vpos=i;
            temp.p=pos;
            temp.r1=true;
            temp.r2=false;
            read.push_back(temp);
            count=pos;
        }
        count=0;
       
        while(count<80)
        {
            size_t pos=tmp.find("AATT",count+4);
            if(pos==-1)
                break;
            temp.vpos=i;
            temp.p=pos;
            temp.r1=false;
            temp.r2=true;
            read.push_back(temp);
            count=pos;
        }
        
        
    }
    f.close();
    
    std::sort (read.begin(), read.end(),alpha);
    
    int l=0,counter=0;
    
    for(int j=0;j<read.size();j++)
    {
        if(j==scaff[l])
             l++;
   
        if((read[j].r1==true&&read[j+1].r2==true)||(read[j].r2==true&&read[j+1].r1==true))
        {
		int flag=0;			
            for(int m=read[j].vpos;m<=read[j+1].vpos;m++)
                {
                    size_t pos=s[m].find('N');
                    if(pos!=-1)
                        flag=1;
                }
            if(flag)
                goto cont;
            long start,end;
            start=(read[j].vpos-scaff[l-1]-1)*80+read[j].p;
            end=(read[j+1].vpos-scaff[l-1]-1)*80+read[j+1].p;
            if(read[j].r1==true&&read[j+1].r2==true)    
                cout<<"scaffold"<<l<<",+,"<<start<<","<<end<<",";
            else
                cout<<"scaffold"<<l<<",-,"<<start<<","<<end<<",";
            
            for(int k=read[j].vpos;k<=read[j+1].vpos;k++)
            {
                
                 if(k==read[j].vpos)
                    if(read[j].vpos==read[j+1].vpos)
                    {
                        cout<<s[k].substr(read[j].p,read[j+1].p-read[j].p+4);
                        break;
                    }
                    else
                        cout<<s[k].substr(read[j].p,84-read[j].p);
                        
                else if(k==read[j+1].vpos&&read[j].vpos!=read[j+1].vpos)
                    cout<<s[k].substr(0,read[j+1].p+4);
                else
                    cout<<s[k];
            }      
            cout<<endl<<endl;    
        }
        cont:
        continue;
    }
   cout<<"\nNumber of spilts:"<<counter<<" in "<<l<<" scaffolds";
    return 0;
    
}


 
