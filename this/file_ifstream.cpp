#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    ifstream fin("test1.txt");
    if(!fin)
        cout << "flie open fail" << endl;
    string s;
    int a;
    double f;
    fin >> s >> a >> f;
    cout << s << " " << a << " " << f << " " << endl;
    string line;
    //fin.ignore();
    while(getline(fin, line))
    {
        cout << line << endl;
    }
    return 0;
}