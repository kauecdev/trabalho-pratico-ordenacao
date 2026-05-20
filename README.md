# Suite de Testes de Algoritmos de Ordenação

## Disciplina: Projeto e Análise de Algoritmos (PAA)

Este projeto implementa uma suite completa de testes para cinco algoritmos clássicos de ordenação, permitindo análise comparativa de desempenho através de uma interface CLI interativa.

## Algoritmos Implementados

- **Bubble Sort**
- **Insertion Sort**
- **Merge Sort**
- **Quick Sort**
- **Heap Sort**
- **AOH (Algoritmo de Ordenação Híbrido)**

## Funcionalidades

### Suite de Testes
- ✅ Testes com três tipos de entrada: Ascendente, Descendente e Aleatória
- ✅ Testes com tamanhos de array: 100, 1.000, 5.000, 30.000, 50.000, 100.000, 150.000 e 200.000 elementos
- ✅ Execução tripla de cada teste (calcula média de tempo e comparações)
- ✅ Contagem de comparações para cada algoritmo
- ✅ Medição de tempo de execução em milissegundos
- ✅ Exportação automática de resultados em arquivo CSV

### Interface CLI
- Menu principal com opções para executar testes separadamente ou todos
- Submenu para seleção individual de algoritmos
- Exibição formatada de resultados
- Opção para voltar ao menu anterior

## Estrutura do Projeto

```
trabalho-ordenacao/
├── main.cpp              # Arquivo principal com interface CLI
├── bubble_sort.cpp       # Implementação do Bubble Sort
├── bubble_sort.h         # Cabeçalho do Bubble Sort
├── insertion_sort.cpp    # Implementação do Insertion Sort
├── insertion_sort.h      # Cabeçalho do Insertion Sort
├── merge_sort.cpp        # Implementação do Merge Sort
├── merge_sort.h          # Cabeçalho do Merge Sort
├── quick_sort.cpp        # Implementação do Quick Sort
├── quick_sort.h          # Cabeçalho do Quick Sort
├── heap_sort.cpp         # Implementação do Heap Sort
├── heap_sort.h           # Cabeçalho do Heap Sort
├── aoh.cpp               # Implementação do AOH
├── aoh.h                 # Cabeçalho do AOH
└── README.md             # Este arquivo
```

## Requisitos

- C++ 11 ou superior
- Compilador g++ (ou clang)
- Sistema operacional: macOS ou Windows (com MinGW/MSYS2)

## Instruções de Compilação e Execução

### macOS

#### 1. Verificar se o compilador está instalado

Abra o Terminal e execute:

```bash
g++ --version
```

Se o g++ não estiver instalado, instale via Xcode:

```bash
xcode-select --install
```

#### 2. Compilar o projeto

Navegue até o diretório do projeto:

```bash
cd /caminho/para/trabalho-ordenacao
```

Execute o comando de compilação:

```bash
g++ -O2 -o program main.cpp bubble_sort.cpp insertion_sort.cpp merge_sort.cpp quick_sort.cpp heap_sort.cpp aoh.cpp
```

#### 3. Executar o programa

```bash
./program
```

### Windows

#### 1. Instalar MinGW-w64

- Acesse: https://www.mingw-w64.org/
- Baixe o instalador (recomenda-se a versão online)
- Execute o instalador e escolha as configurações padrão
- Adicione o MinGW ao PATH do sistema (geralmente em `C:\Program Files\mingw-w64\x86_64-...\bin`)

#### 2. Compilar o projeto

Abra o Prompt de Comando (cmd) ou PowerShell e navegue até o diretório do projeto:

```cmd
cd C:\caminho\para\trabalho-ordenacao
```

Execute o comando de compilação:

```cmd
g++ -O2 -o program.exe main.cpp bubble_sort.cpp insertion_sort.cpp merge_sort.cpp quick_sort.cpp heap_sort.cpp aoh.cpp
```

#### 3. Executar o programa

```cmd
program.exe
```

Ou simplesmente:

```cmd
program
```

## Como Usar

Ao executar o programa, você verá o menu principal:

