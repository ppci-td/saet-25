#include "testlib.h"

using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int N = rnd.next(1, 10000);
    cout << N << endl;

    int cnt = 0;

    for(int i = 0; i < N; i++){
        int G = rnd.next(1, 100);
        int C = rnd.next(1, 100);
        cnt += (G-C);
        if(cnt < 0){
            C = 0;
            cnt += (G-C);
        }
        cout << G << " " << C << endl;       
    }
}