#include <iostream>

using namespace std;

int main() {
    float a, b, c;

    cin >> a >> b >> c;

    const bool is_triangle = (a < b + c) && (b < a + c) && (c < b + a);
    
    cout << is_triangle << endl;
    return 0;
}
