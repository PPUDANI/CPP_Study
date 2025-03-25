#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

void Permutation(string numbers)
{
    do{
        cout << numbers << endl;
    } while (std::next_permutation(numbers.begin(), numbers.end()));
}

int main() {
    cout << "\n<1234>" << endl;
    Permutation("1234");
}
