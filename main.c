#include "./headers/utils.h"

int main(){
    srand(time(NULL));

    MatrizDesenho matriz;

    int num_figuras = 0;
    int controle_switch = 0;
    
    int sair = 0;
    int ultima_opcao = 0;
    int ultimo_num_figuras = 0;
    int existe_ultimo_quadro = 0;

    printf("\n");
    printf("PROGRAMA GERADOR DE OBRA DE ARTE:\n");
    printf("=================================\n");

    while (sair == 0){
        printf("\nEscolha o tipo de figura basica a ser usada para criar a obra:\n");

        if (existe_ultimo_quadro){
            printf("\n0 - repetir ultimo quadro\n");
            printf("\n");
        }

        printf("1 - asterisco simples\n");
        printf("2 - simbolo de soma com asteriscos.\n");
        printf("3 - letra X com asteriscos.\n");
        printf("4 - figuras aleatorias\n");

        printf("5 - ver obra de arte criativa\n");

        printf("6 - encerrar o programa\n");

        printf("\n");
    
        scanf("%d", &controle_switch);

        if (controle_switch == 6){
            sair = 1;
            continue;
        }

        int repetindo = 0;

        if (controle_switch == 0){
            if (existe_ultimo_quadro == 0){
                controle_switch = 4;
                printf("\nopcao invalida. ativando geracao de figuras aleatorias\n");
            }
        
            else{
                controle_switch = ultima_opcao;
                num_figuras = ultimo_num_figuras;
                repetindo = 1;
            }
        }

        if (repetindo == 0){
            if ((controle_switch < 1 || controle_switch > 5)){
                controle_switch = 4;
                printf("\nopcao invalida. ativando geracao de figuras aleatorias\n");
            }

            printf("\ndigite a quantidade de figuras desejadas:\n");
            scanf("%d", &num_figuras);

            VerificaQntdValida(&num_figuras);
        }

        InicalizaMatriz(&matriz);

        switch (controle_switch){  
        case 1:
            GeraAsterisco(&matriz, num_figuras, 1, lsup_j);
            break;

        case 2:
            GeraEstrela(&matriz, num_figuras, 1, lsup_j);
            break;

        case 3:
            GeraX(&matriz, num_figuras, 1, lsup_j);
            break;

        case 4:
            GeraFigurasAleatorias(&matriz, num_figuras, 1, lsup_j);
            break;

        case 5:
            printf("\nas figuras agora serao espelhadas!\n");
            GeraEspelhos(&matriz, num_figuras);
            break;
        }

        ImprimeMatriz(&matriz);

        ultima_opcao = controle_switch;
        ultimo_num_figuras = num_figuras;
        existe_ultimo_quadro = 1;
    }
}