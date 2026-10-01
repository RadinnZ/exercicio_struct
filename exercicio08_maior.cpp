/*
8) Escreva uma função template maior que recebe um vetor de N elementos de qualquer tipo
numérico e retorna o maior valor do vetor. Use-a para encontrar a maior nota em um vetor de
notas (float) de uma turma de 30 alunos.
*/

#include <iostream>
using namespace std;

template <typename T>
T maior(T vetor[], int n) {
    T maiorValor = vetor[0];

    for (int i = 1; i < n; i++) {
        if (vetor[i] > maiorValor)
            maiorValor = vetor[i];
    }

    return maiorValor;
}

int main() {
    const int N = 30;
    float notas[N];

    for (int i = 0; i < N; i++) {
        cout << "Nota do aluno " << i + 1 << ": ";
        cin >> notas[i];
    }

    cout << "Maior nota da turma: " << maior(notas, N) << endl;

    return 0;
}
