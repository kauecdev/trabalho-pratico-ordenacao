#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <iomanip>
#include <fstream>
#include "bubble_sort.h"
#include "insertion_sort.h"
#include "merge_sort.h"
#include "quick_sort.h"
#include "heap_sort.h"

using namespace std;

const int NUM_EXECUTIONS = 3;
const vector<int> ARRAY_SIZES = {100, 1000, 5000, 30000, 50000, 100000, 150000, 200000};

vector<int> generateAscendingArray(int size)
{
  vector<int> arr(size);
  for (int i = 0; i < size; i++)
  {
    arr[i] = i + 1;
  }
  return arr;
}

vector<int> generateDescendingArray(int size)
{
  vector<int> arr(size);
  for (int i = 0; i < size; i++)
  {
    arr[i] = size - i;
  }
  return arr;
}

vector<int> generateRandomArray(int size)
{
  vector<int> arr(size);
  for (int i = 0; i < size; i++)
  {
    arr[i] = rand() % (size * 10) + 1;
  }
  return arr;
}

struct TestResult
{
  string algorithmName;
  string inputType;
  int arraySize;
  long long totalComparisons;
  double averageTime; // in milliseconds
};

TestResult runSortTest(string algorithmName, int algorithm, string inputType, int arraySize)
{
  TestResult result;
  result.algorithmName = algorithmName;
  result.inputType = inputType;
  result.arraySize = arraySize;
  result.totalComparisons = 0;
  double totalTime = 0.0;

  vector<int> baseArray;

  if (inputType == "ASC")
  {
    baseArray = generateAscendingArray(arraySize);
  }
  else if (inputType == "DESC")
  {
    baseArray = generateDescendingArray(arraySize);
  }
  else if (inputType == "RAND")
  {
    baseArray = generateRandomArray(arraySize);
  }

  for (int exec = 0; exec < NUM_EXECUTIONS; exec++)
  {
    vector<int> testArray = baseArray;

    auto start = chrono::high_resolution_clock::now();
    long long comparisons = 0;

    switch (algorithm)
    {
    case 1:
      comparisons = bubbleSort(testArray);
      break;
    case 2:
      comparisons = insertionSort(testArray);
      break;
    case 3:
      comparisons = mergeSort(testArray);
      break;
    case 4:
      comparisons = quickSort(testArray);
      break;
    case 5:
      comparisons = heapSort(testArray);
      break;
    }

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> elapsed = end - start;

    result.totalComparisons += comparisons;
    totalTime += elapsed.count();
  }

  result.totalComparisons /= NUM_EXECUTIONS;
  result.averageTime = totalTime / NUM_EXECUTIONS;

  return result;
}

void displayTestResult(const TestResult &result)
{
  cout << "\n  Algoritmo: " << result.algorithmName << endl;
  cout << "  Tipo de Input: " << result.inputType << endl;
  cout << "  Tamanho do vetor: " << result.arraySize << endl;
  cout << "  Número de comparações: " << result.totalComparisons << endl;
  cout << "  Tempo médio: " << fixed << setprecision(4) << result.averageTime << " ms" << endl;
}

void saveResultsToCSV(const vector<TestResult> &results, const string &filename)
{
  ofstream file(filename);
  
  if (!file.is_open())
  {
    cout << "\nErro ao abrir arquivo " << filename << " para escrita!" << endl;
    return;
  }

  // Escrever cabeçalho
  file << "Algoritmo,Tipo de Vetor,Tamanho do Vetor,Número de Comparações,Tempo Médio (ms)" << endl;

  // Escrever dados
  for (const auto &result : results)
  {
    file << result.algorithmName << ","
         << result.inputType << ","
         << result.arraySize << ","
         << result.totalComparisons << ","
         << fixed << setprecision(4) << result.averageTime << endl;
  }

  file.close();
  cout << "\nResultados salvos em " << filename << endl;
}

