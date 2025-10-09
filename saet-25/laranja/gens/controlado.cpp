// random, mas ficando entre 0 e 12
#include "testlib.h"

using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int N = rnd.next(1, 10000);
    cout << N << endl;

    int cnt = 0;

    for(int i = 0; i < N; i++){
        int G, C;
        do {
            G = rnd.next(1, 12);
            C = rnd.next(1, 12);
        } while (cnt + G - C > 12 or cnt + G - C < 0);
        cnt += (G-C);
        cout << G << " " << C << endl;       
    }
}
