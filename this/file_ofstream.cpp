#include<iostream>
#include<fstream>

using namespace std;

int main()
{
    ofstream fout("test.txt", ios::app);
    fout << endl << "the words will be appended in the file" << endl;
    fout << "success" << endl;
    fout.close();
    if(!fout)
    {
        cout << "file append fail" << endl;
        return 1;
    }
    return 0;
}