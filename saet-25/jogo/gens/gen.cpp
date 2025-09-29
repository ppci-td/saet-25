#include "testlib.h"

using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int n = rnd.next(3, opt<int>(1));
    cout << n << endl;

    for(int i = 0; i < n; i++){
        int d = rnd.next(1,30);
        int m = rnd.next(1,12);
        int a = rnd.next(1,1e9);
        cout << d << " " << m << " " << a << endl;       
    }
}