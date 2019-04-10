
// a(0,0)
// r <=> a(1) += 1
// d <=> a(2) += 1
// end = (2,2)
// (0, 0) (0,1) (0,2) (1, 2) (2,2);
// (0, 0) (1, 0) (1,1) (2,1) (2,2)

#include <utility>

using namespace std;

typedef pair<int, int> coords_t;

void move_right(coords_t& c)
{
    c.first++;
}

void move_down(coords_t& c)
{
    c.second++;
}

int main()
{
    coords_t coords = {0, 0};
    coords_t end_coords = {3,3};

    while (coords != end_coords)
    {
        move_right(coords);
    }

    return 0;
}