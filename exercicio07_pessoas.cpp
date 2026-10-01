/*
7) Faça um programa que, usando struct, armazene o nome e a data de nascimento de até 10
pessoas. O usuário deve informar apenas o nome de cada pessoa; a data de nascimento deve ser
gerada automaticamente pela função abaixo (não peça a data ao usuário):

void CriaData (TData &D) {
    D.Mes = 1 + (rand() % 12);
    D.Ano = 1940 + (rand() % 74);
    D.Dia = 1 + (rand() % 30);
}

O programa deve:
• verificar se a data de nascimento gerada é válida (utilize o algoritmo desenvolvido no
exercício 5);
• listar todos os nomes e respectivas idades — considere um ano de referência informado
pelo usuário para o cálculo da idade;
• listar os nomes das pessoas mais velhas do que uma certa idade (também fornecida pelo
usuário).
Devem ser criadas funções diferentes para cada uma dessas atividades.
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

struct TData {
    int Dia, Mes, Ano;
};

struct TPessoa {
    string nome;
    TData nasc;
};

void CriaData(TData &D) {
    D.Mes = 1 + (rand() % 12);
    D.Ano = 1940 + (rand() % 74);
    D.Dia = 1 + (rand() % 30);
}

bool anoBissexto(int ano) {
    if (ano % 400 == 0) return true;
    if (ano % 100 == 0) return false;
    return ano % 4 == 0;
}

bool dataValida(TData d) {
    if (d.Ano < 1 || d.Mes < 1 || d.Mes > 12 || d.Dia < 1) return false;

    int dias[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (anoBissexto(d.Ano)) dias[1] = 29;

    return d.Dia <= dias[d.Mes - 1];
}

void cadastrarPessoas(TPessoa pessoas[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Nome da pessoa " << i + 1 << ": ";
        getline(cin, pessoas[i].nome);

        do {
            CriaData(pessoas[i].nasc);
        } while (!dataValida(pessoas[i].nasc));
    }
}

void listarIdades(TPessoa pessoas[], int n, int anoRef) {
    for (int i = 0; i < n; i++) {
        int idade = anoRef - pessoas[i].nasc.Ano;
        cout << pessoas[i].nome << " - nascimento: " << pessoas[i].nasc.Dia << "/"
             << pessoas[i].nasc.Mes << "/" << pessoas[i].nasc.Ano
             << " - idade: " << idade << endl;
    }
}

void listarMaisVelhos(TPessoa pessoas[], int n, int anoRef, int idadeMinima) {
    bool achou = false;

    for (int i = 0; i < n; i++) {
        int idade = anoRef - pessoas[i].nasc.Ano;
        if (idade > idadeMinima) {
            cout << pessoas[i].nome << endl;
            achou = true;
        }
    }

    if (!achou)
        cout << "Ninguem com mais de " << idadeMinima << " anos" << endl;
}

int main() {
    srand(time(0));

    TPessoa pessoas[10];
    int n, anoRef, idadeMinima;

    do {
        cout << "Quantas pessoas (ate 10): ";
        cin >> n;
    } while (n < 1 || n > 10);
    cin.ignore();

    cadastrarPessoas(pessoas, n);

    cout << "Ano de referencia: ";
    cin >> anoRef;

    cout << endl << "Nomes e idades" << endl;
    listarIdades(pessoas, n, anoRef);

    cout << endl << "Idade minima: ";
    cin >> idadeMinima;

    cout << endl << "Pessoas mais velhas que " << idadeMinima << " anos" << endl;
    listarMaisVelhos(pessoas, n, anoRef, idadeMinima);

    return 0;
}
