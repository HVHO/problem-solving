#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;


int testCase = 0;

string Quard_reverse(string::iterator & str) {

    
    char head = *(str);
    str++;

    //  이미지가 단색인 기저사례
    if(head == 'b' || head == 'w') {
        return string(1,head);
    }

    string upLeft = Quard_reverse(str);
    string upRight = Quard_reverse(str);
    string lowLeft = Quard_reverse(str);
    string lowRight = Quard_reverse(str);

    return string("x" + lowLeft + lowRight + upLeft + upRight);

}


int main(void) {

    int i, j;
    string input;


    cin >> testCase;

    for(i = 0; i < testCase; i++) {
        
        cin >> input;
        string::iterator it = input.begin();

        cout << Quard_reverse(it) << endl;

    }

    return 0;
}