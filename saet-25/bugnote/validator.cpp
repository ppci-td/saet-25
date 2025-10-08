#include "rbx.h"
#include "testlib.h"
#include "assert.h"

using namespace std;

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);

    int N = inf.readInt(1, 2000, "N");
    inf.readSpace();
    int Q = inf.readInt(1, 2000, "Q");
    inf.readEoln();

    set<string> unicos;
    for (int i = 0; i < N; i++) {
        string S = inf.readToken();
        assert(unicos.find(S) == unicos.end());
        unicos.insert(S);
        inf.readSpace();
        int linhas = inf.readInt(1, 100000, "linhas");
        inf.readEoln();
    }

    for (int i = 0; i < Q; i++) {
        string T = inf.readToken();
        inf.readSpace();
        int linha = inf.readInt(1, 120000, "linha_bugnote");
        inf.readEoln();
    }

    inf.readEof();
}
