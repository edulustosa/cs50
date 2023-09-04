#include <stdio.h>

void selection_sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                int aux = arr[i];
                arr[i] = arr[j];
                arr[j] = aux;
            }
        }
    }
}

int binary_search(int arr[], int n, int alvo)
{
    int esquerda = 0;
    int direita = n - 1;

    while (esquerda <= direita)
    {
        int meio = (esquerda + direita) / 2;

        if (arr[meio] == alvo)
        {
            return meio;
        }
        else if (arr[meio] < alvo)
        {
            esquerda = meio + 1;
        }
        else
        {
            direita = meio - 1;
        }
    }
    
    return -1;
}

int main(void)
{
    int arr[] = 
    {
        12, 5, 1, 0, 22,
        14, 6, 3, 9, 17,
        11, 10, 8, 27, 32
    };
    int tamanho = sizeof(arr) / sizeof(arr[0]);

    printf("Array original: ");
    for (int i = 0; i < tamanho; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    selection_sort(arr, tamanho);

    printf("Array ordenado: ");
    for (int i = 0; i < tamanho; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int alvo;
    printf("Informe um alvo: ");
    scanf("%d", &alvo);

    int resultado = binary_search(arr, tamanho, alvo);

    if (resultado != -1) 
    {
        printf("Encontrou o numero %d na posicao %d.\n", alvo, resultado);
    } 
    else 
    {
        printf("Numero %d nao encontrado.\n", alvo);
    }

    return 0;
}
