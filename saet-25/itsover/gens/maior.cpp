#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int N = 1000;
    cout << N << endl;

    for (int i = 0; i < N; i++) {
       
        int M = 1000;
        cout << M << endl;

        for (int j = 0; j < M; j++) {
            if(j == M-1) cout << rnd.next(99900,100000);
            else cout << rnd.next(99900, 100000) << " ";
        }
        cout << endl;
    }
}
