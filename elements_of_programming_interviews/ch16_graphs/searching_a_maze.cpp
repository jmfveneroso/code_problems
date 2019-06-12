// =====================================================
// Book: Elements of programming interviews
// Problem 16.1: Searching a maze
// =====================================================

#include <iostream>
#include <vector>
#include <array>

using namespace std;

class Point {
 public:
  int x, y;

  bool operator==(const Point& b) const {
    return x == b.x && y == b.y;
  }
};

bool is_viable(
  Point& cur, vector< vector<int> >& maze
) {
  if (cur.x < 0 || cur.x >= maze.size()) return false;
  if (cur.y < 0 || cur.y >= maze[cur.x].size()) return false;
  return maze[cur.x][cur.y] == 0;
}

bool maze_search(
  Point& cur, Point& destination, vector< vector<int> >& maze, vector<Point>& path
) {
  const array< array<int, 2>, 4 > step = { 0, 1, 0, -1, 1, 0, -1, 0 };

  maze[cur.x][cur.y] = 1;
  if (cur == destination) return true;

  for (const array<int, 2>& s : step) {
    Point next { cur.x + s[0], cur.y + s[1] };
    if (!is_viable(next, maze)) continue;
 
    path.push_back(next);
    if (maze_search(next, destination, maze, path))
      return true;
    path.pop_back();
  }
  return false;
}

int main() {
  vector< vector<int> > maze1 = {
    {0, 0, 0, 0},
    {0, 1, 0, 0},
    {0, 1, 0, 0},
    {0, 1, 0, 0},
  };  

  vector< vector<int> > maze2 = {
    {0, 1, 0, 0},
    {0, 1, 0, 0},
    {0, 1, 0, 0},
    {0, 1, 0, 0},
  };  

  Point entrance { 3, 0 };
  Point exit { 0, 3 };

  vector<Point> path;
  cout << maze_search(entrance, exit, maze1, path) << " should be true." << endl;
  for (auto& p : path) cout << "(" << p.x << ", " << p.y << ")" << endl;

  cout << maze_search(entrance, exit, maze2, path) << " should be false." << endl;
  return 0;
}
