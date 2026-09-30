#include <iostream>
#include <vector>

using namespace std;

void modifyVector(vector<int>& _integerVector) {
    for (auto& item : _integerVector) {
        if (item % 2 == 0)
        {
            item = item * item ;
        }
    }

}

void print (vector<int>& _integerVector) {
    for (auto& item : _integerVector) {
        cout << item << " ";
    }
    cout << endl;
}
/*
int main()
{
    std::cout << "Hello World!\n";
    vector<int> integerVector = { 10, 20, 31, 43, 5, 6 };

    cout << "listenin ilk hali : " << endl;

    print(integerVector);
    
    modifyVector(integerVector);

    cout << "listenin son hali : " << endl;

    print(integerVector);

}

*/
