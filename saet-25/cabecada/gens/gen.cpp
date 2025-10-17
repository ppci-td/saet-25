#include "testlib.h"
#include <iomanip>

using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int N = rnd.next(2, 100);
    int M = rnd.next(1, 200);
    int Q = rnd.next(1, 100);
    cout << N << " " << M << " " << Q << endl;

    for(int i = 0; i < M; i++){
        int X = rnd.next(1, N);
        int Y = rnd.next(1, N);
        while(X == Y) Y = rnd.next(1, N); //caminho até ele mesmo
        int D = rnd.next(1, 1000000000);
        int placa = rnd.next(0, 10);
        if (placa==0)
           cout <<  X << " " << Y << " " << D << " " << placa << endl;
        else {
            double H = (double)(rnd.next(0, 1000))/100.0;
            cout <<  X << " " << Y << " " << D << " " << setprecision(2) << H << endl;
        }
    }

    for(int i = 0; i < Q; i++){
        int q = rnd.next(1, N);
        cout << q << endl;
    }
}
