# Trabalho_ED
Trabalho Estrutura de dados

IDEIA:
Um sistema de gerenciamento de tarefas é uma ferramenta ou aplicavo de soware projetado para ajudar
indivíduos, equipes ou organizações a organizar, acompanhar e gerenciar as tarefas que precisam ser realizadas. Sendo
seu objevo principal melhorar a eficiência, a produvidade e o acompanhamento de projetos e avidade.
As Equipes de Desenvolvimento de Soware ulizam esse sistema para rastrear e priorizar as tarefas de
desenvolvimento, correção de bugs, testes e implantação de soware, sendo assim uma ferramenta essencial para
melhorar a eficiência, a colaboração e o acompanhamento de projetos. Ajudando também as equipes a se manterem
organizadas, a cumprir prazos e a entregar soware de alta qualidade de forma mais consistente
Esta avidade tem como objevo a elaboração simplificada de Sistema de Gerenciamento de Tarefas para
o controle as tarefas de uma Equipe de Desenvolvimento de Soware.
A vidade Avalia va 1 – Sistema de Gerenciamento de Projetos
Projeto:
Parte Básica
O Time deverá elaborar um Sistema de Gerenciamento de Tarefas considerando as seguintes Caracteríscas:
1. Informações das Tarefas a serem realizadas (Estrutura Tarefa):
• Código da Tarefa – número inteiro
• Nome da Tarefa – caractere de tamanho máximo 30
• Projeto – nome do projeto a que pertence a tarefa - caractere de tamanho máximo 30
• Data de Início – estrutura contendo dia, mês e ano como valores inteiros
• Data de Término – estrutura contendo dia, mês e ano como valores inteiros
• Status – define se a tarefa está atrasada ou em dia, pode ser considerado um valor inteiro sendo
1 atrasada e 0 em dia e -1 pendente
2. O sistema deverá ser constuído das seguintes funcionalidades
1. Adicionar uma nova Tarefa O usuário poderá adicionar uma nova Tarefa à fila de Tarefas, com
todas as suas informações
2. Modificar uma Tarefa. Dado o código de uma Tarefa, permite alteração dos dados inseridos de
uma tarefa
3. Concluir Tarefa – O usuário poderá marcar uma tarefa como concluída, a data de Término é
atualizada, o status de atrasada NÃO. A Fila de tarefas deve estar atualizada. As tarefas concluídas
são removidas para uma Lista encadeada de Tarefas Concluídas, ordenadas pela data de Término
4. Atualização do Status da Tarefa -
O status sobre a Tarefa estar atrasada ou não pode ser realizado automacamente pelo
sistema, comparando as datas atuais e de Término esperado
Dado o Código da Tarefa o Usuário poderá atualizar se a Tarefa está pendente ou não.
Considera-se uma Tarefa Pendente aquela que está necessitando de uma ação que independe da
Equipe de Desenvolvimento de Soware, como por exemplo uma decisão do “Dono do Projeto”.
Marcar uma tarefa como Pendente significa colocar status -1 para ela. As tarefas Pendentes saem
da fila de tarefas e entram em uma lista de tarefas pendentes que pode ser ordenada pela data
do término do projeto, o projeto que tem que terminar antes vem antes. Essas tarefas só voltam
par a fila quando a pendência é eliminada, indo para o final da fila.
5. Lista de Tarefas Pendentes - Imprime a Lista de Tarefas Pendentes,
6. Lista de Tarefas Concluídas - Imprime a Lista de Tarefas Concluídas
A vidade Avalia va 1 – Sistema de Gerenciamento de Projetos
7. Lista de Tarefas Concluídas com e sem Atrasos - imprime duas informações: Tarefas com atraso
e depois tarefas sem atrasos
8. Sair do Programa
O sistema deve ser amigável, ou seja, fácil compreensão e manipulação. Considere
como “Dono do Projeto” a professora
O sistema deve ser construído usando os conceitos de Filas e Listas vistos durante as
aulas, bem como os conceitos de bibliotecas e funções
Parte Avançada
Está parte consiste em aprimorar o sistema, tornando-o mais eficiente.
Suponha agora que a estrutura tarefa tenha mais um campo:
• Código da Tarefa – número inteiro
• Nome da Tarefa – caractere de tamanho máximo 30
• Projeto – nome do projeto a que pertence a tarefa - caractere de tamanho máximo 30
• Data de Início – estrutura contendo dia, mês e ano como valores inteiros
• Data de Término – estrutura contendo dia, mês e ano como valores inteiros
• Status – define se a tarefa está atrasada ou em dia, pode ser considerado um valor inteiro sendo
1 atrasada e 0 em dia e -1 pendente
• Prioridade da Tarefa – um valor inteiro de 1, 2, 3, sendo 1 Alta Prioridade, 2 Prioridade Normal e
3 Baixa Prioridade.
Com essa nova estrutura as funcionalidades do sistema deverão ser modificadas pois será necessário
haver 3 filas de tarefas, uma para cada prioridade. A Lista de Pendência pode ser somente Uma
Lista ordenada pela prioridade da mais alta para mais baixa e em cada prioridade ordenada pela
data de término.
