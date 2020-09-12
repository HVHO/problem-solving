#include <string>
#include <vector>

using namespace std;

// floyd-washell problem
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    long long answer = 0;
    
    // mat init
    vector<vector<long long>> mat(n+1);
    for(int i = 1; i <= n; i++)
        mat[i]= vector<long long>(n+1, 1e9);
    for(int i = 1; i <= n; i++)
        mat[i][i] = 0;
    
    // fill mat
    for(int i = 0; i < fares.size(); i++) {
        mat[fares[i][0]][fares[i][1]] = fares[i][2];
        mat[fares[i][1]][fares[i][0]] = fares[i][2];
    }
    
    // floyd-washell
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                if(mat[i][k] + mat[k][j] < mat[i][j]) {
                    mat[i][j] = mat[i][k] + mat[k][j];
                    mat[j][i] = mat[i][k] + mat[k][j];
                }
                    
    
    // find way
    answer = 2e9;
    
    for(int i = 1; i <= n; i++) {
        if(answer > (mat[s][i] + mat[i][a] + mat[i][b]))
            answer = mat[s][i] + mat[i][a] + mat[i][b];
    }
    
    return (int)answer;
}