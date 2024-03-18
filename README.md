# Jogo da Forca

 Projeto desenvolvido durante o segundo semestre de Engenharia da Computação com o objetivo de reunir um grupo para criar coletivamente um jogo da forca programado em C. Para a aprovação do projeto, era necessário incluir as principais mecânicas: escolha da letra, exibição do número de erros e leitura da palavra a ser adivinhada, particularmente, fui responsável pelos arquivos: "arquivos.h", "menu.h", "main.c" e também pelos arquivos de texto. Além disso, funcionalidades para ler e salvar em arquivos.

## Funcionalidades

**Modos de Jogo**

 Foi adicionada a possibilidade de jogar tanto sozinho quanto em dupla. Caso o usuário escolha jogar sozinho, três opções de dificuldade serão apresentadas para que ele escolha. No caso de jogar com outra pessoa, um dos jogadores digitará uma palavra enquanto o outro tentará adivinhar.

**Opções de Dificuldade**

Caso o usuário escolher jogar sozinho foram incluídas três opções de dificuldade: Fácil, Médio e Difícil. Após a escolha, o jogo lerá aleatoriamente dos arquivos uma palavra contida na dificuldade selecionada.

**Modos de Chute**

 Existem dois modos possíveis para a adivinhação: Letra por letra ou Chute direto. Se o jogador escolher Letra por letra, precisará digitar uma letra para tentar adivinhar a palavra. Caso erre, o desenho será formado, indicando que o jogador perdeu uma vida. Se acertar, a palavra será preenchida com a respectiva letra. No modo Chute direto, o jogador tem apenas uma chance de acertar a palavra completa. Se acertar, vence o jogo; caso contrário, perde.
