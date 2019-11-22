#include "game.h"


// # parede, . vazio, 0-4 geladeiras
// # parede, . vazio, 0-4 geladeiras
unsigned char GameMap[MAP_WIDTH][MAP_HEIGHT] = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
    {'#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
    {'#', '.', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '#', '.', '.', '#', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
    {'#', '.', '.', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '.', '#', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
    {'#', '.', '.', '.', '.', '.', '#', '#', '.', '.', '.', '.', '.', '#', '.', '.', '.', '.', '#', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
    {'#', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '.', '.', '#', '.', '.', '.', '.', '#', '.', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '.', '#'},
    {'#', '.', '.', '.', '.', '.', '.', '#', '#', '.', '.', '.', '.', '#', '.', '.', '.', '.', '#', '.', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '.', '#'},
    {'#', '.', '.', '.', '.', '.', '.', '.', '#', '#', '.', '.', '.', '.', '#', '.', '.', '#', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '#'},
    {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#', '#', '.', '.', '.', '#', '.', '.', '#', '.', '.', '.', '.', '.', '.', '.', '#', '#', '.', '.', '.', '.', '#'},
    {'#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#', '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#', '#', '.', '.', '#'},
    {'#', '.', '.', '#', '.', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
    {'#', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
    {'#', '.', '.', '.', '.', '#', '.', '.', '.', '.', '1', '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
    {'#', '.', '.', '.', '.', '.', '#', '.', '.', '#', '#', '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#', '#', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
    {'#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#', '#', '#', '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
    {'#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#', '#', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '#'},
    {'#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '.', '#'},
    {'#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#', '#', '#', '.', '.', '.', '.', '.', '#', '.', '.', '#'},
    {'#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#', '#', '.', '.', '.', '.', '.', '.', '.', '#', '.', '.', '#'},
    {'#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#', '#', '.', '.', '.', '.', '.', '.', '.', '.', '#', '#', '.', '.', '#'},
    {'#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#', '4', '.', '.', '.', '#'},
    {'#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '.', '#'},
    {'#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '#'},
    {'#', '.', '.', '#', '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#', '3', '#', '#', '#', '#', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '#'},
    {'#', '.', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '#', '#', '#', '.', '.', '.', '.', '#', '.', '.', '#'},
    {'#', '.', '.', '.', '2', '#', '#', '.', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '.', '#', '.', '.', '#'},
    {'#', '.', '.', '.', '.', '.', '#', '#', '.', '.', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '#', '.', '.', '#'},
    {'#', '.', '.', '.', '.', '.', '.', '#', '#', '.', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
    {'#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
    {'#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}};