#include "./headers/utils.h"

int main(){
    srand(time(NULL));

    MatrizDesenho matriz;

    int num_figuras = 0;
    int controle = 0;

    printf("\n");
    printf("PROGRAMA GERADOR DE OBRA DE ARTE:\n");
    printf("=================================\n");
    printf("Escolha o tipo de figura basica a ser usada para criar a obra:\n");
    printf("1 - asterisco simples\n");
    printf("2 - simbolo de soma com asteriscos.\n");
    printf("3 - letra X com asteriscos.\n");
    printf("4 - figuras aleatorias\n");
    printf("\n");
    
    scanf("%d", &controle);

    switch (controle)
    {
    case 1:
        printf("Digite a quantidade de figuras desejadas:\n");
        scanf("%d", &num_figuras);

        if (VerificaQntdValida(&num_figuras) == 0){
            break;
        }

        InicalizaMatriz(&matriz);

        GeraAsterisco(&matriz, num_figuras);

        ImprimeMatriz(&matriz);

        break;

    case 2:
        printf("Digite a quantidade de figuras desejadas:\n");
        scanf("%d", &num_figuras);

        if (VerificaQntdValida(&num_figuras) == 0){
            break;
        }

        InicalizaMatriz(&matriz);

        GeraEstrela(&matriz, num_figuras);

        ImprimeMatriz(&matriz);

        break;

    case 3:
        printf("Digite a quantidade de figuras desejadas:\n");
        scanf("%d", &num_figuras);

        if (VerificaQntdValida(&num_figuras) == 0){
            break;
        }

        InicalizaMatriz(&matriz);

        GeraX(&matriz, num_figuras);

        ImprimeMatriz(&matriz);

        break;

    case 4:
        printf("Digite a quantidade de figuras desejadas:\n");
        scanf("%d", &num_figuras);

        if (VerificaQntdValida(&num_figuras) == 0){
            break;
        }

        InicalizaMatriz(&matriz);

        GeraFigurasAleatorias(&matriz, num_figuras);

        ImprimeMatriz(&matriz);

        break;
    
    default:
        break;
    }
}
