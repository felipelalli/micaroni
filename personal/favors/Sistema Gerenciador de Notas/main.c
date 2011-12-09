#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Maximos */
#define MAX_ALUNOS 50
#define MAX_NOME_ALUNO 30

/* Sexos */
#define MASC 'M'
#define FEM 'F'

#define TRUE 1
#define FALSE 0

/*
 * Funcao principal, onde tudo comeca
 */
int main()
{
    /* Tipo data que sera usado no nascimento do aluno */
    typedef struct
    {
        int dia;
        int mes;
        int ano;
    } tipo_data;

    /* Tipo nota */
    typedef struct
    {
        int portugues;
        int matematica;
        int fisica;
        int quimica;
        int ingles;
    } tipo_nota_por_materia;

    /* Tipo aluno */
    typedef struct
    {
        char nome[MAX_NOME_ALUNO];
        tipo_data data_nascimento;
        char sexo;
        int idade;
        tipo_nota_por_materia notas[4]; /* Cada posicao no vetor eh um bimestre */
    } tipo_aluno;

    /* Vetor de alunos + tamanho do vetor */
    tipo_aluno alunos[MAX_ALUNOS];
    int quantos_alunos = 0;

    int sair = FALSE; /* Para controlar a saida do loop principal */
    int exibir_menu = TRUE; /* Para decidir se exibe as opcoes novamente ou nao */

    /* Le de arquivo, se disponivel */
    FILE *arquivo = fopen("alunos.txt", "r");

    if (arquivo != NULL) {
        int terminou = FALSE;

        while (!terminou) {
            int i = quantos_alunos;

            int read = fscanf(arquivo, "%s\n%02d/%02d/%02d;%d;%c;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d\n",
                   alunos[i].nome,
                   &alunos[i].data_nascimento.dia,
                   &alunos[i].data_nascimento.mes,
                   &alunos[i].data_nascimento.ano,
                   &alunos[i].idade,
                   &alunos[i].sexo,
                   &alunos[i].notas[0].portugues, /* 1o bimestre */
                   &alunos[i].notas[0].matematica,
                   &alunos[i].notas[0].fisica,
                   &alunos[i].notas[0].quimica,
                   &alunos[i].notas[0].ingles,
                   &alunos[i].notas[1].portugues, /* 2o bimestre */
                   &alunos[i].notas[1].matematica,
                   &alunos[i].notas[1].fisica,
                   &alunos[i].notas[1].quimica,
                   &alunos[i].notas[1].ingles,
                   &alunos[i].notas[2].portugues, /* 3o bimestre */
                   &alunos[i].notas[2].matematica,
                   &alunos[i].notas[2].fisica,
                   &alunos[i].notas[2].quimica,
                   &alunos[i].notas[2].ingles,
                   &alunos[i].notas[3].portugues, /* 4o bimestre */
                   &alunos[i].notas[3].matematica,
                   &alunos[i].notas[3].fisica,
                   &alunos[i].notas[3].quimica,
                   &alunos[i].notas[3].ingles);

            if (read == EOF) {
                terminou = TRUE;
            } else {
                printf("Lendo aluno %s...\n", alunos[i].nome);
                quantos_alunos++; /* atualiza tamanho do vetor */
            }
        }

        fclose(arquivo);
    }

    while (!sair) {
        int opcao;

        if (exibir_menu) {
            printf("-= Sistema Gerenciador de Notas =-\n\n"); /* \n eh para quebrar linha */

            printf("1. Adicionar novo aluno\n");
            printf("2. Cadastro de notas de um aluno\n");
            printf("3. Imprimir medias de cada materia de cada aluno\n");
            printf("4. Modificar notas de uma materia de um aluno\n");
            printf("5. Imprimir nome e notas de um aluno\n");
            printf("6. Imprimir dados de um aluno\n");
            printf("7. Imprimir medias de um aluno\n");
            printf("8. Imprimir notas de um bimestre de todos alunos\n");
            printf("9. Apagar um aluno\n");
            printf("10. Ordenar os alunos em ordem alfabetica\n");
            printf("11. Salvar as informacoes no arquivo alunos.txt\n");
            printf("12. Sair (salva no arquivo alunos.txt)\n");
        }

        exibir_menu = FALSE;

        printf("\nDigite uma funcao 1 a 12 (0 = exibe funcoes): ");

        scanf("%d", &opcao);

        switch (opcao) {

        case 0:
            /* Somente para exibir novamente as opcoes */
            exibir_menu = TRUE;
        break;

        case 1:
            if (quantos_alunos >= MAX_ALUNOS) {
                printf("\n** Maximo de alunos atingido! Apague algum para incluir outro. Maximo: %d\n", MAX_ALUNOS);
            } else {
                tipo_aluno novo_aluno; /* variavel que guarda o novo aluno que serah colocado no vetor */
                int sexo_valido; /* variavel de controle apenas para verificar se o sexo digitado eh valido */
                int bimestre; /* para o for que percorre os bimestres mais abaixo */

                printf("Nome do aluno (max %d caracteres): ", MAX_NOME_ALUNO);
                scanf("%s", novo_aluno.nome);

                printf("Data de nascimento (no formato dia/mes/ano): ");
                scanf("%d/%d/%d",
                      &novo_aluno.data_nascimento.dia,
                      &novo_aluno.data_nascimento.mes,
                      &novo_aluno.data_nascimento.ano);

                printf("Idade: ");
                scanf("%d", &novo_aluno.idade);

                do {
                    /* Permanece em loop enquanto o sexo digitado nao for M ou F */
                    printf("Sexo: (M ou F): ");
                    scanf("%1s", &novo_aluno.sexo); /* %1s eh pra ler 1 caracter soh */

                    /* transforma em maiusculas */
                    if (novo_aluno.sexo == 'f') {
                        novo_aluno.sexo = FEM;
                    } else if (novo_aluno.sexo == 'm') {
                        novo_aluno.sexo = MASC;
                    }

                    /* Valida se o sexo eh um caracter aceitavel (definidos como constante) */
                    sexo_valido = (novo_aluno.sexo == MASC || novo_aluno.sexo == FEM);

                } while (!sexo_valido);

                /* zera as notas do aluno */
                for (bimestre = 0; bimestre < 4; bimestre++) {
                    novo_aluno.notas[bimestre].portugues = 0;
                    novo_aluno.notas[bimestre].matematica = 0;
                    novo_aluno.notas[bimestre].fisica = 0;
                    novo_aluno.notas[bimestre].quimica = 0;
                    novo_aluno.notas[bimestre].ingles = 0;
                }

                alunos[quantos_alunos++] = novo_aluno; /* coloca o aluno na ultima posicao disponivel do vetor */
            }

        break;

        case 2:
            if (quantos_alunos == 0) {
                printf("\n** Nao ha alunos cadastrados!\n");
            } else {
                int numero_do_aluno;

                printf("Digite o numero do aluno (0-%d): ", quantos_alunos - 1);
                scanf("%d", &numero_do_aluno);

                if (numero_do_aluno < 0 || numero_do_aluno >= quantos_alunos) {
                    printf("\n** Numero do aluno invalido!\n");
                } else {
                    int bimestre;

                    for (bimestre = 0; bimestre < 4; bimestre++) {
                        printf("\nCadastro de notas para o %do bimestre\n\n", bimestre + 1); /* +1 porque o for comeca no zero */

                        printf("Digite a nota para portugues: ");
                        scanf("%d", &alunos[numero_do_aluno].notas[bimestre].portugues);

                        printf("Digite a nota para matematica: ");
                        scanf("%d", &alunos[numero_do_aluno].notas[bimestre].matematica);

                        printf("Digite a nota para fisica: ");
                        scanf("%d", &alunos[numero_do_aluno].notas[bimestre].fisica);

                        printf("Digite a nota para quimica: ");
                        scanf("%d", &alunos[numero_do_aluno].notas[bimestre].quimica);

                        printf("Digite a nota para ingles: ");
                        scanf("%d", &alunos[numero_do_aluno].notas[bimestre].ingles);
                    }
                }
            }

        break;

        case 3:
            if (quantos_alunos == 0) {
                printf("\n** Nao ha alunos cadastrados!\n");
            } else {
                int i, bimestre;

                for (i = 0; i < quantos_alunos; i++) {
                    int total_portugues = 0;
                    int total_matematica = 0;
                    int total_fisica = 0;
                    int total_quimica = 0;
                    int total_ingles = 0;

                    for (bimestre = 0; bimestre < 4; bimestre++) {
                        total_portugues += alunos[i].notas[bimestre].portugues;
                        total_matematica += alunos[i].notas[bimestre].matematica;
                        total_fisica += alunos[i].notas[bimestre].fisica;
                        total_quimica += alunos[i].notas[bimestre].quimica;
                        total_ingles += alunos[i].notas[bimestre].ingles;
                    }

                    {
                        float portugues_media = ((float) total_portugues) / 4.0;
                        float matematica_media = ((float) total_matematica) / 4.0;
                        float fisica_media = ((float) total_fisica) / 4.0;
                        float quimica_media = ((float) total_quimica) / 4.0;
                        float ingles_media = ((float) total_ingles) / 4.0;

                        printf("%d) %s\t\tPOR %0.2f; MAT %0.2f; FIS %0.2f; QUI %0.2f; ING %0.2f\n", /* \t eh para alinhar as notas com tabulacao */
                               i, alunos[i].nome,
                               portugues_media,
                               matematica_media,
                               fisica_media,
                               quimica_media,
                               ingles_media);
                    }
                }
            }

        break;

        case 4:
            if (quantos_alunos == 0) {
                printf("\n** Nao ha alunos cadastrados!\n");
            } else {
                int numero_do_aluno;

                printf("Digite o numero do aluno (0-%d): ", quantos_alunos - 1);
                scanf("%d", &numero_do_aluno);

                if (numero_do_aluno < 0 || numero_do_aluno >= quantos_alunos) {
                    printf("\n** Numero do aluno invalido!\n");
                } else {
                    int bimestre;
                    int materia;

                    printf("\n1. portugues / 2. matematica / 3. fisica / 4. quimica / 5. ingles\n\n");
                    printf("Selecione a materia (1-5): ");
                    scanf("%d", &materia);

                    if (materia < 1 || materia > 5) {
                        printf("\n** Numero de materia invalido!\n");
                    } else {
                        for (bimestre = 0; bimestre < 4; bimestre++) {
                            printf("\nCadastro de notas para o %do bimestre\n\n", bimestre + 1); /* +1 porque o for comeca no zero */

                            switch (materia) {
                                case 1:
                                    printf("Digite a nota para portugues: ");
                                    scanf("%d", &alunos[numero_do_aluno].notas[bimestre].portugues);
                                break;

                                case 2:
                                    printf("Digite a nota para matematica: ");
                                    scanf("%d", &alunos[numero_do_aluno].notas[bimestre].matematica);
                                break;

                                case 3:
                                    printf("Digite a nota para fisica: ");
                                    scanf("%d", &alunos[numero_do_aluno].notas[bimestre].fisica);
                                break;

                                case 4:
                                    printf("Digite a nota para quimica: ");
                                    scanf("%d", &alunos[numero_do_aluno].notas[bimestre].quimica);
                                break;

                                case 5:
                                    printf("Digite a nota para ingles: ");
                                    scanf("%d", &alunos[numero_do_aluno].notas[bimestre].ingles);
                                break;
                            }
                        }
                    }
                }
            }

        break;

        case 5:
            if (quantos_alunos == 0) {
                printf("\n** Nao ha alunos cadastrados!\n");
            } else {
                int numero_do_aluno;

                printf("Digite o numero do aluno (0-%d): ", quantos_alunos - 1);
                scanf("%d", &numero_do_aluno);

                if (numero_do_aluno < 0 || numero_do_aluno >= quantos_alunos) {
                    printf("\n** Numero do aluno invalido!\n");
                } else {
                    int bimestre;
                    printf("\n== Notas do aluno %s ==\n\n", alunos[numero_do_aluno].nome);

                    for (bimestre = 0; bimestre < 4; bimestre++) {
                        printf("= %do bimestre =\n", bimestre + 1); /* +1 porque o for comeca no zero */

                        printf("Portugues:  %d\n", alunos[numero_do_aluno].notas[bimestre].portugues);
                        printf("Matematica: %d\n", alunos[numero_do_aluno].notas[bimestre].matematica);
                        printf("Fisica:     %d\n", alunos[numero_do_aluno].notas[bimestre].fisica);
                        printf("Quimica:    %d\n", alunos[numero_do_aluno].notas[bimestre].quimica);
                        printf("Ingles:     %d\n\n", alunos[numero_do_aluno].notas[bimestre].ingles);
                    }
                }
            }

        break;

        case 6:
            if (quantos_alunos == 0) {
                printf("\n** Nao ha alunos cadastrados!\n");
            } else {
                int numero_do_aluno;

                printf("Digite o numero do aluno (0-%d): ", quantos_alunos - 1);
                scanf("%d", &numero_do_aluno);

                if (numero_do_aluno < 0 || numero_do_aluno >= quantos_alunos) {
                    printf("\n** Numero do aluno invalido!\n");
                } else {
                    printf("\nNome: %s", alunos[numero_do_aluno].nome);

                    /* %02d eh pra mostrar o 0 na frente quando tem um digito soh */
                    printf("\nData de nascimento: %02d/%02d/%02d",
                           alunos[numero_do_aluno].data_nascimento.dia,
                           alunos[numero_do_aluno].data_nascimento.mes,
                           alunos[numero_do_aluno].data_nascimento.ano);

                    printf("\nIdade: %d", alunos[numero_do_aluno].idade);
                    printf("\nSexo: %c\n", alunos[numero_do_aluno].sexo);
                }
            }

        break;

        case 7:
            if (quantos_alunos == 0) {
                printf("\n** Nao ha alunos cadastrados!\n");
            } else {
                int numero_do_aluno;

                printf("Digite o numero do aluno (0-%d): ", quantos_alunos - 1);
                scanf("%d", &numero_do_aluno);

                if (numero_do_aluno < 0 || numero_do_aluno >= quantos_alunos) {
                    printf("\n** Numero do aluno invalido!\n");
                } else {
                    int bimestre;
                    int total_portugues = 0;
                    int total_matematica = 0;
                    int total_fisica = 0;
                    int total_quimica = 0;
                    int total_ingles = 0;

                    for (bimestre = 0; bimestre < 4; bimestre++) {
                        total_portugues += alunos[numero_do_aluno].notas[bimestre].portugues;
                        total_matematica += alunos[numero_do_aluno].notas[bimestre].matematica;
                        total_fisica += alunos[numero_do_aluno].notas[bimestre].fisica;
                        total_quimica += alunos[numero_do_aluno].notas[bimestre].quimica;
                        total_ingles += alunos[numero_do_aluno].notas[bimestre].ingles;
                    }

                    float portugues_media = ((float) total_portugues) / 4.0;
                    float matematica_media = ((float) total_matematica) / 4.0;
                    float fisica_media = ((float) total_fisica) / 4.0;
                    float quimica_media = ((float) total_quimica) / 4.0;
                    float ingles_media = ((float) total_ingles) / 4.0;

                    printf("\nNome e media de cada disciplina do aluno %s:\n\n", alunos[numero_do_aluno].nome);
                    printf("Portugues:  %0.2f\n", portugues_media);
                    printf("Matematica: %0.2f\n", matematica_media);
                    printf("Fisica:     %0.2f\n", fisica_media);
                    printf("Quimica:    %0.2f\n", quimica_media);
                    printf("Ingles:     %0.2f\n\n", ingles_media);
                }
            }

        break;

        case 8:
            if (quantos_alunos == 0) {
                printf("\n** Nao ha alunos cadastrados!\n");
            } else {
                int bimestre;
                printf("Digite um bimestre (1-4): ");
                scanf("%d", &bimestre);

                if (bimestre < 1 || bimestre > 4) {
                    printf("\n** Bimestre invalido!\n");
                } else {
                    int i;

                    for (i = 0; i < quantos_alunos; i++) {
                        printf("%d) %s\t\tPOR %d; MAT %d; FIS %d; QUI %d; ING %d\n", /* \t eh para alinhar as notas com tabulacao */
                               i, alunos[i].nome,
                               alunos[i].notas[bimestre].portugues,
                               alunos[i].notas[bimestre].matematica,
                               alunos[i].notas[bimestre].fisica,
                               alunos[i].notas[bimestre].quimica,
                               alunos[i].notas[bimestre].ingles);
                    }
                }
            }

        break;

        case 9:
            if (quantos_alunos == 0) {
                printf("\n** Nao ha alunos cadastrados!\n");
            } else {
                int numero_do_aluno;

                printf("Digite o numero do aluno (0-%d): ", quantos_alunos - 1);
                scanf("%d", &numero_do_aluno);

                if (numero_do_aluno < 0 || numero_do_aluno >= quantos_alunos) {
                    printf("\n** Numero do aluno invalido!\n");
                } else {
                    int i;
                    printf("\nAluno %s apagado!\n", alunos[numero_do_aluno].nome);

                    /* Diminui tamanho do vetor */
                    quantos_alunos--;

                    /* Desloca elementos para a esquerda */
                    for (i = numero_do_aluno; i < quantos_alunos; i++) {
                        alunos[i] = alunos[i + 1];
                    }
                }
            }

        break;

        case 10:
            if (quantos_alunos == 0) {
                printf("\n** Nao ha alunos cadastrados!\n");
            } else {
                int ordenado = 0;

                /* Utilizando o metodo de ordenacao bubble sort */

                while (!ordenado) {
                    int i;

                    ordenado = TRUE;

                    for (i = 0; i < quantos_alunos - 1; i++) {
                        int comparacao = strcmp(alunos[i].nome, alunos[i + 1].nome);

                        if (comparacao > 0) {
                            tipo_aluno aluno_para_troca = alunos[i];
                            alunos[i] = alunos[i + 1];
                            alunos[i + 1] = aluno_para_troca;

                            /* Se houve pelo menos uma troca, entao nao esta ordenado! */
                            ordenado = FALSE;
                        }
                    }
                }

                printf("\nLista de alunos ordenada com sucesso!\n");
            }

        break;

        case 11:
            if (quantos_alunos == 0) {
                printf("\n** Nao ha alunos cadastrados!\n");
            }

        case 12:
            /* Salva em arquivo (tanto para a opcao 11 - salvar - quanto para a opcao 12 - sair) */
            {
                int i;
                FILE *arquivo = fopen("alunos.txt", "w+");

                for (i = 0; i < quantos_alunos; i++) {
                    printf("Salvando aluno %s...\n", alunos[i].nome);

                    fprintf(arquivo, "%s\n%02d/%02d/%02d;%d;%c;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d\n",
                           alunos[i].nome,
                           alunos[i].data_nascimento.dia,
                           alunos[i].data_nascimento.mes,
                           alunos[i].data_nascimento.ano,
                           alunos[i].idade,
                           alunos[i].sexo,
                           alunos[i].notas[0].portugues, /* 1o bimestre */
                           alunos[i].notas[0].matematica,
                           alunos[i].notas[0].fisica,
                           alunos[i].notas[0].quimica,
                           alunos[i].notas[0].ingles,
                           alunos[i].notas[1].portugues, /* 2o bimestre */
                           alunos[i].notas[1].matematica,
                           alunos[i].notas[1].fisica,
                           alunos[i].notas[1].quimica,
                           alunos[i].notas[1].ingles,
                           alunos[i].notas[2].portugues, /* 3o bimestre */
                           alunos[i].notas[2].matematica,
                           alunos[i].notas[2].fisica,
                           alunos[i].notas[2].quimica,
                           alunos[i].notas[2].ingles,
                           alunos[i].notas[3].portugues, /* 4o bimestre */
                           alunos[i].notas[3].matematica,
                           alunos[i].notas[3].fisica,
                           alunos[i].notas[3].quimica,
                           alunos[i].notas[3].ingles);
                }

                fclose(arquivo);
            }

            if (opcao == 12) {
                sair = 1;
            }

            break;

        default:
            printf("\n** Opcao invalida!\n");
            break;
        }
    }

    return 0;
}
