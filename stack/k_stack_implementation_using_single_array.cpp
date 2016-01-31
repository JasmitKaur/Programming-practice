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

class k_stack {
    private:
        int n;
        int k;
        int *a;
        int *top;
        int *next;
        int free;
    public:
        k_stack(int n1, int k1);
        void push(int sn, int data);
        int pop(int sn);
        bool is_full_s(int sn);
        bool is_empty_s(int sn);
        void print();
};

k_stack::k_stack(int n1, int k1)
{
    int i;

    n = n1;
    k = k1;

    free = 0;

    a = new int[n];
    top = new int[k];
    for (i = 0; i < k; ++i)
        top[i] = -1;

    next = new int[n];
    for (i = 0; i < n-1; ++i)
        next[i] = i+1;

    next[n-1] = -1;
}

bool k_stack::is_full_s(int sn)
{
    return (free == -1);
}

bool k_stack::is_empty_s(int sn)
{
    return (top[sn] == -1);
}

void k_stack::push(int sn, int data)
{
    if (is_full_s(sn)) {
        cout << "Stack overflow\n";
        return;
    }

    int i = free;
    free = next[i];
    next[i] = top[sn];
    top[sn] = i;
    a[i] = data;
}

int k_stack::pop(int sn)
{
    if (is_empty_s(sn)) {
        cout << "Stack underflow\n";
        return -1;
    }

    int data = a[top[sn]];
    int i = top[sn];
    top[sn] = next[i];
    next[i] = free;
    free = i;
    return data;
}

void k_stack::print()
{
    int i;

    cout << "data array: ";
    for(i = 0; i < n; ++i)
        cout << a[i] << " ";
    cout << endl;

    cout << "next array: ";
    for(i = 0; i < n; ++i)
        cout << next[i] << " ";
    cout << endl;

    cout << "top array: ";
    for(i = 0; i < k; ++i)
        cout << top[i] << " ";
    cout << endl;

    cout << "free: " << free << endl;
}

//problem: implement k stacks using an array of size n
int main ()
{
    int k = 3, n = 10;
    k_stack ks(n, k);

    // Let us put some items in stack number 2
    ks.push(2, 15);
    ks.push(2, 45);

    // Let us put some items in stack number 1
    ks.push(1, 17);
    ks.push(1, 49);
    ks.push(1, 39);

    // Let us put some items in stack number 0
    ks.push(0, 11);
    ks.push(0, 9);
    ks.push(0, 7);

    ks.print();

    cout << "Popped element from stack 2 is " << ks.pop(2) << endl;
    cout << "Popped element from stack 1 is " << ks.pop(1) << endl;
    cout << "Popped element from stack 0 is " << ks.pop(0) << endl;

    ks.print();

    return 0;
}

