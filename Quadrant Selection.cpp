#include <stdio.h>
using namespace std;

int xcoor, ycoor;

int main() {
    scanf("%d %d", &xcoor, &ycoor);
    if (xcoor > 0 && ycoor > 0) return 0 * printf("%d\n", 1);
    else if (xcoor < 0 && ycoor > 0) return 0 * printf("%d\n", 2);
    else if (xcoor < 0 && ycoor < 0) return 0 * printf("%d\n", 3);
    else if (xcoor > 0 && ycoor < 0) return 0 * printf("%d\n", 4);
}
