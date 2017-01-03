#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> array_left_rotation(vector<int> a, int n, int k) {
    
    vector<int> temp;
    //int j=0;
    for(int i=n-k;i<n;i++)
        temp.push_back(a[i]);
    a.erase(a.end()-k,a.end());
    //int b=temp.begin(),e=temp.end();
    a.insert(0,temp.begin(),temp.end());
    return a;
}

int main(){
    int n;
    int k;
    cin >> n >> k;
    vector<int> a(n);
    for(int a_i = 0;a_i < n;a_i++){
        cin >> a[a_i];
    }
    vector<int> output = array_left_rotation(a, n, k);
    for(int i = 0; i < n;i++)
        cout << output[i] << " ";
    cout << endl;
    return 0;
}
