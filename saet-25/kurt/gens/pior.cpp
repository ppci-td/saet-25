#include "testlib.h"

using namespace std;

typedef pair<int,int> ii;
typedef pair<int, ii > i3;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int N = 100000;
    cout << N << endl;

    for(int i = 0; i < N; i++){
      int H = rnd.next(0, 11);
      int M = rnd.next(0, 59);
      int S = rnd.next(0, 59);

      cout << H << " " << M << " " << S << endl;
    }
}
