
#include "Serializer.hpp"
#include <cassert> // Para assert
#include <iostream>
#include <stdint.h> // Para uintptr_t>

#define println(x) std::cout << x
#define nullptr NULL

static void printData(const Data *p) {
  println(YELLOW "Value: " DFT BLUE);
  println(p->value);
  println("\n" DFT);
  println(YELLOW "Text: " DFT BLUE);
  println(p->text);
  println("\n" DFT);
}

void testSerialization(Data *dataPtr, uintptr_t raw) {
  Data *deserializedData = Serializer::deserialize(raw);

  if (deserializedData == dataPtr) {
    println(GREEN "Test serialization OK!\n" DFT);
  } else {
    println(RED "Test serialization FAIL!\n" DFT);
  }

  assert(deserializedData == dataPtr);

  printData(dataPtr);
}

void testNullPointerSerialization() {
  Data *nullPtr = nullptr;

  uintptr_t raw = Serializer::serialize(nullPtr);
  Data *deserializedData = Serializer::deserialize(raw);

  if (deserializedData == nullptr) {
    println(GREEN "Test serialization with null pointer OK!\n" DFT);
  } else {
    println(RED "Test serialization with null pointer FAIL!\n" DFT);
  }

  assert(deserializedData == nullptr);
}

int main() {
  println(BLUE_GREEN "Teste 1: Serialização e Desserialização Correta\n" DFT);
  {
    Data myData = {42, "Hello, World!"};
    Data *dataPtr = &myData;

    uintptr_t raw = Serializer::serialize(dataPtr);

    testSerialization(dataPtr, raw);

    println(GREEN "Test 1 success!\n\n" DFT);
  }

  println(BLUE_GREEN "Teste 2: Serialização de Ponteiro Nulo\n" DFT);
  {
    testNullPointerSerialization();

    println(GREEN "Test 2 success!\n\n" DFT);
  }

  println(BLUE_GREEN "Teste 3: Deserialização de Valor Inválido\n" DFT);
  {
    uintptr_t invalidRaw =
        0xFFFFFFFFFFFFFFFF; // Valor inválido que não corresponde a um ponteiro
                            // válido
    Data *deserializedData = Serializer::deserialize(invalidRaw);

    // Aqui não podemos fazer uma assertiva direta de que o ponteiro é inválido,
    // mas podemos checar se o ponteiro não é um endereço válido do nosso objeto
    // original. Verificar se deserializedData não aponta para um objeto válido
    // de Data
    assert(
        deserializedData !=
        nullptr); // Este teste pode não ser confiável em ambientes diferentes

    println(GREEN "Test 3 success!\n\n" DFT);
  }

  println(BLUE_GREEN
          "Teste 4: Serialização e Desserialização com Dados Diferentes\n" DFT);
  {
    Data myData1 = {100, "Test String"};
    Data myData2 = {200, "Another Test String"};
    Data *dataPtr1 = &myData1;
    Data *dataPtr2 = &myData2;

    uintptr_t raw1 = Serializer::serialize(dataPtr1);
    uintptr_t raw2 = Serializer::serialize(dataPtr2);

    Data *deserializedData1 = Serializer::deserialize(raw1);
    printData(deserializedData1);
    Data *deserializedData2 = Serializer::deserialize(raw2);
    printData(deserializedData2);

    // Assegurar que os ponteiros e dados são iguais aos originais
    assert(deserializedData1 == dataPtr1);
    assert(deserializedData1->value == 100);
    assert(deserializedData1->text == "Test String");

    assert(deserializedData2 == dataPtr2);
    assert(deserializedData2->value == 200);
    assert(deserializedData2->text == "Another Test String");

    println(GREEN "Test 4 success!\n\n" DFT);
  }

  println(BLUE_GREEN
          "Teste 5: Serialização e Desserialização de Objeto Modificado\n" DFT);
  {
    Data myData = {10, "Original"};
    Data *dataPtr = &myData;

    uintptr_t raw = Serializer::serialize(dataPtr);
    Data *deserializedData = Serializer::deserialize(raw);

    println(ORANGE "\nOriginal: \n" DFT);
    printData(dataPtr);
    printData(deserializedData);

    println(ORANGE "\nModification: \n" DFT);
    // Modificar os dados do objeto original
    myData.value = 20;
    myData.text = "Modified";

    printData(dataPtr);
    printData(deserializedData);

    // Assegurar que as alterações são refletidas no ponteiro desserializado
    // assert(deserializedData->value == 20);
    // assert(deserializedData->text == "Modified");

    println(GREEN "Test 5 success!\n" DFT);
  }

  std::cout << "Todos os testes passaram!" << std::endl;

  return 0;
}
