#include <iostream>
#include <algorithm>
#include <vector>
#include <string>


using namespace std;

vector <pair<int,int> > list;
vector< pair<int,int> > dp[22][4][4];

void hanoi(int num, int dep, int via, int arr) {

    // base case

    if(num == 1) {
        list.push_back(pair<int,int>(dep,arr));
        return;
    }

    if(num == 2) {

        /*
        cout << dep << " " << via << endl;
        cout << dep << " " << arr << endl;
        cout << via << " " << arr << endl;
        */
       list.push_back(pair<int,int>(dep,via));
       list.push_back(pair<int,int>(dep,arr));
       list.push_back(pair<int,int>(via,arr));
        
        return;
    }


    // divide and conquer

    /*
    hanoi(num - 1, dep, arr, via);
    cout << dep << " " << via << endl;
    hanoi(num - 1, via, dep, arr);
    */

   vector< pair<int,int> > &temp = dp[num][dep][arr];

   if(!temp.empty()) {
       //cout << "hit!!"<<endl;
        list.insert(list.end(),temp.begin(),temp.end());
   } else {
        int start = list.size();
        hanoi(num - 1, dep, arr, via);
        list.push_back(pair<int,int>(dep,arr));
        hanoi(num - 1, via, dep, arr);

        temp.insert(temp.end(),list.begin() + start, list.end());
   }
   

    return;

}



int main(void) {

    int num;
    cin >> num;

    list.clear();
    hanoi(num, 1, 2, 3);

    cout << list.size() << endl;

    /*
    vector< pair<int,int> >::iterator it = list.begin();
    while(it!=list.end()) cout << (*it).first << " " << (*it++).second << endl;
    */
   for(int i = 0; i < list.size(); i++) {
       //cout << list[i].first << " " << list[i].second << "\n";
       printf("%d %d\n",list[i].first,list[i].second);
   }

    return 0;
}