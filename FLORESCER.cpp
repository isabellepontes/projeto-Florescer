#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
 
int pontuacaoTotal = 0;
const char* NOME_ARQUIVO = "placar.txt";
 
 
void carregarPontuacao() {
    FILE *arquivo = fopen(NOME_ARQUIVO, "r");
 
    if (arquivo != NULL) {
        fscanf(arquivo, "%d", &pontuacaoTotal);
        fclose(arquivo);
        printf("Placar inicializado. Pontuação carregada do arquivo.\n");
    } else {
        printf("Placar inicializado. Arquivo de pontuação não encontrado, iniciando com 0.\n");
    }
}
 
 
void salvarPontuacao() {
    FILE *arquivo = fopen(NOME_ARQUIVO, "w");
 
    if (arquivo != NULL) {
        fprintf(arquivo, "%d", pontuacaoTotal);
        fclose(arquivo);
        printf("(Salvo: Pontuação registrada no arquivo.)\n");
    } else {
        printf("ERRO: Não foi possível salvar a pontuação no arquivo!\n");
    }
}
 
 
void exibirPontuacao() {
    printf("Pontuação Atual: %d\n", pontuacaoTotal);
}
 
 
void adicionarPontos(int pontos) {
    if (pontos > 0) {
        pontuacaoTotal += pontos;
        printf("Parabéns! Você ganhou %d pontos.\n", pontos);
        
        salvarPontuacao();
        exibirPontuacao();
    } else {
        printf("Erro: Não é possível adicionar pontos negativos.\n");
    }
}
 
 
void resetarPontuacao() {
    pontuacaoTotal = 0;
    salvarPontuacao();
    printf("----------------------------------------\n");
    printf("Pontuação total resetada com sucesso.\n");
    printf("----------------------------------------\n");
}
 
 
int main() {
    
    setlocale(LC_ALL, "");
    
    printf("--- Projeto Florescer: Teste do Módulo de Pontuação em C ---\n");
 
    carregarPontuacao();
    
    printf("\n--- INÍCIO DO JOGO ---\n");
    
    exibirPontuacao();
    
    printf("\n[AÇÃO: Acertei um Quiz (10 pontos)]\n");
    adicionarPontos(10);
 
    printf("\n[AÇÃO: Completei um Desafio (50 pontos)]\n");
    adicionarPontos(50);
    
    printf("\n--- FIM DAS AÇÕES ---\n");
    
    resetarPontuacao();
    
    exibirPontuacao();
    
    printf("\nEncerrando o sistema de pontuação.\n");
    return 0;
}
