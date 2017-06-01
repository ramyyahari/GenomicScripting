/*
Input file has to be a csv file, we assume first line has headers.
To compile: g++ -std=c++11 filter_csv_weights.cpp -o bruce
To run: ./filter_csv_weights filename maximum_peak_size plex_limit
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#ifdef _WIN32
#include <windows.h>
#define SYSERROR()  GetLastError()
#else
#include <errno.h>
#define SYSERROR()  errno
#endif

using namespace std;

class Bucket {
  public:
    string SNP_id;
    float original, product1, product2;  
};

class Split { 
    vector <string> reading;
    vector <Bucket> bucket1, bucket2;
    int peak, plex_limit;
    public:
        Split (string filename, string peak_size, string plex) {
            fstream f;
            string temp;
            f.open(filename);
            getline(f, temp);
            while (!f.eof()) {
                getline(f, temp);
                reading.push_back(temp);
            }
            f.close();   
            peak = stoi(peak_size);
            plex_limit = stoi(plex);         
        }

        void process () {
            Bucket temp;
            for(auto const& value: reading) {

                if(value.empty()) {
                    break;
                }

                if(bucket1.size() == 30 || bucket2.size() == 30) {
                    display_set();
                }

                size_t pos = value.find(',');
                temp.SNP_id = value.substr(0, pos);
                size_t pos2 = value.find(',', pos+1);
                temp.original = stof(value.substr(pos+1, pos2));
                size_t pos3 = value.find(',', pos2+1);
                temp.product1 = stof(value.substr(pos2+1, pos3));
                temp.product2 = stof(value.substr(pos3+1, value.length()));

                //cout << temp.SNP_id << "\n" << temp.original <<"\n" << temp.product1 <<"\n" << temp.product2;  
                bool decide = check_insert(temp);                
                if(decide) {
                    bucket1.push_back(temp);
                } else {
                    bucket2.push_back(temp);
                }   
            }
            display_set();
        } 

        bool check_insert (Bucket new_value) {
            
            if(bucket1.size() == 0) {
                return true;
            }
            for(auto const& value: bucket1) {
                bool check1 = (((new_value.product1 >= value.product1 + 16) || (new_value.product1 <= value.product1 - 16)) 
                                && ((new_value.product1 >= value.product2 + 16) || (new_value.product1 <= value.product2 - 16))
                                && ((new_value.product1 >= value.original + 16) || (new_value.product1 <= value.original - 16)));
                bool check2 = (((new_value.product2 >= value.product1 + 16) || (new_value.product2 <= value.product1 - 16)) 
                                && ((new_value.product2 >= value.product2 + 16) || (new_value.product2 <= value.product2 - 16))
                                && ((new_value.product2 >= value.original + 16) || (new_value.product2 <= value.original - 16)));
                if(check1 && check2) {
                    return true;
                } 
            }
            return false;
        }
        void display_set () {
            cout<<"\nSet1";
            for(auto const& value: bucket1) {
                cout<< endl << value.SNP_id << "," << value.original << "," << value.product1 << "," << value.product2; 
            }
            cout<<"\nSet2";
            for(auto const& value: bucket2) {
                cout<< endl << value.SNP_id << "," << value.original << "," << value.product1 << "," << value.product2; 
            }
            bucket1.clear();
            bucket2.clear();
        }
};

int main(int argc, char* argv[])
{
    cout << "Reading from file: " << argv[1] << endl
         << "Maximum peak separation: " << argv[2] << endl
         << "Maximum number of SNPs per plex: " << argv[3] << endl;
    Split file (argv[1], argv[2], argv[3]);
    file.process();
    return 0;
}    
