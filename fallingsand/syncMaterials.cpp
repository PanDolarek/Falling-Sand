#include <iostream>
#include <SFML/Graphics.hpp>
#include "fs.h"
using namespace std;

void syncMaterials(int **xy)
{
    for (int j = gridy; j >= 0; j--)
    {
        for (int i = 0; i < gridx; i++)
        {
            material currentMaterial = {0, false, false};

            if (xy[i][j] == Sand.num)
            {
                currentMaterial = Sand;
            }
            else if (xy[i][j] == Water.num)
            {
                currentMaterial = Water;
            }
            else if (xy[i][j] == Wall.num)
            {
                currentMaterial = Wall;
            }
            else
            {
                continue;
            }

            bool canMoveDown = (xy[i][j + 1] == 0);
            bool canMoveLeft = (xy[i - 1][j] == 0);
            bool canMoveRight = (xy[i + 1][j] == 0);
            bool canMoveDownLeft = (xy[i - 1][j + 1] == 0);
            bool canMoveDownRight = (xy[i + 1][j + 1] == 0);

            if (i > 1 && i + 2 < gridx && j + 1 < gridy)
            {
                if (currentMaterial.canMove)
                {
                    if (canMoveDown)
                    {
                        xy[i][j + 1] = currentMaterial.num;
                        xy[i][j] = 0;
                    }
                    else
                    {
                        if (xy[i][j + 1] == Water.num)
                        {
                            swap(xy[i][j + 1], xy[i][j]);
                        }
                        if (xy[i - 1][j + 1] == Water.num)
                        {
                            swap(xy[i - 1][j + 1], xy[i][j]);
                        }
                        if (xy[i + 1][j + 1] == Water.num)
                        {
                            swap(xy[i + 1][j + 1], xy[i][j]);
                        }
                        if (canMoveDownLeft && canMoveDownRight)
                        {
                            if (rand() % 2 == 0)
                            {
                                xy[i - 1][j + 1] = currentMaterial.num;
                                xy[i][j] = 0;
                            }
                            else
                            {
                                xy[i + 1][j + 1] = currentMaterial.num;
                                xy[i][j] = 0;
                            }
                        }
                        else if (canMoveDownLeft)
                        {
                            xy[i - 1][j + 1] = currentMaterial.num;
                            xy[i][j] = 0;
                        }
                        else if (canMoveDownRight)
                        {
                            xy[i + 1][j + 1] = currentMaterial.num;
                            xy[i][j] = 0;
                        }
                        else if (!currentMaterial.solid)
                        {
                            if (rand() % 2 == 0)
                            {
                                if (canMoveLeft)
                                {
                                    xy[i - 1][j] = currentMaterial.num;
                                    xy[i][j] = 0;
                                }
                                else if (canMoveRight)
                                {
                                    xy[i + 1][j] = currentMaterial.num;
                                    xy[i][j] = 0;
                                }
                            }
                            else
                            {
                                if (canMoveRight)
                                {
                                    xy[i + 1][j] = currentMaterial.num;
                                    xy[i][j] = 0;
                                }
                                else if (canMoveLeft)
                                {
                                    xy[i - 1][j] = currentMaterial.num;
                                    xy[i][j] = 0;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}