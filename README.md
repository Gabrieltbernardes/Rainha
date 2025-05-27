# 🧠 Problema das N-Rainhas — Solução em C

Este projeto implementa a resolução do **Problema das N-Rainhas** usando **backtracking**. O objetivo é posicionar N rainhas em um tabuleiro de dimensão N×N de forma que nenhuma delas se ataque — ou seja, nenhuma rainha pode estar na mesma linha, coluna ou diagonal que outra.

---

## 📌 Sobre o Projeto

O código resolve o problema de forma recursiva, utilizando busca em profundidade com retrocesso (*backtracking*), e imprime a **primeira solução válida encontrada**.

---

## 🧩 Como Funciona

- O algoritmo tenta colocar uma rainha por linha.
- Antes de posicionar, verifica:
  - Se há alguma rainha na **mesma coluna**.
  - Se há alguma rainha na **diagonal principal**.
  - Se há alguma rainha na **diagonal secundária**.
- Se for seguro, coloca a rainha e avança para a próxima linha.
- Se não houver solução para a posição atual, o algoritmo volta uma etapa (backtracking).

---

## 💻 Exemplo de Execução

Digite o tamanho do tabuleiro (N): 4<br>
0 0 1 0<br>
1 0 0 0<br>
0 0 0 1<br>
0 1 0 0
