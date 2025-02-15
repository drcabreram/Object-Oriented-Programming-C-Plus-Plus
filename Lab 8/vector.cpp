#include <iostream>
#include <vector>

using namespace std;

void printMemVec(const vector<int>& v) {
    cout << "Vector – Each int is worth " << sizeof(v[0]) << " bytes\n";
    for (size_t i = 0; i < v.size(); i++) {
        cout << "Value: " << v[i] << " at Memory Location: " << &v[i] << endl;
    }
}

void incVecBy10(vector<int>& v) {
    for (size_t i = 0; i < v.size(); i++) {
        v[i] += 10;
    }
}

int main() {
    const int SIZE = 5;
    vector<int> vec;

    for (int i = 0; i < SIZE; i++) {
        vec.push_back(100 + i);
    }

    cout << "Before Increment---------\n";
    printMemVec(vec);
    incVecBy10(vec);
    cout << "After Increment----------\n";
    printMemVec(vec);

    vec.pop_back();
    cout << "After Pop-----------\n";
    printMemVec(vec);

    vec.push_back(101);
    vec.push_back(102);

    cout << "After Push-----------\n";
    printMemVec(vec);

    return 0;
}

