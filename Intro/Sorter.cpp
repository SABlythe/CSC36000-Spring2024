#include <iostream>
#include <list>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[])
{
    list<int> myNumbers;

    for (int index=1; index<argc; index++)
    {
        myNumbers.push_back( atoi(argv[index]) );
    }

    for (int val : myNumbers)
    {
        cout << val << " ";
    }
    cout << endl << " ======= "<< endl;

    // sort the numbers here!!!
    myNumbers.sort();

    for (int val : myNumbers)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
