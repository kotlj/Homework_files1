
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int choise = 1;
    cout << "choose task:\n1 - start word symb count;\n2 - '1' into '0' and reverse;\n";
    cin >> choise;
    if (choise == 1)
    {
        int size;
        int counter = 0;
        char* s;
        char user;
        ifstream file;
        file.open("Test.txt");
        file.seekg(0, ios_base::end);
        size = file.tellg();
        file.seekg(0, ios_base::beg);
        s = new char[size];
        file.get(s, size);
        file.close();
        cout << "enter symbol:\n";
        cin >> user;
        for (int i = 0; i < size - 1; i++)
        {
            if (i == 0 && s[i] == user && s[i + 1] != ' ' || s[i] == user && s[i - 1] == ' ' && s[i] + 1 != ' ')
            {
                counter++;
            }
        }
        cout << counter << "\n";
        delete[] s;
    }
    else if (choise == 2)
    {
        int size;
        char* s;
        ifstream fileR;
        ofstream fileW;
        fileR.open("Read.txt");
        fileR.seekg(0, ios_base::end);
        size = fileR.tellg();
        fileR.seekg(0, ios_base::beg);
        s = new char[size];
        fileR.get(s, size);
        fileR.close();
        for (int i = 0; i < size; i++)
        {
            if (s[i] == '1')
            {
                s[i] = '0';
                continue;
            }
            else if (s[i] == '0')
            {
                s[i] = '1';
            }
        }
        fileW.open("Write.txt");
        fileW << s << "\n";
        fileW.close();
    }
}
