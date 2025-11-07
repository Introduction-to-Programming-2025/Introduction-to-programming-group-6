#include <iostream>
using namespace std;

int main() {
    size_t n;
    cin >> n;

    double x[50000], y[50000];
    for (size_t i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    // the rectangle
    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    // the circle
    double xc, yc, r;
    cin >> xc >> yc >> r;

    size_t inCircle = 0;
    size_t inRect = 0;
    size_t inBoth = 0;

    for (size_t i = 0; i < n; i++) {
        double dist = (x[i] - xc) * (x[i] - xc) + (y[i] - yc) * (y[i] - yc);
        bool circle = dist <= r * r;

        bool rect = x[i] >= x1 && x[i] <= x2 && y[i] <= y1 && y[i] >= y2;

        if (circle) inCircle++;
        if (rect) inRect++;
        if (circle && rect) inBoth++;
    }

    cout << inCircle << endl;
    cout << inRect << endl;
    cout << inBoth << endl;

    return 0;
}
