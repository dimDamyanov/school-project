#include <iostream>
#include "ArrayList.inl"

using namespace std;

int main() {
    ArrayList<int> a;
    for (int i = 0; i < 10; i++)
        a.push_back(i);
    int c = 8;
    a.insert(4, c);
    for (int i = 0; i < a.size(); i++) {
        cout << a.get(i) << endl;
    }
    a.remove(4);
    for (int i = 0; i < a.size(); i++) {
        cout << a.get(i) << endl;
    }
    return 0;
}