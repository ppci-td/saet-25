#include "testlib.h"

using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int N = 10000;
    cout << N << endl;

    int cnt = 0;

    // ganha 12 no primeiro dia
    cout << 12 << " " << 0 << endl;

    for(int i = 1; i < N; i++){
        int C = rnd.next(1, 100);
        // mantem 12
        cout << C << " " << C << endl;
    }
}
