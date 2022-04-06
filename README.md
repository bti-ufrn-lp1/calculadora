# Calculadora

## Sobre
Este programa implementa uma calculadora simples com as quatro operações aritméticas básicas (adição, subtração, multiplicação e divisão) e imprime o resultado na saída padrão.

## Implementação
Este programa foi implementado na linguagem de programação C++ primando pela modularização, isto é, buscando organizar todos os diretórios e arquivos de forma a facilitar a estruturação, leitura, manutenção e reutilização do código. Assim sendo, o protótipo e a implementação das funções estão organizados em arquivos separados, arquivos de cabeçalho (extensão .h) e arquivos de corpo (extensão .cpp).

### Organização em diretórios
O projeto mantém a organização dos arquivos fonte em dois diretórios principais:
- O diretório [``include``](https://github.com/bti-ufrn-lp1/calculadora/tree/master/include) contém arquivos de cabeçalho com a definição dos protótipos das funções que implementam as operações realizadas pela calculadora.
- O diretório [``src``](https://github.com/bti-ufrn-lp1/calculadora/tree/master/src) contém arquivos de corpo com a implementação das funções definidas nos arquivos de cabeçalho.

### Arquivos fonte
No diretório [``include``](https://github.com/bti-ufrn-lp1/calculadora/tree/master/include), o arquivo de cabeçalho [``calculadora.h``](https://github.com/bti-ufrn-lp1/calculadora/blob/master/include/calculadora.h), o qual define os protótipos das funções da calculadora:
- ``somar`` realiza a adição de dois números inteiros e retorna a soma resultante;
- ``subtrair`` realiza a subtração entre dois números inteiros e retorna a diferença resultante;
- ``multiplicar`` realiza a multiplicação entre dois números inteiros e retorna o produto resultante, e;
- ``dividir`` realiza a divisão entre dois números inteiros e retorna o quociente resultante; caso o segundo parâmetro, referente ao divisor, seja igual a zero, o programa exibe uma mensagem de erro na saída padrão e retorna um valor indefinido ([``NAN``-- *Not-A-Number*](https://www.cplusplus.com/reference/cmath/nan-function/).

No diretório [``include``](https://github.com/bti-ufrn-lp1/calculadora/tree/master/include), o arquivo de cabeçalho [``calculadora.h``](https://github.com/bti-ufrn-lp1/calculadora/blob/master/include/calculadora.h), o qual define os protótipos das funções da calculadora

No diretório [``src``](https://github.com/bti-ufrn-lp1/calculadora/tree/master/src), o arquivo de corpo [``calculadora.cpp``](https://github.com/bti-ufrn-lp1/calculadora/tree/master/src) implementa essas funções definidas no arquivo de cabeçalho.

Além desses arquivos fonte, a raiz do repositório contém um arquivo em separado [``main.cpp``](https://github.com/bti-ufrn-lp1/calculadora/blob/master/main.cpp) corresponde à implementação da função principal do programa. A versão atual desta implementação define estaticamente (isto é, no próprio código fonte) os valores que servirão de operandos às operações realizadas pela calculadora, de modo que é necessário alterar este arquivo e recompilar o programa para que seja possível fazer uso de outros valores. De todo modo, é bastante fácil modificar este programa para que os valores possam ser fornecidos pelo usuário via linha de comando ou através da entrada padrão. Nesse caso, fica evidente o benefício da modularizacão em separar os arquivos fonte: a modificação do arquivo [``main.cpp``](https://github.com/bti-ufrn-lp1/calculadora/blob/master/main.cpp) para utilizar outros valores ou mudar a forma pela qual eles são recebidos como entrada não requer qualquer tipo de modificação na implementacão das funções da calculadora, mas sim apenas nesse arquivo.

### Arquivos para compilação e construção do programa
À medida em que o tamanho do programa (e, consequentemente, o número de arquivos fonte) cresce, inserir manualmente comandos de compilação torna-se pouco prático. Assim sendo, foram implementados *makefiles* para facilitar a tarefa de compilação dos arquivos fonte e geração do arquivo executável referente ao programa.

Neste repositório, há dois tipos de *makefile*:
- O arquivo [``Makefile-manual``](https://github.com/bti-ufrn-lp1/calculadora/blob/master/Makefile-manual) foi escrito manualmente seguindo a estrutura típica de *makefiles*, contendo regras compostas de alvos, dependências e comandos a serem executados.
- O arquivo [``Makefile``](https://github.com/bti-ufrn-lp1/calculadora/blob/master/Makefile) foi gerado automaticamente utilizando o [CMake](https://cmake.org), um conjunto de ferramentas que possibilita a construção, teste e empacotamento de programas de forma portável e flexível entre plataformas. Para tanto, o CMake utiliza o arquivo de configuração [``CMakeLists.txt``](https://github.com/bti-ufrn-lp1/calculadora/blob/master/CMakeLists.txt).

## Pré-requisitos
- [Git](https://git-scm.com), para *download* dos arquivos deste repositório
- Compilador g++, para compilação do programa
- [GNU make](https://www.gnu.org/software/make/), para a construção de programas a partir de um *makefile*
- [CMake](https://cmake.org), para a geração automática de *makefiles*

## Download, compilação e execução do programa
No terminal do sistema operacional, insira os seguintes comandos para realizar o *download* da implementação a partir deste repositório Git e navegar para o diretório resultante:

```bash
 # Download da implementação a partir do repositório Git
 git clone https://github.com/bti-ufrn-lp1/calculadora.git
 
 # Navegação para o diretório
 cd calculadora
```
Caso se queira utilizar o *makefile* escrito manualmente, insira o seguinte comando no terminal do sistema operacional para compilar o programa:

```bash
 make -f Makefile-manual
```
Esse comando irá gerar arquivos objeto (extensão .o) no diretório ``build`` e o arquivo executável do programa, ``calculadora``, no diretório ``bin``.

Caso se queira utilizar o CMake, insira os seguintes comandos no terminal do sistema operacional para gerar automaticamente o *makefile* e, em seguida, compilar o programa:

```bash
 # Utilização do CMake para geração do Makefile
 cmake .
 
 # Compilação e geração do executável do programa
 make
```

Esses comandos irão gerar, além de um conjunto de arquivos e diretórios resultantes dos processos de compilação e ligação do programa, o arquivo executável do programa, ``calculadora``, no diretório ``bin``.

Finalmente, para executar o programa gerado por qualquer um desses dois processos, basta inserir o seguinte comando no terminal do sistema operacional:

```bash
 ./bin/calculadora
```
