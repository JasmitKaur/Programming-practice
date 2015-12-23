
#ifndef _STACK_H_
#define _STACK_H_

#include <vector>
#include <iostream>
#include <string>

#define RET_FAIL 1000;


/* for int values */
void push_stack(std::vector<int> *s, int val)
{
    s->push_back(val);
}

int pop_stack(std::vector<int> *s)
{
    if (!s->empty()) {
        int val = s->back();
        s->pop_back();
        return val;
    } else
        return RET_FAIL;
}

void print_stack(std::vector<int> *s)
{
    std::vector<int>::iterator it;
    for (it = s->begin(); it != s->end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

int get_top(std::vector<int> *s)
{
    if (!s->empty())
        return s->back();
    else
        return RET_FAIL;
}


/* for string values */
void push_stack(std::vector<char> *s, char val)
{
    s->push_back(val);
}

char pop_stack(std::vector<char> *s)
{
    if (!s->empty()) {
        char val = s->back();
        s->pop_back();
        return val;
    } else
        return NULL;
}

void print_stack(std::vector<char> *s)
{
    if (!s->empty()) {
        std::vector<char>::iterator it;
        for (it = s->begin(); it != s->end(); it++)
            std::cout << *it << " ";
        std::cout << std::endl;
    }
}

char get_top(std::vector<char> *s)
{
    if (!s->empty())
        return s->back();
    else
        return NULL;
}

#endif // _STACK_H_
