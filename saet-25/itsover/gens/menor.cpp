#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int N = 1;
    cout << N << endl;
    int M = 1;
    cout << M << endl;
    cout << rnd.next(1, 5) << endl;
}
