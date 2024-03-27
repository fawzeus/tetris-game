#include <vector>
const int NBWIDTH=17,NBHEIGHT=20;
const int WIDTH = NBWIDTH*18+200,HEIGHT=NBHEIGHT*18+200;
// Define the tetris shapes in a 4x4 grid
const std::vector<std::vector<std::pair<int, int>>> shapes = {
    // Shape 1: Square
    {
        {0, 0}, {0, 1},
        {1, 0}, {1, 1}
    },
    // Shape 2: Line
    {
        {2, 0}, {2, 1}, {2, 2}, {2, 3}
    },
    // Shape 3: L
    {
        {0, 0}, {0, 1}, {0, 2},
        {1, 0}
    },
    // Shape 4: Reverse L
    {
        {0, 0},
        {1, 0},
        {2, 0}, {2, 1}
    },
    // Shape 5: T
    {
        {0, 0}, {0, 1}, {0, 2},
                {1, 1}
    },
    // Shape 6: S
    {
        {0, 1}, {0, 2},
        {1, 0}, {1, 1}
    },
    // Shape 7: Z
    {
        {0, 0}, {0, 1},
        {1, 1}, {1, 2}
    }
};

enum class Direction{
    Left,
    Right,
    UP,
    Down
};