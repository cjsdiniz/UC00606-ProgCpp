// Estação Meteorológica — UC00606
// Plataforma: Arduino Uno R3 (Tinkercad Simulator)

// ── Dados ────────────────────────────────────────────────
const int NUM_DADOS = 10;

float temperatura[NUM_DADOS];
float humidade[NUM_DADOS];
float velocidadeVento[NUM_DADOS];
bool  dadosCarregados = false;


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
//  Gera os arrays com valores aleatórios realistas
// ════════════════════════════════════════════════════════
void carregarDados() {
  randomSeed(millis());   // Seed diferente a cada chamada

  for (int i = 0; i < NUM_DADOS; i++) {
    temperatura[i]     = random(100, 360) / 10.0;  // 10.0 – 35.9 °C
    humidade[i]        = (float)random(40, 91);     // 40 – 90 %
    velocidadeVento[i] = random(0, 501)  / 10.0;   // 0.0 – 50.0 km/h
  }

  dadosCarregados = true;
  Serial.print(F("\n"));
  Serial.print(NUM_DADOS);
  Serial.println(F(" registos gerados aleatoriamente."));
}

// ════════════════════════════════════════════════════════
//  Mostra tabela, médias, classificação e leituras ao vivo
// ════════════════════════════════════════════════════════
void visualizarDados() {
  if (!dadosCarregados) {
    Serial.println(F("\nSem dados: execute a Opcao 1 primeiro."));
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

// ════════════════════════════════════════════════════════
void setup() {
  Serial.begin(9600);

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
      Serial.println(F("\nPrograma terminado. Ate breve!"));
      while (true);   // Termina execução
      break;
    default:
      Serial.println(F("Opcao invalida."));
      break;
  }
}
