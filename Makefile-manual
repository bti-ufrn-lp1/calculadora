# Makefile completo separando os diferentes elementos da aplicação em diretórios:
# - bin: arquivos executáveis (programa)
# - build: arquivos binários
# - doc: documentação (idealmente gerada de forma automática)
# - include: arquivos de cabeçalhos
# - lib: bibliotecas
# - src: arquivos de código fonte
# - test: arquivos fonte com a implementação de testes
#
# Algumas variáveis são usadas com significado especial:
# - $@: nome do alvo (target)
# - $^: lista com os nomes de todos os pré-requisitos sem duplicatas
# - $<: nome do primeiro pré-requisito
#
# Comandos do sistema operacional
# Linux: rm -rf
# Windows: cmd //C del
RM=rm -rf
MKDIR=mkdir

# Compilador
CC=g++

# Variáveis para os diretórios
BIN_DIR=./bin
BUILD_DIR=./build
DOC_DIR=./doc
INCLUDE_DIR=./include
LIB_DIR=./lib
SRC_DIR=./src
TEST_DIR=./test

# Nome do programa
PROG=calculadora

# Opções de compilação
FLAGS=-W -Wall -pedantic -std=c++11 -I. -I$(INCLUDE_DIR)

# Alvo para a compilação completa, removendo os arquivos objeto gerados ao final
all: $(PROG)

# Alvo para a construção do executável
# Ligação dos arquivos objeto (.o) definidos como dependências
$(PROG): $(BUILD_DIR)/calculadora.o $(BUILD_DIR)/main.o
	@echo "> Gerando '$@'"
	$(MKDIR) -p $(BIN_DIR)
	$(CC) $(FLAGS) -o $(BIN_DIR)/$@ $^
	@echo "> Executavel '$@' criado em $(BIN_DIR)"

# Alvo para a construção do arquivo objeto calculadora.o
# Compilação dos arquivos fonte definidos como dependências
$(BUILD_DIR)/calculadora.o: $(SRC_DIR)/calculadora.cpp $(INCLUDE_DIR)/calculadora.h
	$(MKDIR) -p $(BUILD_DIR)
	$(CC) -c $(FLAGS) -o $@ $<

# Alvo para a construção do arquivo objeto main.o
# Compilação dos arquivos fonte definidos como dependências
$(BUILD_DIR)/main.o: main.cpp
	$(MKDIR) -p $(BUILD_DIR)
	$(CC) -c $(FLAGS) -o $@ $<

# Garantia de que os alvos desta lista não sejam confundidos com arquivos de mesmo nome
.PHONY: all clean doxy debug doc

# Alvos para a geração automática de documentação de código fonte com Doxygen
# Remove sempre a documentação anterior (caso exista) e gera uma nova versão
doxy:
	$(RM) $(DOC_DIR)/*
	doxygen -g
doc:
	doxygen

# Alvo adicionando flags para depuração
debug: FLAGS += -g -O0
debug: $(PROG)

# Alvo para limpar arquivos temporários (objeto) gerados durante a compilação,
# assim como os arquivos executáveis
clean:
	$(RM) $(BIN_DIR)/*
	$(RM) $(BUILD_DIR)/*