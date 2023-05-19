/*
O objetivo de entrada do nosso programa é receber um número inteiro que determina a quantidade
de palavras que vão ser compostas no nosso dicionário. Após ter recebido todas as palavras
reservadas respeitando a quantidade proposta, temos a senha digitada pelo usuário.
O objetivo da saída é verificar se a senha digitada pelo usuário satisfaz todas as condições propostas
pelo desafio.

Nome: Pedro Spido Tanimoto Celestino, RA: 2760482121039
Nome: Michel Jose da Silva, RA: 2760482221025      
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int oitoCaracteres(char senha[50], int tam)
{
    //Se o tamanho da senha for menor que oito é retornado para a função o valor 0, se não é retornado o valor 1
    if (strlen(senha) < tam)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int palindromo(char senha[50])
{

    int i, j, tam = 0;
    char senhaInv[50];

    //É feito a cópia do tamanho da senha atual
    while (senha[tam] != '\0' && tam < 50)
    {
        tam++;
    }

    senhaInv[tam] = '\0';
    j = tam - 1;
    i = 0;
    //O vetor senhaInv[] a senha invertida
    while (i < tam)
    {
        senhaInv[j] = senha[i];
        i++;
        j--;
    }

    //Função strcmp que compara se a senha invertida é igual a senha digitada
    int palindromo = strcmp(senhaInv, senha);

    //Se a senha for um palindromo é retornado 1 para a função, se não é retornado 0
    if (palindromo == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int letraMinuscula(char senha[50])
{
    int temMinuscula = 0;

    //Dentro de um Loop é verificado se cada letra da senha é uma letra maiuscula, utilizando a função islower().
    for (int i = 0; i < strlen(senha); i++)
    {
        if (islower(senha[i]))
        {
            temMinuscula = 1;
        }
    }

    //Se a senha possuir uma letra maiuscula é retornado 1 para a função, se não é retornado 0.
    if (temMinuscula)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int numero(char senha[50])
{
    int temNumero = 0;

    //Dentro de um Loop é verificado se cada letra da senha é um numero, utilizando a função isdigit().
    for (int i = 0; i < strlen(senha); i++)
    {
        if (isdigit(senha[i]))
        {
            temNumero = 1;
        }
    }

    //Se a senha possuir um numero é retornado 1 para a função, se não é retornado 0.
    if (temNumero)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int letraMaiuscula(char senha[50])
{
    int temMaiuscula = 0;

    //Dentro de um Loop é verificado se cada letra da senha é uma letra maiuscula, utilizando a função isupper().
    for (int i = 0; i < strlen(senha); i++)
    {
        if (isupper(senha[i]))
        {
            temMaiuscula = 1;
        }
    }

    //Se a senha possuir uma letra maiuscula é retornado 1 para a função, se não é retornado 0.
    if (temMaiuscula)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int simbolos(char senha[50])
{
    //Dentro de um Loop é verificado se alguma letra da nossa senha possui um dos símbolos propostos. 
    //Se possuir é retornado 1 para a função e ela acaba, se nenhuma letra possuir o simbolo é retornado 0.
    for (int i = 0; i < strlen(senha); i++)
    {
        if (senha[i] == '!' || senha[i] == '?' || senha[i] == '#' ||
            senha[i] == '@' || senha[i] == '$')
        {
            return 1;
        }
    }
    return 0;
}

int palavraReservada(char senha[50], char dicionario[50][20], int n)
{

    //Percorre todas as palavras do dicionario
    for (int i = 0; i < n; i++)
    {
        //Converte a palavra do dicionario para minusculas
        char palavra_minuscula[20];
        strcpy(palavra_minuscula, dicionario[i]);
        for (int j = 0; j < strlen(palavra_minuscula); j++)
        {
            palavra_minuscula[j] = tolower(palavra_minuscula[j]);
        }

        //Converte a senha para minuscula
        char senha_minuscula[50];
        strcpy(senha_minuscula, senha);
        for (int j = 0; j < strlen(senha); j++)
        {
            senha_minuscula[j] = tolower(senha_minuscula[j]);
        }

        //Verifica se a senha contem a palavra do dicionario, ignorando maiusculas e minusculas
        if (strstr(senha_minuscula, palavra_minuscula) != NULL)
        {
            return 1;
        }
    }

    //Se nao encontrou nenhuma palavra do dicionario na senha, retorna 0 
    return 0;
}

void verificaSenha(int possuiOitoCaracteres, int possuiLetraMaiuscula,
                   int possuiLetraMinuscula, int possuiNumero,
                   int ehUmPalindromo, int possuiSimbolos, int possuiPalavraReservada)
{
    //Um if para cada condição proposta
    if (!possuiOitoCaracteres)
    {
        printf("A senha deve conter pelo menos oito caracteres\n");
    }
    if (ehUmPalindromo)
    {
        printf("A senha e um Palindromo\n");
    }
    if (!possuiLetraMinuscula)
    {
        printf("A senha deve conter pelo menos uma letra minuscula\n");
    }
    if (!possuiNumero)
    {
        printf("A senha deve conter pelo menos um numero\n");
    }
    if (!possuiLetraMaiuscula)
    {
        printf("A senha deve conter pelo menos uma letra maiuscula\n");
    }
    if (!possuiSimbolos)
    {
        printf("A senha deve conter pelo menos um simbolo\n");
    }
    if (possuiPalavraReservada)
    {
        printf("A senha nao pode conter palavras reservadas\n");
    }
    if (possuiLetraMaiuscula && possuiLetraMinuscula && possuiNumero && possuiOitoCaracteres &&
        !ehUmPalindromo && possuiSimbolos && !possuiPalavraReservada)
    {
        printf("A senha esta ok!");
    }
}

int main()
{

    //O programa pede para ser digitado a quantidade de palavras reservadas desejadas (int)
    printf("\nDigite a quantidade de palavras reservadas: ");
    int n;
    scanf("%d", &n);

    printf("\nDigite as palavras reservadas: \n");
    // le as palavras do dicionario
    char dicionario[50][20];
    for (int i = 0; i < n; i++)
    {
        scanf("%s", dicionario[i]);
    }

    printf("\nDigite sua senha: ");
    // le a senha do usuario
    char senha[50];
    int tam = 8;
    scanf("%s", senha);

    //chamada de todas as funções com variaveis que recebem respectivamente um valor booleano para cada situação
    int possuiOitoCaracteres = oitoCaracteres(senha, tam);
    int ehUmPalindromo = palindromo(senha);
    int possuiLetraMinuscula = letraMinuscula(senha);
    int possuiNumero = numero(senha);
    int possuiLetraMaiuscula = letraMaiuscula(senha);
    int possuiSimbolos = simbolos(senha);
    int possuiPalavraReservada = palavraReservada(senha, dicionario, n);

    //Função que verifica as condições para a situação atual da senha
    verificaSenha(possuiOitoCaracteres, possuiLetraMaiuscula,
                  possuiLetraMinuscula, possuiNumero,
                  ehUmPalindromo, possuiSimbolos, possuiPalavraReservada);
}