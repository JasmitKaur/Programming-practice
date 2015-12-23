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
using namespace std;


typedef enum {
    North = 'N',
    South = 'S',
    West = 'W',
    East = 'E'
}direction;


std::string doesCircleExist(std::string commands)
{
    int x = 0 , y = 0;

    direction cur_direction = North;
    int commandLen = commands.length();
    int maxRadValue = 0;
    float radius = 0;
    int iterations = 4;

    while (iterations > 0) {
        int index = 0;
        while (index != commandLen) {
            if (commands[index] == 'L' || commands[index] == 'R') {
                if (cur_direction == North) {
                    if (commands[index] == 'L') {
                        cur_direction = West;
                    }else if (commands[index] == 'R')
                        cur_direction = East;
                }else if (cur_direction == South) {
                    if (commands[index] == 'L') {
                        cur_direction = East;
                    }else if (commands[index] == 'R')
                        cur_direction = West;
                }else if (cur_direction == West) {
                    if (commands[index] == 'L') {
                        cur_direction = South;
                    }else if (commands[index] == 'R')
                        cur_direction = North;
                }else  if (cur_direction == East) {
                    if (commands[index] == 'L') {
                        cur_direction = North;
                    }else if (commands[index] == 'R')
                        cur_direction = South;
                }
            }else {
                if (cur_direction == North) {
                    y += 1;
                }else if (cur_direction == South){
                    y -= 1;
                }else if (cur_direction == West){
                    x -= 1;
                }else if (cur_direction == East)
                    x += 1;
            }
            index++;
            int tempVal = x*x + y*y;
            if (tempVal > maxRadValue) {
                maxRadValue = tempVal;
            }
        }
        iterations--;
    }

    if (x == 0 && y == 0) {
        radius = sqrt(maxRadValue);
        if (radius >= 0) {
            return "YES";
        }
    }
    return "NO";

}

int main()
{
    cout << doesCircleExist("GRGL") <<endl;
    return 0;
}
