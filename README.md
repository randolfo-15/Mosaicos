Bem vindo ao Projeto Mosaicos
=============================

   Mosaicos é uma biblitéca cros-plataforma que visa oferecer um conjunto de ferramentas 
para facilitar o uso do recursos de termanal como sintaxe hinglight e coloração de 
backgrounds e foregrounds, através de objetos que simulam o compotamento destes componentes 

Mosaicos dispõe dos seguintes recursos
--------------------------------------

+ Suporte a exibição de mais de 16.000 mil cores.
+ Criar displays de contéudo textual.
+ Movimentar a posição do ponteiro de leitura do terminal.
+ Simmular teoria das cores com mistura e remoção de tons.

Donwload
========
O código fonte de mosaicos esta disponivel em [donwload](https://gitlab.com/Randolfo-15/Mosaicos.git)

Método de compilação
--------------------

Visando maximizar a ultilização da biblioteca usamos o cmake para construir a mesma
seguindo os seguintes passos:

1. Com o git clone o repositorio:
``` 
git clone https://gitlab.com/Randolfo-15/Mosaicos.git
```

2. Crie um diretorio para construir a biblioteca:
```
cmake -B build
```

Por padrão geramos uma biblioteca estatica com este comando:

3. Caso queira gerar um biblioteca dinâmica use:
```
cmake -B build -DSHARED_LIBRARY=ON
```
4. Instalação:
```
cmake --install build 
```
5. Após estes passos faça um hello_world:

``` c++
#include <Dp/display_rag.hpp>
#include <iostream>

using std::cout;

int main(){
   Dp dp;
   dp.title("...");
   dp.write("\nOla mundo\n");
   cout<<dp<<'\n';
   return 0;
}

```



