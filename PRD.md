# Microcontroladores - Programação Arduíno - UC00606-ProgC++


## Projecto
Projeto (programa) para ser executado no simulador Tinkedcad (https://www.tinkercad.com/) para Arduino Uno R3.


## Visão geral
Desenvolvar um projeto original e funcional, mostrando capacidade de aplicar os conceitos de Programação Arduíno aprendidos ao longo da UC, com criatividade e clareza. 
O programa deve ser interativo (via Monitor Série).


## Objectivo
Pretende-se que o programa leia os dados fornecidos pelos sensores:
- sensor TMP36, para dados da temperatura;
- Potenciómetro: para obter dados simulados de humidade;
- Motor CC com Codificador: para obter dados simulados de velocidade do vento (simulando o funcionamento de um anemometro);

Como os dados são simulados e não obtidos de sensores reais os dados devem ser obtidos da seguinte forma:
- Dados de temperatura: definir uma lista inicial de valores de temperatura, mas baseados em temperaturas ambientes reais;
- Dados de humidade: definir uma lista inicial de valores de humidade, mas coerente com os valores da temperatura;
- Dados de velocidade do vento: definir uma lista inicial de valores de velocidade do vento;


## Requisitos gerais obrigatórios do código:
Utilizar:
• Linguagem: C++
• Estruturas Condicionais – If/Else
• Estrutura Switch Case
• Arrays
• Ciclos – (For e While ou Do While)
• Interações com o utilizador – Via Serial Monitor.
• funções – Com retorno, sem retorno ou que recebem parâmetros

Todos os requisitos devem ser aplicados de forma prática no projeto. 
Não basta declarar uma função sem que haja interação funcional.
Com o ficheiro do programa (.ino), deve também ser entregue um relatório com:
• Descrição do projeto e Funcionamento geral (como o programa trabalha);
• Lógica utilizada (explicação simples);
• Estruturas usadas (onde aplicou cada conceito);
• Exemplo de utilização (inputs e outputs);
• Dificuldades e melhorias.


#Requisitos do formato do código e do ficheiro
## Formato
Utilizar o seguinte template para a estrutura do programa:

void setup() {
  Serial.begin(9600);
	(...)
}
void loop() {
	(...)
}

## Ficheiro
O ficheiro com o código deverá ser gravado com o nome "ArduinoSimulação.ino"


## Requisitos funcionais do código:

- Devem ser criadas as listas iniciais (temperatura, humidade e velocidade do vento); 
- Deve ser criado um menu que permita ao utilizador as seguintes opções:
	- Opção 1: Carregar dados iniciais, onde serão carregados os dados nas listas;
	- Opção 2: Visualizar os dados de temperatura, humidade e velocidade do vento;
	- Opção 3: Sair do programa;


## Tipos de sensores a utilizar
Sensor Tinkercad | Justificação da simulação
--------|-----------
TMP36 | Utilizar o TMP36 para a temperatura 
Potenciómetro | Para simular valores variáveis de pressão barométrica ou humidade através de entrada analógica.
Motor CC com Codificador | Simula um Anemómetro (para ler a Velocidade do Vento) e a rotação do vento. Pode ler as «RPM» ou os impulsos do codificador para representar a velocidade do vento.

