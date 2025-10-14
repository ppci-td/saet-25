#include "testlib.h"

using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int N = rnd.next(2, 1000);
    int M = rnd.next(1, 2000);
    int Q = rnd.next(1, 1000);
    cout << N << " " << M << " " << Q << endl;

    for(int i = 0; i < M; i++){
        int X = rnd.next(1, N);
        int Y = rnd.next(1, N);
        while(X == Y) int Y = rnd.next(1, N); //caminho até ele mesmo
        int D = rnd.next(1, 1000000000);
        double H = rnd.next(0, 10);
        cout <<  X << " " << Y << " " << D << " " << H << endl;
    }

    for(int i = 0; i < Q; i++){
        int Q = rnd.next(1, Q);
        cout << Q << endl;
    }
}