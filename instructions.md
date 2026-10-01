# Exercício 1 (E1) - Análise Léxica

## Instruções para Configuração do Repositório da Equipe

Este exercício possui duas partes (Parte 1 e Parte 2). 
O trabalho deve ser feito em equipe. 
Siga os passos abaixo rigorosamente para configurar o ambiente do seu grupo:

### 1. Criar o Repositório Privado da Equipe
1. Um dos membros da equipe deve acessar o GitHub e criar um novo repositório.
2. Configure o repositório como **Private** (Privado).
3. **Não** adicione README, .gitignore ou licença (deixe o repositório completamente vazio).
4. Nomeie o repositório seguindo o padrão: `MATA61-E1-Grupo-X` (substitua X pelo nome do seu grupo).

### 2. Importar o Conteúdo da Especificação
Abra o terminal na sua máquina e execute os seguintes comandos para clonar o repositório da disciplina e empurrá-lo para o repositório privado do seu grupo:

```bash
# Clone o repositório base da disciplina usando a opção --bare
git clone --bare https://github.com/MATA61-20262/E1.git

# Acesse a pasta criada
cd E1.git

# Envie o conteúdo para o novo repositório privado do seu grupo
# (Substitua a URL abaixo pela URL do repositório que seu grupo criou)
git push --mirror https://github.com

# Apague a pasta temporária E1.git da sua máquina
cd ..
rm -rf E1.git
```

Agora, **clone o repositório privado do seu grupo* normalmente na sua máquina para começar a trabalhar.

### 3. Adicionar a Professora e a Equipe
1. No repositório privado do grupo, vá em **Settings** > **Collaborators** > **Add people**.
2. Adicione os outros membros da equipe.
3. Adicione o usuário da professora: `christinaflachufba`.

---

## Como Entregar as Partes 1 e 2

Para facilitar a correção, **não faça commits diretamente na branch `main`**. Use o fluxo de Pull Requests (PR):

### Entrega da Parte 1:
1. Criem uma branch chamada `parte-1` (`git checkout -b parte-1`).
2. Desenvolvam a solução da primeira parte nesta branch.
3. Abram um **Pull Request** da branch `parte-1` para a branch `main` dentro do próprio repositório de vocês.
4. **Não deem "Merge" no PR!** 
O link desse Pull Request aberto será a entrega de vocês na plataforma da disciplina.
A professora usará este PR para comentar no código e dar a nota.

### Entrega da Parte 2:
1. Criem uma nova branch a partir da `main` chamada `parte-2` (`git checkout -b parte-2`).
2. Desenvolvam a segunda parte, seguindo as instruções no README.md de E1.
3. Abram um novo **Pull Request** da branch `parte-2` para a branch `main`.
4. Deixem o PR aberto para a correção da professora.

