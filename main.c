#include "./headers/utils.h"

int main(){
    srand(time(NULL));

    MatrizDesenho matriz;

    int num_figuras = 0;
    int controle_switch = 0;
    int controle_while = 0;

    printf("\n");
    printf("PROGRAMA GERADOR DE OBRA DE ARTE:\n");
    printf("=================================\n");

    while (controle_while == 0){
        printf("Escolha o tipo de figura basica a ser usada para criar a obra:\n");
        printf("1 - asterisco simples\n");
        printf("2 - simbolo de soma com asteriscos.\n");
        printf("3 - letra X com asteriscos.\n");
        printf("4 - figuras aleatorias\n");

        printf("5 - ver obra de arte criativa\n");

        printf("6 - encerrar o programa\n");

        printf("\n");
    
        scanf("%d", &controle_switch);

        switch (controle_switch)
        {
        case 1:
            printf("Digite a quantidade de figuras desejadas:\n");
            scanf("%d", &num_figuras);

            if (VerificaQntdValida(&num_figuras) == 0){
                break;
            }

            InicalizaMatriz(&matriz);

            GeraAsterisco(&matriz, num_figuras, 1, lsup_j);

            ImprimeMatriz(&matriz);

            break;

        case 2:
            printf("Digite a quantidade de figuras desejadas:\n");
            scanf("%d", &num_figuras);

            if (VerificaQntdValida(&num_figuras) == 0){
                break;
            }

            InicalizaMatriz(&matriz);

            GeraEstrela(&matriz, num_figuras, 1, lsup_j);

            ImprimeMatriz(&matriz);

            break;

        case 3:
            printf("Digite a quantidade de figuras desejadas:\n");
            scanf("%d", &num_figuras);

            if (VerificaQntdValida(&num_figuras) == 0){
                break;
            }

            InicalizaMatriz(&matriz);

            GeraX(&matriz, num_figuras, 1, lsup_j);

            ImprimeMatriz(&matriz);

            break;

        case 4:
            printf("Digite a quantidade de figuras desejadas:\n");
            scanf("%d", &num_figuras);

            if (VerificaQntdValida(&num_figuras) == 0){
                break;
            }

            InicalizaMatriz(&matriz);

            GeraFigurasAleatorias(&matriz, num_figuras, 1, lsup_j);

            ImprimeMatriz(&matriz);

            break;

        case 5:
            printf("As figuras agora serao espelhadas!\n");
            printf("Digite a quantidade de figuras desejadas:\n");

            scanf("%d", &num_figuras);

            if (VerificaQntdValida(&num_figuras) == 0){
                break;
            }

            InicalizaMatriz(&matriz);

            GeraEspelhos(&matriz, num_figuras);

            ImprimeMatriz(&matriz);

            break;

        case 6:
            controle_while++;
            break;
        
        default:
            break;
        }
    }
}
