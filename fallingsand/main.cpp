#include <iostream>
#include <SFML/Graphics.hpp>
#include "fs.h"
using namespace std;

void alloc(int **xy)
{
    for (int i = 0; i < gridx; i++)
    {
        xy[i] = new int[gridy];
    }

    for (int i = 0; i < gridx; i++)
    {
        for (int j = 0; j < gridy; j++)
        {
            xy[i][j] = 0;
        }
    }
}

void free(int **xy)
{
    for (int i = 0; i < gridy; i++)
    {
        delete[] xy[i];
    }
    delete[] xy;
}

int main()
{
    int **xy = new int *[gridx];

    alloc(xy);

    game(xy);

    free(xy);

    return 0;
}
