# 📚 SisyphusBiblio

Sistema de gerenciamento de biblioteca desenvolvido em Linguagem C para controle de acervo, usuários, empréstimos e devoluções.

## 📖 Sobre o Projeto

O SisyphusBiblio foi desenvolvido com o objetivo de auxiliar bibliotecas no gerenciamento de seus livros e usuários, permitindo o controle de empréstimos, devoluções e consultas ao acervo de forma organizada e eficiente.

O sistema busca substituir processos manuais de registro, reduzindo erros e facilitando o acesso às informações da biblioteca.

## 🎯 Objetivo

Desenvolver uma aplicação em linguagem C capaz de:

* Gerenciar livros do acervo.
* Gerenciar usuários da biblioteca.
* Controlar empréstimos de livros.
* Registrar devoluções.
* Consultar disponibilidade de exemplares.
* Visualizar histórico de empréstimos.
* Persistir informações em arquivos texto.

## 🚀 Funcionalidades

### 📚 Gerenciamento de Livros

* Cadastro de livros.
* Consulta de livros.
* Busca por título.
* Busca por autor.
* Alteração de informações.
* Ativação e inativação de registros.

### 👤 Gerenciamento de Usuários

* Cadastro de usuários.
* Consulta de usuários.
* Busca por CPF.
* Alteração de informações.
* Ativação e inativação de usuários.

### 🔄 Empréstimos

* Registro de empréstimos.
* Verificação de disponibilidade.
* Atualização automática da quantidade de exemplares.
* Controle de status do empréstimo.

### 📥 Devoluções

* Registro de devoluções.
* Atualização automática do estoque de exemplares.
* Encerramento de empréstimos ativos.

### 📊 Histórico

* Visualização de empréstimos realizados.
* Consulta por usuário.
* Consulta por livro.
* Exibição em formato de tabela.

## 🏗️ Estrutura do Sistema

O sistema é composto pelas seguintes entidades:

### Livro

* Código
* Título
* Autor
* Editora
* Categoria
* Ano de Publicação
* Quantidade de Exemplares
* Localização
* Status

### Usuário

* Código
* Nome
* CPF
* Telefone
* E-mail
* Status

### Empréstimo

* Código do Empréstimo
* Código do Usuário
* Código do Livro
* Data do Empréstimo
* Data Prevista para Devolução
* Status

### Devolução

* Código da Devolução
* Código do Empréstimo
* Data da Devolução
* Status

## 🛠️ Tecnologias Utilizadas

* Linguagem C
* Estruturas (struct)
* Funções
* Vetores
* Arquivos TXT
* Controle de fluxo (if, else, switch)
* Estruturas de repetição (for, while, do while)

## 📂 Estrutura do Projeto

```text
SisyphusBiblio/
│
├── src/
│   ├── livros.c
│   ├── usuarios.c
│   ├── emprestimos.c
│   ├── devolucoes.c
│   └── main.c
│
├── data/
│   ├── livros.txt
│   ├── usuarios.txt
│   ├── emprestimos.txt
│   └── devolucoes.txt
│
├── docs/
│   ├── levantamento_requisitos.pdf
│   └── diagramas
│
└── README.md
```

## 💾 Persistência de Dados

Os dados serão armazenados em arquivos texto para garantir que as informações permaneçam disponíveis mesmo após o encerramento da aplicação.

## 📌 Requisitos Funcionais

* Cadastro de livros.
* Cadastro de usuários.
* Registro de empréstimos.
* Registro de devoluções.
* Consulta de acervo.
* Visualização de histórico.

## 📌 Requisitos Não Funcionais

* Interface simples via terminal.
* Tempo de resposta adequado.
* Validação de campos obrigatórios.
* Integridade dos dados.
* Persistência das informações.

## 🎓 Projeto Acadêmico

Projeto desenvolvido para a disciplina de Programação em Linguagem C, com foco na aplicação de estruturas de dados básicas, modularização, manipulação de arquivos.

## 📄⚠️ Licença

Projeto desenvolvido exclusivamente para fins educacionais.
