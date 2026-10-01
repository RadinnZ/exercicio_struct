/*
6) Escreva uma função template trocar que recebe dois parâmetros por referência e troca os valores
entre eles, funcionando para qualquer tipo de dado. Use-a tanto para trocar dois valores int
quanto para trocar dois valores do tipo Ponto (da questão 2) — lembre-se de que a struct inteira
pode ser copiada de uma vez com o operador de atribuição.
*/

#include <iostream>
using namespace std;

struct Ponto {
    float x, y;
};

template <typename T>
void trocar(T &a, T &b) {
    T aux = a;
    a = b;
    b = aux;
}

int main() {
    int n1 = 10, n2 = 25;
    cout << "Antes: n1 = " << n1 << " n2 = " << n2 << endl;
    trocar(n1, n2);
    cout << "Depois: n1 = " << n1 << " n2 = " << n2 << endl;

    Ponto p1 = {1.5, 2.0};
    Ponto p2 = {-3.0, 4.5};
    cout << "Antes: p1 = (" << p1.x << ", " << p1.y << ") p2 = (" << p2.x << ", " << p2.y << ")" << endl;
    trocar(p1, p2);
    cout << "Depois: p1 = (" << p1.x << ", " << p1.y << ") p2 = (" << p2.x << ", " << p2.y << ")" << endl;

    return 0;
}
