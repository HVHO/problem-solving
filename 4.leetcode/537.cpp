// 537. Complex Number Multiplication


class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        pair<int,int> a,b;
        sscanf(num1.c_str(),"%d+%di",&a.first, &a.second);
        sscanf(num2.c_str(),"%d+%di",&b.first, &b.second);
        
        int real = a.first * b.first - a.second * b.second;
        int img = a.second * b.first + a.first * b.second;
        

        return to_string(real) + "+" + to_string(img) + "i";
    }
};
