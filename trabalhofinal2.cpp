//=============Dupla=============//
//===Davison Girão===============//
//===Cicero Ilbsberg=============//


#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <map>

struct RegistroVenda {
    int codigoPedido;
    std::string codigoProduto;
    int quantidadeVendida;
    double precoUnitario;
    std::string dataVenda;
};
//Menu de escolhas p/ o usuariio
int mostrarMenu() {
    int escolha;

    std::cout << "\n========== MENU PRINCIPAL ==========\n";
    std::cout << "1. Importar dados das vendas\n";
    std::cout << "2. Calcular faturamento total\n";
    std::cout << "3. Produto mais vendido (quantidade)\n";
    std::cout << "4. Produto mais rentável (faturamento)\n";
    std::cout << "5. Encerrar programa\n";
    std::cout << "====================================\n";
    std::cout << "Digite sua escolha: ";

    //garante que o usuario escolha uma opcão valida
    while (!(std::cin >> escolha) || escolha < 1 || escolha > 5) {
        std::cout << "Opção inválida! Selecione um número entre 1 e 5: ";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }
//retrona para as opcoes
    return escolha;
}
//Recebe um vetor por referência para armazenar os dados importados.
bool importarDadosVendas(std::vector<RegistroVenda> &listaVendas) {
    std::string nomeArquivo;

    //Pede o nome do arquivo CSV.
    std::cout << "Informe o nome do arquivo CSV: ";
    std::cin >> nomeArquivo;

    //Tenta abrir o arquivo; se não conseguir, exibe erro.
    std::ifstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) {
        std::cout << "Erro ao tentar abrir o arquivo: " << nomeArquivo << std::endl;
        return false;
    }

    std::string linha;
    std::getline(arquivo, linha); // ignora cabeçalho

    //Para cada linha do arquivo:
    //Usa stringstream para dividir os campos por vírgula.
    //Converte os valores com stoi (string para int) e stod (string para double).

    while (std::getline(arquivo, linha)) {
        std::stringstream ss(linha);
        std::string campo;

        getline(ss, campo, ',');
        int pedido = std::stoi(campo);

        getline(ss, campo, ',');
        std::string produto = campo;

        getline(ss, campo, ',');
        int qtd = std::stoi(campo);

        getline(ss, campo, ',');
        double preco = std::stod(campo);

        getline(ss, campo, ',');
        std::string data = campo;
//Cria um registroVenda e adiciona ao vetor
        RegistroVenda registro = {pedido, produto, qtd, preco, data};
        listaVendas.push_back(registro);
    }
//fecha o arquivo e exibe que foi importado
    arquivo.close();
    std::cout << "Dados importados com sucesso.\n";
    return true;
}
//funcao calcular o total faturado
double calcularTotalFaturado(const std::vector<RegistroVenda>& listaVendas) {
//variavel contador
    double total = 0.0;

    //contador
    for (const auto& venda : listaVendas) {
        total += venda.quantidadeVendida * venda.precoUnitario;
    }

    return total;
}
//Percorre todas as vendas, somando a quantidade por produto.
std::string obterProdutoMaisVendido(const std::vector<RegistroVenda>& listaVendas) {
    std::map<std::string, int> contagemProdutos;

    for (const auto& venda : listaVendas) {
        contagemProdutos[venda.codigoProduto] += venda.quantidadeVendida;
    }

    std::string produtoMaisVendido;
    int maiorQuantidade = 0;

    for (const auto& item : contagemProdutos) {
    for (const auto& item : contagemProdutos) {
        if (item.second > maiorQuantidade) {
            maiorQuantidade = item.second;
            produtoMaisVendido = item.first;
        }
    }

    return produtoMaisVendido;
}
//Soma a receita total por produto.
std::string obterProdutoMaisRentavel(const std::vector<RegistroVenda>& listaVendas) {
    std::map<std::string, double> receitaProdutos;

    for (const auto& venda : listaVendas) {
        receitaProdutos[venda.codigoProduto] += venda.quantidadeVendida * venda.precoUnitario;
    }

    std::string produtoTop;
    double maiorReceita = 0.0;

    for (const auto& item : receitaProdutos) {
        if (item.second > maiorReceita) {
            maiorReceita = item.second;
            produtoTop = item.first;
        }
    }

    return produtoTop;
}

int main() {
    std::vector<RegistroVenda> vendas;
    bool dadosImportados = false;

    while (true) {
        int opcao = mostrarMenu();

        switch (opcao) {
            case 1:
                vendas.clear();
                dadosImportados = importarDadosVendas(vendas);
                break;

            case 2:
                if (!dadosImportados) {
                    std::cout << "É necessário importar os dados primeiro (opção 1).\n";
                } else {
                    double total = calcularTotalFaturado(vendas);
                    std::cout << "Faturamento total: R$ " << total << std::endl;
                }
                break;

            case 3:
                if (!dadosImportados) {
                    std::cout << "É necessário importar os dados primeiro (opção 1).\n";
                } else {
                    std::string produto = obterProdutoMaisVendido(vendas);
                    std::cout << "Produto mais vendido: " << produto << std::endl;
                }
                break;

            case 4:
                if (!dadosImportados) {
                    std::cout << "É necessário importar os dados primeiro (opção 1).\n";
                } else {
                    std::string produto = obterProdutoMaisRentavel(vendas);
                    std::cout << "Produto mais rentável: " << produto << std::endl;
                }
                break;

            case 5:
                std::cout << "Encerrando o programa. Até logo.\n";
                return 0;
        }
    }

    return 0;
}
