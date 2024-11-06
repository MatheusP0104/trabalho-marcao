#include <stdio.h>
#include <limits.h> // lib para usar INT_MAX

float notasAlunos[30][2], medias[30][2], contagem;
int alunos_cadastrados = 0;

int registrarAlunos() // Yanko
{
    int i, j, id = 0;
    float nota = 0, soma;
    
    // Título da aplicação no console
    printf("\t\t\t\t -----------------------------------\n");
    printf("\t\t\t\t | Gerenciador de Notas dos alunos |\n");
    printf("\t\t\t\t -----------------------------------\n");
    
    printf("\t\tEscreva o Id e 3 notas para cada aluno, no final o relatorio sera mostrado. \n\n");
    
    // Laço de repetição para cadastro de até 30 alunos
    for (i = 0; i < 30; i++) {
        printf("\nEscreva o id do aluno: (Digite um numero negativo pra encerrar)\n");
        scanf("%d", &id);

        if(id < 1){ // Verifica se a condição de encerramento foi cumprida
            printf("Cadastro encerrado!\n");
            return -1; // Encerra o programa (poderia ser return 0 tmb)     
        }else{
            int k;
            for(k = 0; k < alunos_cadastrados; k++){
                if(notasAlunos[k][0] == id){
                    printf("O Id digitado ja existe, por favor tente novamente.\n");
                    i--;
                    break;
        }
    }

    if(k == alunos_cadastrados){
        soma = 0;
        for (j = 0; j < 3; j++) { // Laço de repetição para as 3 notas
                printf("\nEscreva a %d nota: ", j + 1);
                scanf("%f", &nota);

                soma += nota;

                

            }
            notasAlunos[alunos_cadastrados][0] = id;
            notasAlunos[alunos_cadastrados][1] = soma;
            alunos_cadastrados++;
        }
    }
        
    }
    
}

void calcularMedia() {
    for (int i = 0; i < alunos_cadastrados; i++) {
        if (notasAlunos[i][0] != 0) {
            medias[i][0] = notasAlunos[i][0]; // Armazena o ID
            medias[i][1] = notasAlunos[i][1] / 3.0; // Calcula e armazena a média
        }
    }

    // Impressão das médias
    for (int i = 0; i < alunos_cadastrados; i++) {
        printf("Aluno %d - Media: %.2f\n", (int)medias[i][0], medias[i][1]);
    }
}

int MaiorNota(float vetorAlunos[30][2], int contador_alunos){
    float Maior_Nota = 0;

     for(int i = 0; i < contador_alunos; i++) {
        if(vetorAlunos[i][1] > Maior_Nota) {
            Maior_Nota = vetorAlunos[i][1];
        }
    }

    return Maior_Nota;
}

// int ExibirNota(float vetorAlunos[30][2]) {
//     , Menor_Nota = vetorAlunos[0][1];

//     for(int i = 0; i < alunos_cadastrados; i++) {
//         if(vetorAlunos[i][0] != 0) {
//             if(vetorAlunos[i][1] > Maior_Nota) {
//                 Maior_Nota = vetorAlunos[i][1];
//             }

//             if(vetorAlunos[i][1] < Menor_Nota) {
//                 Menor_Nota = vetorAlunos[i][1];
//             }
//         }
//     }

//     printf("\nA maior nota eh: %.2f\n", Maior_Nota);
//     printf("A menor nota eh: %.2f\n", Menor_Nota);
// }

    int main()
{
   registrarAlunos();
   calcularMedia();
   printf("A maior nota eh: %.2f", MaiorNota(notasAlunos, alunos_cadastrados));
   
}