#include "testlib.h"

using namespace std;

typedef pair<int,int> ii;
typedef pair<int, ii > i3;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int N = 100000;
    cout << N << endl;

    set<i3> S;
    for(int i = 0; i < N; i++){
        int D,M,A;
        do {
            D = rnd.next(1,30);
            M = rnd.next(1,12);
            A = rnd.next(99999990,1000000000);
        } while (S.count(i3(A,ii(M,D))));
        S.insert(i3(A,ii(M,D)));
    }
    // imprimir em ordem cronologica
    for (auto w : S)
        cout << w.second.second << " " << w.second.first << " " << w.first << endl;       
}
