#include "testlib.h"

using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int N = rnd.next(1,100000);
    int X = rnd.next(0,256);

    string S;
    
    for(int i = 0; i < N; i++){
        int aux = rnd.next(0,3);
        if(aux == 0) S.push_back('A');
        if(aux == 1) S.push_back('C');
        if(aux == 2) S.push_back('G');
        if(aux == 3) S.push_back('T');
    }

    cout << N << " " << X << endl << S << endl;

}