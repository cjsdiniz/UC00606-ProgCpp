# Estação Meteorológica — UC00606

Projecto da unidade curricular **UC00606 — Programação em C++**, implementado em Arduino C++ para o simulador **Tinkercad** (Arduino Uno R3).

## Descrição

Simula uma estação meteorológica interactiva com três sensores virtuais, controlada via Serial Monitor. O utilizador interage através de um menu de texto que permite carregar e visualizar os dados recolhidos.

## Sensores simulados

| Sensor | Pino | Grandeza |
|--------|------|----------|
| TMP36 | A1 | Temperatura (°C) |
| Potenciómetro | A0 | Humidade relativa (%) |
| Motor CC com Codificador | D2 (INT0) | Velocidade do vento (km/h) |

## Funcionamento

O programa arranca e apresenta um menu no Serial Monitor com três opções:

```
--- MENU ---
1 - Carregar dados iniciais
2 - Visualizar dados
3 - Sair
```

**Opção 1 — Carregar dados:** preenche os arrays com 10 registos de valores realistas de temperatura (15–27 °C), humidade (50–75 %) e vento (3,5–25 km/h).

**Opção 2 — Visualizar dados:** apresenta uma tabela formatada com todos os registos, calcula as médias, classifica o vento segundo a Escala de Beaufort simplificada e mostra leituras ao vivo dos três sensores.

**Opção 3 — Sair:** encerra o programa.

## Fórmulas de conversão

**TMP36 → °C**
```cpp
float volt = analogRead(A1) * (5.0 / 1024.0);
float tempC = (volt - 0.5) * 100.0;
```

**Potenciómetro → Humidade (%)**
```cpp
float hum = map(analogRead(A0), 0, 1023, 0, 100);
```

**Codificador → Velocidade do vento (km/h)**
```cpp
// 20 impulsos/rotação | perímetro do anemómetro ≈ 0,5 m
float rps = contadorPulsos / 20.0;   // rotações por segundo
float kmh = rps * 0.5 * 3.6;
```

## Construções C++ utilizadas

| Requisito | Onde é aplicado |
|-----------|----------------|
| `if / else` | Classificação do vento; validação de dados carregados |
| `switch / case` | Despacho das opções do menu |
| Arrays | `temperatura[]`, `humidade[]`, `velocidadeVento[]` |
| Ciclo `for` | Preenchimento e impressão dos arrays |
| Ciclo `do-while` + `while` | Validação da entrada do utilizador em `lerOpcao()` |
| Função com retorno | `lerTMP36()`, `lerHumidade()`, `lerVelocidadeVento()`, `lerOpcao()` |
| Função sem retorno | `mostrarMenu()`, `visualizarDados()`, `carregarDados()` |
| Função com parâmetros | `lerTMP36(int pino)`, `lerHumidade(int pino)`, `imprimirSeparador(int tamanho)` |
| Interrupção (ISR) | `contarPulso()` — conta impulsos do codificador em `INT0` |

## Estrutura do projecto

```
UC00606-ProgC++/
├── ArduinoSimulação.ino    # Código principal (entrega)
├── ArduinoSimulaçãoV2.ino  # Versão em desenvolvimento
├── PRD.md                  # Requisitos do projecto
├── sensores.md             # Notas sobre os sensores Tinkercad
├── codigoexemplo.md        # Exemplos de referência
└── CLAUDE.md               # Configuração do assistente de código
```

## Como executar no Tinkercad

1. Acede a [tinkercad.com](https://www.tinkercad.com/) e cria um novo circuito.
2. Adiciona os componentes: Arduino Uno R3, TMP36, potenciómetro e motor CC com codificador.
3. Liga o TMP36 ao pino **A1**, o potenciómetro ao pino **A0** e o sinal do codificador ao pino **D2**.
4. Cola o conteúdo de `ArduinoSimulação.ino` no editor de código do Tinkercad.
5. Inicia a simulação e abre o **Serial Monitor** (9600 baud).
6. Interage com o menu introduzindo `1`, `2` ou `3`.

## Unidade Curricular

**UC00606 — Microcontroladores / Programação em C++ com Arduino**
