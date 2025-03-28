#ifndef FS_H
#define FS_H

const int width = 1280;
const int height = 720;
const int cell = 4;
const int gridx = width / cell, gridy = height / cell;

typedef struct
{
    int num;
    bool solid;
    bool canMove;
} material;

const material Sand = {1, true, true};
const material Water = {2, false, true};
const material Wall = {3, true, false};

void game(int **xy);
void alloc(int **xy);
void free(int **xy);
void syncMaterials(int **xy);

#endif