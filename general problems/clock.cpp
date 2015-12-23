#include<iostream>
#include<vector>

using namespace std;

#define MAX 2000000000
#define MAX_INT 1000000

vector<int> gearlist(int n, int d, vector<int> r, vector<int> c) {
    vector<int> ret;

    for ( int i=0; i<n; i++) {
        int l_min = MAX;
        int l_i = MAX_INT;
        for ( int j=0; j<n; j++) {
            if (r[i] + r[j] >= d) {
                if ( (c[j] < l_min) || (c[j] == l_min && r[j] > r[l_i]) ) {
                    l_min = c[j];
                    l_i = j;
                }
            }
        }
        if (l_min == MAX || l_i == MAX_INT) {
            ret.push_back(0);
        } else {
            ret.push_back(l_i+1);
        }
    }
    return ret;
}

int main()
{
    vector<int> list1;
    vector<int> list2;
    list1.push_back(1);
    list1.push_back(3);
    list1.push_back(6);
    list1.push_back(2);
    list1.push_back(5);

    list2.push_back(5);
    list2.push_back(6);
    list2.push_back(4);
    list2.push_back(3);
    list2.push_back(4);

    vector<int> ans = gearlist(5, 8, list1, list2);
    for ( int j=0; j<5; j++)
        cout << ans[j] << " ";
}
