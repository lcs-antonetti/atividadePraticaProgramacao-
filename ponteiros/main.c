#include <stdio.h>
#include <stdlib.h>

void ex_1();
void ex_2();
void ex_3();
void ex_4();
void swapN(int* x, int* y);
void ex_5();
void organizeN(int* a, int* b);
void ex_6();
int soma_dobro(int* a, int* b);
void ex_7();
void Soma_A(int* a, int* b);
void ex_8();
void ex_9();
void ex_10();
void ex_11();
void ex_12();
int sort_arr(int arr[]);
void quebra_linha();

int main()
{
    //quebra_linha();
    //ex_1();
    //quebra_linha();
    //ex_2();
    //quebra_linha();
    //ex_3();
    //quebra_linha();
    //ex_4();
    //quebra_linha();
    //ex_5();
    //quebra_linha();
    //ex_6();
    //quebra_linha()
    //ex_7();
    //quebra_linha();
    //ex_8();
    //quebra_linha();
    //ex_9();
    //quebra_linha();
    //ex_10();
    //quebra_linha();
    //ex_11();
    //quebra_linha();
    ex_12();
    quebra_linha();

    return 0;
}

void quebra_linha()
{
    printf("\n<-------------------------------------------------------------------------------------------------->\n");
}

void ex_1()
{
    int inteiro = 5;
    float real = 2.75;
    char carac = 'c';

    int* ptr = &inteiro;
    float* ptr_1 = &real;
    char* ptr_2 = &carac;

    printf("%d\n", *ptr);
    printf("%.2f\n", *ptr_1);
    printf("%c\n", *ptr_2);

    *ptr = 7;
    *ptr_1 = 4.75;
    *ptr_2 = 'h';

    printf("\n%d\n", *ptr);
    printf("%.2f\n", *ptr_1);
    printf("%c", *ptr_2);
}

void ex_2()
{
    int n1;
    int n2;

    int* ptr = &n1;
    int* ptr_1 = &n2;

    printf ("%p", ptr);
    printf ("\n%p", ptr_1);

    if(ptr > ptr_1)
    {
        printf("\nMaior endereco: %p", ptr);
    }
    else
    {
        printf("\nMaior endereco: %p", ptr_1);
    }
}

void ex_3()
{
    int n1;
    int n2;

    printf("Digite o primeiro numero: \n");
    scanf("%d", &n1);
    printf("Digite o segundo numero: \n");
    scanf("%d", &n2);

    int* ptr_0 = &n1;
    int* ptr_1 = &n2;

    printf("\n");
    printf("%p\n", ptr_0);
    printf("%p\n", ptr_1);

    if(ptr_0 > ptr_1)
    {
        printf("%d", *ptr_0);
    }
    else
    {
        printf("%d", *ptr_1);
    }
}

void ex_4()
{
    int n1;
    int n2;

    printf("Digite o primeiro numero: \n");
    scanf("%d", &n1);
    printf("Digite o segundo numero: \n");
    scanf("%d", &n2);

    swapN(&n1, &n2);

    printf("numero ordenados %d / %d\n", n2, n1);
    printf("numeros invertidos %d / %d", n1, n2);


}

void swapN(int* x, int* y)
{
    int z = *x;
    *x = *y;
    *y = z;

}

void ex_5()
{
    int n1;
    int n2;

    printf("digite o primeiro numero: ");
    scanf("%d", &n1);
    printf("digite o segundo numero: ");
    scanf("%d", &n2);

    organizeN(&n1, &n2);

    printf("maior: %d\n", n1);
    printf("Menor: %d", n2);
}

void organizeN(int* a, int *b)
{
    if(*a < *b)
    {
        int c = *a;
        *a = *b;
        *b = c;
    }
}

void ex_6()
{
    int n1;
    int n2;

    printf("digite o primeiro numero: ");
    scanf("%d", &n1);
    printf("digite o segundo numero: ");
    scanf("%d", &n2);

    printf("soma do dobro dos numeros: %d", soma_dobro(&n1, &n2));

}

int soma_dobro(int* a, int* b)
{
    *a = *a*2;
    *b = *b*2;

    printf("n1: %d\n", *a);
    printf("n2: %d\n", *b);

    int soma = *a + *b;

    return soma;
}

void ex_7()
{
    int n1;
    int n2;

    printf("digite o primeiro numero: ");
    scanf("%d", &n1);
    printf("digite o segundo numero: ");
    scanf("%d", &n2);

    printf("A: %d\n", n1);
    printf("B: %d\n", n2);

    Soma_A(&n1, &n2);

    printf("A + B = %d\n", n1);
}

void Soma_A(int* a, int* b)
{
    *a = *a + *b;
}

void ex_8()
{
    float arr[10] = {1.0, 1.25, 1.5, 1.75, 2.0, 2.25, 2.5, 2.75, 3.0, 3.25};
    float* ptr = arr;

    for(int i = 0; i < 10; i++)
    {
        printf("endereço %d: %p\n", i + 1, ptr + i);
    }
}

void ex_9()
{
    float arr [3][3] = {1.0, 1.25, 1.5, 1.75, 2.0, 2.25, 2.5, 2.75, 3.0};
    float* ptr = &arr[0][0];

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            printf("endereço %d x %d: %p | valor: %f\n", i + 1, j + 1, (void*)(ptr + i * 3 + j), *(ptr + i * 3 + j));
        }
    }
}

void ex_10()
{
    int arr[5];

    for(int i = 0; i < 5; i++)
    {
        printf("%d: \n", i + 1);
        scanf("%d", &arr[i]);
    }

    int* ptr = arr;

    for(int i = 0; i < 5; i++)
    {
        printf("dobro %d numero: %d\n", i + 1, (2 * *(ptr + i)));
    }
}

void ex_11()
{
    int arr[5];

    for(int i = 0; i < 5; i++)
    {
        printf("%d: \n", i + 1);
        scanf("%d", &arr[i]);
    }

    int* ptr = arr;

    for(int i = 0; i < 5; i++)
    {
        if( arr[i] % 2 == 0)
        {
            printf("endereco %d numero par: %p\n", arr[i], (ptr + i));
        }
    }
}

void ex_12()
{
    int arr[3];

    for(int i = 0; i < 3; i++)
    {
        printf("Digite um numero: ");
        scanf("%d", &arr[i]);
    }

    printf("retorno da funcao: %d", sort_arr(arr));

}

int sort_arr(int arr[])
{
    int temp;

    if (arr[0] == arr[1] && arr[0] == arr[2])
    {
        return 1;
    }else
    {
        if (arr[0] > arr[1])
        {
            temp = arr[0];
            arr[0] = arr[1];
            arr[1] = temp;
        }
        if (arr[1] > arr[2])
        {
            temp = arr[1];
            arr[1] = arr[2];
            arr[2] = temp;
        }
        if (arr[0] > arr[1])
        {
            temp = arr[0];
            arr[0] = arr[1];
            arr[1] = temp;
        }

        printf("%d %d %d\n", arr[0], arr[1], arr[2]);

        return 0;

    }
}

