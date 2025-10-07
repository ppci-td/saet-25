#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

string gerarNome(int minTam = 3, int maxTam = 8) {
    int tam = rnd.next(minTam, maxTam);
    string nome;
    nome.reserve(tam);
    nome.push_back((char)('A' + rnd.next(0, 25))); 
    for (int i = 1; i < tam; i++)
        nome.push_back((char)('a' + rnd.next(0, 25)));
    return nome;
}

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int N = rnd.next(1, 2000);
    int Q = rnd.next(1, 2000);
    cout << N << " " << Q << endl;


    set<string> usados;
    vector<string> nomes;
    for (int i = 0; i < N; i++) {
        string nome;
        do {
            nome = gerarNome();
        } while (usados.count(nome));
        usados.insert(nome);
        nomes.push_back(nome);

        int linhas = rnd.next(1, 100000);
        cout << nome << " " << linhas << endl;
    }

    for (int i = 0; i < Q; i++) {
        bool nomeValido = rnd.next(0, 1); 
        string nome;
        if (nomeValido || nomes.empty()) {
            nome = nomes[rnd.next(0, N - 1)];
        } else {
            nome = gerarNome(); 
        }

        int linha = rnd.next(1, 120000); 
        cout << nome << " " << linha << endl;
    }

    return 0;
}