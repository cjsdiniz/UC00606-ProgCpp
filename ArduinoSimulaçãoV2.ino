// Estação Meteorológica — UC00606
// Plataforma: Arduino Uno R3 (Tinkercad Simulator)

// ── Pinos ────────────────────────────────────────────────
const int PIN_TMP36    = A1;  // Sensor de temperatura TMP36
const int PIN_HUMIDADE = A0;  // Potenciómetro → humidade
const int PIN_ENCODER  = 2;   // Motor CC c/ codificador → vento (INT0)

// ── Dados ────────────────────────────────────────────────
const int NUM_DADOS = 10;

float temperatura[NUM_DADOS];
float humidade[NUM_DADOS];
float velocidadeVento[NUM_DADOS];
bool  dadosCarregados = false;

// Contador de impulsos do codificador (acedido pela ISR)
volatile int contadorPulsos = 0;

// ── Protótipos ───────────────────────────────────────────
void  mostrarMenu();
int   lerOpcao();
void  carregarDados();
void  visualizarDados();
float lerTMP36(int pino);
float lerHumidade(int pino);
float lerVelocidadeVento();
void  imprimirSeparador(int tamanho);

// ── ISR do codificador ───────────────────────────────────
void contarPulso() {
  contadorPulsos++;
}

// ════════════════════════════════════════════════════════
void setup() {
  Serial.begin(9600);
  pinMode(PIN_ENCODER, INPUT);
  attachInterrupt(digitalPinToInterrupt(PIN_ENCODER), contarPulso, RISING);

  Serial.println(F("===================================="));
  Serial.println(F("      ESTACAO METEOROLOGICA         "));
  Serial.println(F("===================================="));
}

// ════════════════════════════════════════════════════════
void loop() {
  mostrarMenu();
  int opcao = lerOpcao();

  switch (opcao) {
    case 1:
      carregarDados();
      break;
    case 2:
      visualizarDados();
      break;
    case 3:
      Serial.println(F("\nPrograma encerrado. Ate logo!"));
      while (true);   // Termina execução
      break;
    default:
      Serial.println(F("Opcao invalida."));
      break;
  }
}

// ════════════════════════════════════════════════════════
//  Mostra o menu de opções
// ════════════════════════════════════════════════════════
void mostrarMenu() {
  Serial.println(F("\n--- MENU ---"));
  Serial.println(F("1 - Carregar dados iniciais"));
  Serial.println(F("2 - Visualizar dados"));
  Serial.println(F("3 - Sair"));
  Serial.print(F("Escolha: "));
}

// ════════════════════════════════════════════════════════
//  Lê e valida a opção do utilizador (do-while + while)
// ════════════════════════════════════════════════════════
int lerOpcao() {
  int opcao = 0;

  do {
    while (Serial.available() == 0);   // Aguarda entrada

    opcao = Serial.parseInt();
    Serial.println(opcao);

    if (opcao < 1 || opcao > 3) {
      Serial.println(F("Invalido. Introduza 1, 2 ou 3:"));
    }
  } while (opcao < 1 || opcao > 3);

  return opcao;
}

// ════════════════════════════════════════════════════════
//  Carrega os arrays com valores iniciais realistas
// ════════════════════════════════════════════════════════
void carregarDados() {
  float tempInicial[NUM_DADOS]  = {18.5, 22.0, 25.3, 20.1, 15.8,
                                   19.4, 23.7, 27.2, 21.0, 17.3};
  float humInicial[NUM_DADOS]   = {65.0, 60.0, 55.0, 70.0, 75.0,
                                   68.0, 58.0, 50.0, 63.0, 72.0};
  float ventoInicial[NUM_DADOS] = { 5.0, 12.5,  8.0, 20.3,  3.5,
                                   15.0, 10.2, 25.0,  7.5, 18.0};

  for (int i = 0; i < NUM_DADOS; i++) {
    temperatura[i]     = tempInicial[i];
    humidade[i]        = humInicial[i];
    velocidadeVento[i] = ventoInicial[i];
  }

  dadosCarregados = true;
  Serial.print(F("\n"));
  Serial.print(NUM_DADOS);
  Serial.println(F(" registos carregados com sucesso."));
}

