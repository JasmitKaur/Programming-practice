#include<iostream>
#include<string>

using namespace std;

int main()
{
    string list1;
    cin >> list1;
    list1 = 'A' + list1;
    int last = list1.length()-1;

    while(list1.at(0) < list1.at(last)) {
        int j = last-1;
        if (j>0 && list1.at(j) >= list1.at(j+1)) {
            j--;
        } else if (j==0) {
            break;
        }

        int l = last;
        if (list1.at(j) >= list1.at(last)) {
            l--;
        }
        swap(list1.at(j), list1.at(l));
        int k = j+1;
        l = last;
        while (k<l) {
            swap(list1.at(k), list1.at(l));
            k++;
            l--;
        }
     cout << list1.substr(1, last) << endl;
    }
}
