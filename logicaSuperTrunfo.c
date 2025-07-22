#include <stdio.h>
#include <string.h>

// Estrutura que representa uma carta de cidade
struct Carta {
    char estado[50];
    char codigo[10];
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidade; // calculada automaticamente: população / área
};

// Função para cadastrar uma carta
struct Carta cadastrarCarta(int numero) {
    struct Carta carta;

    printf("\n📥 Cadastro da Carta %d:\n", numero);

    // Leitura dos dados da carta via terminal
    printf("Digite o estado: ");
    scanf(" %[^\n]", carta.estado); // Lê até a quebra de linha

    printf("Digite o código da carta: ");
    scanf(" %[^\n]", carta.codigo);

    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", carta.nome);

    printf("Digite a população: ");
    scanf("%d", &carta.populacao);

    printf("Digite a área (km²): ");
    scanf("%f", &carta.area);

    printf("Digite o PIB (em bilhões): ");
    scanf("%f", &carta.pib);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta.pontosTuristicos);

    // Cálculo automático da densidade populacional
    carta.densidade = carta.populacao / carta.area;

    return carta;
}

// Função para exibir os dados de uma carta
void exibirCarta(struct Carta carta) {
    printf("\n📄 Informações da Carta:\n");
    printf("Estado: %s\n", carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("Cidade: %s\n", carta.nome);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões\n", carta.pib);
    printf("Pontos turísticos: %d\n", carta.pontosTuristicos);
    printf("Densidade populacional: %.2f hab/km²\n", carta.densidade);
}

// Função que compara duas cartas com base em um atributo escolhido
void compararCartas(struct Carta c1, struct Carta c2, char atributo[]) {
    printf("\n📊 Comparando cartas com base em: %s\n", atributo);

    // Comparação especial para densidade (menor valor vence)
    if (strcmp(atributo, "densidade") == 0) {
        if (c1.densidade < c2.densidade)
            printf("\n🏆 Vencedora: %s (densidade = %.2f)\n", c1.nome, c1.densidade);
        else
            printf("\n🏆 Vencedora: %s (densidade = %.2f)\n", c2.nome, c2.densidade);
    }
    // Comparação para população (maior vence)
    else if (strcmp(atributo, "populacao") == 0) {
        if (c1.populacao > c2.populacao)
            printf("\n🏆 Vencedora: %s (população = %d)\n", c1.nome, c1.populacao);
        else
            printf("\n🏆 Vencedora: %s (população = %d)\n", c2.nome, c2.populacao);
    }
    // Comparação para área (maior vence)
    else if (strcmp(atributo, "area") == 0) {
        if (c1.area > c2.area)
            printf("\n🏆 Vencedora: %s (área = %.2f)\n", c1.nome, c1.area);
        else
            printf("\n🏆 Vencedora: %s (área = %.2f)\n", c2.nome, c2.area);
    }
    // Comparação para PIB (maior vence)
    else if (strcmp(atributo, "pib") == 0) {
        if (c1.pib > c2.pib)
            printf("\n🏆 Vencedora: %s (PIB = %.2f)\n", c1.nome, c1.pib);
        else
            printf("\n🏆 Vencedora: %s (PIB = %.2f)\n", c2.nome, c2.pib);
    }
    // Comparação para pontos turísticos (maior vence)
    else if (strcmp(atributo, "pontos") == 0) {
        if (c1.pontosTuristicos > c2.pontosTuristicos)
            printf("\n🏆 Vencedora: %s (pontos turísticos = %d)\n", c1.nome, c1.pontosTuristicos);
        else
            printf("\n🏆 Vencedora: %s (pontos turísticos = %d)\n", c2.nome, c2.pontosTuristicos);
    }
    // Atributo inválido
    else {
        printf("❌ Atributo inválido! Use: populacao, area, pib, pontos ou densidade.\n");
    }
}

// Função principal do programa
int main() {
    printf("🔹 Cadastro de Cartas Super Trunfo de Cidades 🔹\n");

    // Cadastro das duas cartas via terminal
    struct Carta carta1 = cadastrarCarta(1);
    struct Carta carta2 = cadastrarCarta(2);

    // Exibição das cartas cadastradas
    exibirCarta(carta1);
    exibirCarta(carta2);

    // Atributo usado para comparar — você pode alterar para: "populacao", "area", "pib", "pontos", "densidade"
    char atributo[20] = "pib";

    // Comparação entre as duas cartas
    compararCartas(carta1, carta2, atributo);

    return 0;
}