```
==================================================
SUITE DE TESTES DE ALGORITMOS DE ORDENAÇÃO
==================================================
1 - Rodar testes separadamente
2 - Rodar todos os testes
3 - Encerrar programa
==================================================
Sua escolha:
```

### Opção 1: Rodar testes separadamente

Selecione `1` e o seguinte submenu aparecerá:

```
==================================================
SELECIONE O ALGORITMO
==================================================
1 - Bubble Sort
2 - Insertion Sort
3 - Merge Sort
4 - Quick Sort
5 - Heap Sort
6 - AOH (Quick + Insertion)
7 - Voltar
==================================================
Sua escolha:
```

Escolha um algoritmo (1-5) ou `6` para voltar ao menu principal. O algoritmo será testado com as três variações de entrada em todos os tamanhos configurados.

### Opção 2: Rodar todos os testes

Selecione `2` e todos os cinco algoritmos serão testados automaticamente com todas as três variações de entrada (Ascendente, Descendente e Aleatória) em todos os tamanhos configurados.

### Opção 3: Encerrar

Selecione `3` para sair do programa.

## Saída do Programa

Para cada teste executado, o programa exibirá:

```
  Executando Bubble Sort com vetor ASC...

  Algoritmo: Bubble Sort
  Tipo de Input: ASC
  Tamanho do vetor: 100
  Número de comparações: 4950
  Tempo médio: 0.0100 ms
```

Onde:
- **Algoritmo**: Nome do algoritmo de ordenação
- **Tipo de Input**: Tipo de entrada (ASC = Ascendente, DESC = Descendente, RAND = Aleatória)
- **Tamanho do vetor**: Quantidade de elementos do array testado
- **Número de comparações**: Média de comparações realizadas em 3 execuções
- **Tempo médio**: Tempo médio de execução em milissegundos

## Exportação de Resultados em CSV

O programa gera automaticamente um arquivo CSV com os resultados dos testes ao final da execução:

### Ao rodar todos os testes
Cria um arquivo chamado **`resultados_testes.csv`** contendo os dados de todos os 120 testes (5 algoritmos × 3 tipos de entrada × 8 tamanhos).

### Ao rodar testes individuais
Cria um arquivo chamado **`resultados_[Nome_do_Algoritmo].csv`** contendo os 24 testes daquele algoritmo (3 tipos de entrada × 8 tamanhos).

### Formato do CSV

O arquivo possui as seguintes colunas:
- **Algoritmo**: Nome do algoritmo de ordenação
- **Tipo de Vetor**: Tipo de entrada (ASC, DESC, RAND)
- **Tamanho do Vetor**: Tamanho do array testado
- **Número de Comparações**: Quantidade média de comparações
- **Tempo Médio (ms)**: Tempo médio de execução em milissegundos

Exemplo de saída:
```
Algoritmo,Tipo de Vetor,Tamanho do Vetor,Número de Comparações,Tempo Médio (ms)
Bubble Sort,ASC,100,4950,0.0100
Bubble Sort,DESC,100,4950,0.0200
Bubble Sort,RAND,100,4950,0.0150
Bubble Sort,ASC,1000,499500,0.9500
...
```

Os arquivos CSV podem ser abertos em qualquer editor de texto ou planilha eletrônica (Excel, LibreOffice Calc, Google Sheets, etc.) para análise mais detalhada dos resultados.

## Detalhes Técnicos

### Geração de Dados

- **Ascendente**: Array de 1 até o tamanho configurado em ordem crescente
- **Descendente**: Array do tamanho configurado até 1 em ordem decrescente
- **Aleatória**: Array com valores aleatórios entre 1 e 10 vezes o tamanho configurado

### Medições

- Cada teste é executado **3 vezes**
- O número de comparações é **a média das 3 execuções**
- O tempo é medido usando `chrono::high_resolution_clock` do C++ padrão

## Notas Importantes

1. Os algoritmos modificam o array original (ordenação in-place ou com cópia)
2. O gerador de números aleatórios é inicializado com a hora do sistema
3. Os tempos podem variar ligeiramente entre execuções

## Autor

Projeto desenvolvido para a disciplina de Projeto e Análise de Algoritmos (PAA)

## Licença

Este projeto é fornecido como material educacional.
