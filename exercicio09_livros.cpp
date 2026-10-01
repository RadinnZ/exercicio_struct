/*
9) Crie uma struct chamada Livro, com os campos titulo (string), autor (string) e paginas (int).
Declare um vetor de 15 Livros e escreva uma função que recebe o vetor preenchido e um número
de páginas, e retorna a quantidade de livros com mais páginas do que o valor informado.
*/

#include <iostream>
#include <string>
using namespace std;

struct Livro {
    string titulo;
    string autor;
    int paginas;
};

int contarLivros(Livro livros[], int n, int paginas) {
    int cont = 0;

    for (int i = 0; i < n; i++) {
        if (livros[i].paginas > paginas)
            cont++;
    }

    return cont;
}

int main() {
    const int N = 15;
    Livro livros[N];

    for (int i = 0; i < N; i++) {
        cout << "Livro " << i + 1 << endl;
        cout << "Titulo: ";
        getline(cin, livros[i].titulo);
        cout << "Autor: ";
        getline(cin, livros[i].autor);
        cout << "Paginas: ";
        cin >> livros[i].paginas;
        cin.ignore();
    }

    int paginas;
    cout << "Numero de paginas: ";
    cin >> paginas;

    cout << "Livros com mais de " << paginas << " paginas: "
         << contarLivros(livros, N, paginas) << endl;

    return 0;
}
