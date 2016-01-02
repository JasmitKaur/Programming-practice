
#include "math.h"
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <climits>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <string>
#include <stdlib.h>

using namespace std;

void print_array(char *a, int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i];
    cout << endl;
}

void reverser_string(char *a, int start, int end)
{
    if (!*a)
        return;

    while (start < end) {
        a[start] ^= a[end];
        a[end] ^= a[start];
        a[start] ^= a[end];
        start++;
        end--;
    }
}

void reverse_words_in_sentence(char *sent, int n)
{
    if (!sent)
        return;

    //reverse complete string
    reverser_string(sent, 0, n-1);
    int s = 0, e = 0;
    for (int i = 0; i <= n; i++) {
        if (sent[i] == ' ' || i == n) {
            e = i - 1;
            reverser_string(sent, s, e);
            s = i + 1;
        }
    }
}

int main ()
{
    char a[6] = {'j', 'a', 's', 'm', 'i', 't'};

    cout << "Given array: ";
    print_array(a, 6);

    reverser_string(a, 0, 5);
    cout << "After reversal: ";
    print_array(a, 6);


    char sentence[14] = {'H', 'a', 'p', 'p', 'y', ' ', 'N', 'e', 'w', ' ', 'Y', 'e', 'a', 'r'};
    cout << "Given sentence: ";
    print_array(sentence, 14);

    reverse_words_in_sentence(sentence, 14);
    cout << "After sentence reversal: ";
    print_array(sentence, 14);

    return 0;
}
