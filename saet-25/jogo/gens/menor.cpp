#include "testlib.h"

using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int N = 3;
    cout << N << endl;

    for(int i = 0; i < N; i++){
        int D = rnd.next(1,30);
        int M = rnd.next(1,12);
        int A = rnd.next(1,5);
        cout << D << " " << M << " " << A << endl;       
    }
}