// ════════════════════════════════════════════════════════
//  Mostra tabela, médias, classificação e leituras ao vivo
// ════════════════════════════════════════════════════════
void visualizarDados() {
  if (!dadosCarregados) {
    Serial.println(F("\nErro: execute a Opcao 1 primeiro."));
    return;
  }

  imprimirSeparador(46);
  Serial.println(F("  #  | Temp (C) | Humidade (%) | Vento (km/h)"));
  imprimirSeparador(46);

  float somaTemp = 0.0, somaHum = 0.0, somaVento = 0.0;

  for (int i = 0; i < NUM_DADOS; i++) {
    Serial.print(F("  "));
    if (i + 1 < 10) Serial.print(F("0"));
    Serial.print(i + 1);
    Serial.print(F("  |   "));
    Serial.print(temperatura[i], 1);
    Serial.print(F("    |      "));
    Serial.print(humidade[i], 0);
    Serial.print(F("        |     "));
    Serial.println(velocidadeVento[i], 1);

    somaTemp  += temperatura[i];
    somaHum   += humidade[i];
    somaVento += velocidadeVento[i];
  }

  imprimirSeparador(46);

  float mediaTemp  = somaTemp  / NUM_DADOS;
  float mediaHum   = somaHum   / NUM_DADOS;
  float mediaVento = somaVento / NUM_DADOS;

  Serial.print(F("  Media Temperatura : ")); Serial.print(mediaTemp,  1); Serial.println(F(" C"));
  Serial.print(F("  Media Humidade    : ")); Serial.print(mediaHum,   0); Serial.println(F(" %"));
  Serial.print(F("  Media Vento       : ")); Serial.print(mediaVento, 1); Serial.println(F(" km/h"));

  // Classificação do vento (Escala de Beaufort simplificada)
  Serial.print(F("  Classificacao     : "));
  if (mediaVento < 5.0) {
    Serial.println(F("Calmo"));
  } else if (mediaVento < 20.0) {
    Serial.println(F("Brisa leve"));
  } else if (mediaVento < 40.0) {
    Serial.println(F("Vento moderado"));
  } else {
    Serial.println(F("Vento forte"));
  }

  // ── Leituras ao vivo dos sensores ────────────────────
  Serial.println(F("\n  [Sensores ao vivo]"));

  float tempAtual  = lerTMP36(PIN_TMP36);
  float humAtual   = lerHumidade(PIN_HUMIDADE);
  float ventoAtual = lerVelocidadeVento();

  Serial.print(F("  TMP36        : ")); Serial.print(tempAtual,  1); Serial.println(F(" C"));
  Serial.print(F("  Potenciometro: ")); Serial.print(humAtual,   0); Serial.println(F(" %"));
  Serial.print(F("  Codificador  : ")); Serial.print(ventoAtual, 1); Serial.println(F(" km/h"));
}

// ════════════════════════════════════════════════════════
//  Lê o TMP36 e converte para graus Celsius
// ════════════════════════════════════════════════════════
float lerTMP36(int pino) {
  int   raw  = analogRead(pino);
  float volt = raw * (5.0 / 1024.0);
  return (volt - 0.5) * 100.0;
}

// ════════════════════════════════════════════════════════
//  Lê o potenciómetro e mapeia para 0–100 %
// ════════════════════════════════════════════════════════
float lerHumidade(int pino) {
  int raw = analogRead(pino);
  return (float)map(raw, 0, 1023, 0, 100);
}

// ════════════════════════════════════════════════════════
//  Conta impulsos do codificador durante 1 s → km/h
//  (20 impulsos/rotação, perímetro do anemómetro ≈ 0,5 m)
// ════════════════════════════════════════════════════════
float lerVelocidadeVento() {
  contadorPulsos = 0;
  delay(1000);
  float rps = contadorPulsos / 20.0;
  return rps * 0.5 * 3.6;
}

// ════════════════════════════════════════════════════════
//  Imprime uma linha separadora de 'tamanho' caracteres
// ════════════════════════════════════════════════════════
void imprimirSeparador(int tamanho) {
  for (int i = 0; i < tamanho; i++) {
    Serial.print(F("-"));
  }
  Serial.println();
}
