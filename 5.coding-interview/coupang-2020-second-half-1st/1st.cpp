#include <string>
#include <vector>

using namespace std;

int prodofbase(int base, int num) {
    int quot = num;
    int remain = 0;

    int res = 1;

    while(quot) {
        remain = quot%base;
        quot /= base;
        if(remain) res *= remain;
    }

    return res;

}

vector<int> solution(int N) {
    vector<int> answer;

    int res = 0;
    int max = 0;

    for(int i = 2; i < 11; i++) {
        int tmp = prodofbase(i, N);
        if(tmp >= max) {
            max = tmp;
            res = i;
        }
    }

    answer.push_back(res);
    answer.push_back(max);

    return answer;
}
