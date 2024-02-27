#include <iostream>
#include <iomanip>
#include <vector>
using std::cin, std::cout, std::endl, std::setw;

int main() {
    // pixel data
    std::vector<int> v[15] = {
        {6}, \
        {6, 3}, \
        {6, 4}, \
        {6}, \
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, \
        {6, 2}, \
        {6, 2, 4}, \
        {5, 3, 4}, \
        {5, 3, 3}, \
        {5, 3, 2}, \
        {4, 4, 1}, \
        {4, 4, 6}, \
        {3, 4, 1, 6}, \
        {2, 3, 1, 2, 6}, \
        {1, 8, 1, 1, 1, 1}
    };
    // print
    for (int i = 0; i < 15; ++i) {
        for (int j = 0; j < v[i].size(); ++j) {
            cout << setw(v[i][j]) << "*";
        }
        cout << endl;
    }
    return 0;
}

/*===================

     *
     *  *
     *   *
     *
**************
     * *
     * *   *
    *  *   *
    *  *  *
    *  * *
   *   **
   *   *     *
  *   **     *
 *  ** *     *
*       *****

===================*/