void runAllTests()
{
  cout << "\n"
       << string(50, '=') << endl;
  cout << "RODANDO TODOS OS TESTES" << endl;
  cout << string(50, '=') << endl;

  vector<pair<int, string>> algorithms = {
      {1, "Bubble Sort"},
      {2, "Insertion Sort"},
      {3, "Merge Sort"},
      {4, "Quick Sort"},
      {5, "Heap Sort"}};

  vector<string> inputTypes = {"ASC", "DESC", "RAND"};
  vector<TestResult> allResults;

  for (auto &alg : algorithms)
  {
    cout << "\n"
         << string(50, '-') << endl;
    cout << "Testando " << alg.second << endl;
    cout << string(50, '-') << endl;

    for (const auto &arraySize : ARRAY_SIZES)
    {
      cout << "\n  Tamanho do vetor: " << arraySize << endl;

      for (const auto &inputType : inputTypes)
      {
        cout << "\n  Executando " << alg.second << " com vetor " << inputType << "..." << endl;
        TestResult result = runSortTest(alg.second, alg.first, inputType, arraySize);
        displayTestResult(result);
        allResults.push_back(result);
      }
    }
  }

  cout << "\n"
       << string(50, '=') << endl;
  cout << "TODOS OS TESTES FINALIZADOS" << endl;
  cout << string(50, '=') << endl;

  // Salvar resultados em CSV
  saveResultsToCSV(allResults, "resultados_testes.csv");
}

void runSingleAlgorithm(int choice)
{
  vector<pair<int, string>> algorithms = {
      {1, "Bubble Sort"},
      {2, "Insertion Sort"},
      {3, "Merge Sort"},
      {4, "Quick Sort"},
      {5, "Heap Sort"}};

  if (choice < 1 || choice > 5)
  {
    cout << "\nEscolha invalida!" << endl;
    return;
  }

  auto alg = algorithms[choice - 1];
  cout << "\n"
       << string(50, '=') << endl;
  cout << "Testando " << alg.second << endl;
  cout << string(50, '=') << endl;

  vector<string> inputTypes = {"ASC", "DESC", "RAND"};
  vector<TestResult> results;

  for (const auto &arraySize : ARRAY_SIZES)
  {
    cout << "\n  Tamanho do vetor: " << arraySize << endl;

    for (const auto &inputType : inputTypes)
    {
      cout << "\n  Executando " << alg.second << " com vetor " << inputType << "..." << endl;
      TestResult result = runSortTest(alg.second, alg.first, inputType, arraySize);
      displayTestResult(result);
      results.push_back(result);
    }
  }

  cout << "\n"
       << string(50, '=') << endl;
  cout << "TESTE FINALIZADO" << endl;
  cout << string(50, '=') << endl;

  // Salvar resultados em CSV
  saveResultsToCSV(results, "resultados_" + alg.second + ".csv");
}

void displayAlgorithmMenu()
{
  cout << "\n"
       << string(50, '=') << endl;
  cout << "SELECIONE O ALGORITMO" << endl;
  cout << string(50, '=') << endl;
  cout << "1 - Bubble Sort" << endl;
  cout << "2 - Insertion Sort" << endl;
  cout << "3 - Merge Sort" << endl;
  cout << "4 - Quick Sort" << endl;
  cout << "5 - Heap Sort" << endl;
  cout << "6 - Voltar" << endl;
  cout << string(50, '=') << endl;
  cout << "Sua escolha: ";
}

void displayMainMenu()
{
  cout << "\n"
       << string(50, '=') << endl;
  cout << "SUITE DE TESTES DE ALGORITMOS DE ORDENAÇÃO" << endl;
  cout << string(50, '=') << endl;
  cout << "1 - Rodar testes separadamente" << endl;
  cout << "2 - Rodar todos os testes" << endl;
  cout << "3 - Encerrar programa" << endl;
  cout << string(50, '=') << endl;
  cout << "Sua escolha: ";
}

int main()
{
  srand(time(0));

  int mainChoice;
  bool running = true;

  while (running)
  {
    displayMainMenu();
    cin >> mainChoice;

    switch (mainChoice)
    {
    case 1:
    {
      bool selectingAlgorithm = true;
      while (selectingAlgorithm)
      {
        displayAlgorithmMenu();
        int algChoice;
        cin >> algChoice;

        if (algChoice == 6)
        {
          selectingAlgorithm = false;
        }
        else if (algChoice >= 1 && algChoice <= 5)
        {
          runSingleAlgorithm(algChoice);
        }
        else
        {
          cout << "\nEscolha inválida! Tente novamente." << endl;
        }
      }
      break;
    }
    case 2:
    {
      runAllTests();
      break;
    }
    case 3:
    {
      cout << "\nObrigado por utilizar a Suite de Testes de Algoritmos de Ordenação!" << endl;
      running = false;
      break;
    }
    default:
      cout << "\nEscolha inválida! Tente novamente." << endl;
    }
  }

  return 0;
}
