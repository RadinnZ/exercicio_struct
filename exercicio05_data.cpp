/*
5) Elabore um programa que leia do usuário uma data (crie o tipo data, com dia, mês e ano). Para
a verificação da data, faça uma função que receba a data e retorne verdadeiro se ela é válida e
falso caso contrário. Anos bissextos são dados pelas seguintes regras (segundo o calendário
Gregoriano):
i) De 4 em 4 anos é ano bissexto.
ii) De 100 em 100 anos não é ano bissexto.
iii) De 400 em 400 anos é ano bissexto.
iv) Prevalecem as últimas regras sobre as primeiras.
A título de curiosidade, o ano de 1900 foi o último ano em que a regra ii foi aplicada (não é
bissexto). A próxima vez será em 2100.
*/

#include <iostream>
using namespace std;

struct TData {
    int Dia, Mes, Ano;
};

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

int main() {
    TData data;

    cout << "Dia: ";
    cin >> data.Dia;
    cout << "Mes: ";
    cin >> data.Mes;
    cout << "Ano: ";
    cin >> data.Ano;

    if (dataValida(data))
        cout << "Data valida" << endl;
    else
        cout << "Data invalida" << endl;

    return 0;
}
