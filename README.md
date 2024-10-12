# Arduino-ESP32

## Projeto de Monitoramento com ESP32: Sensor de Temperatura, Umidade e Distância
Este projeto utiliza um microcontrolador ESP32 para monitorar temperatura, umidade e distância, acionando LEDs conforme os valores dos sensores. O código também fornece alertas na porta serial e pode ser usado para fins de aprendizado em sistemas de monitoramento e automação.

## Sumário
-Introdução
-Funcionalidades
-Materiais Necessários
-Configuração do Hardware
-Instalação e Execução do Código
-Explicação do Código
-Contribuição
-Licença

## Introdução
Este projeto implementa um sistema que lê valores de temperatura, umidade e distância usando um sensor DHT22 e um sensor ultrassônico HC-SR04. Dependendo dos valores lidos, diferentes LEDs são acionados para indicar condições específicas de temperatura e proximidade de objetos.

## Funcionalidades
1. Leitura de Temperatura e Umidade: Usando o sensor DHT22.
2. Leitura de Distância: Usando o sensor ultrassônico HC-SR04.
3. Controle de LEDs de Temperatura:
  Azul: Temperatura menor que 10°C.
  Amarelo: Temperatura entre 11°C e 26°C.
  Vermelho: Temperatura maior que 27°C.
4. Controle de LEDs de Distância:
  Ciano: Distância entre 1 e 3.9 metros.
  Ciano e Laranja: Distância menor que 1 metro (com alerta na Serial).
5. Mensagens na Serial: Exibe leituras dos sensores e um alerta quando a distância é muito curta.

## Materiais Necessários
1 ESP32
1 Sensor DHT22
1 Sensor Ultrassônico HC-SR04
LEDs:
  Azul
  Amarelo
  Vermelho
  Ciano
  Laranja
Resistores (220Ω a 330Ω)
Jumpers e Breadboard

## Configuração do Hardware
1. Conexão do Sensor DHT22:
  VCC ao pino 3.3V do ESP32.
  GND ao GND do ESP32.
  Data ao pino D15 do ESP32.

2. Conexão do Sensor Ultrassônico HC-SR04:
  VCC ao pino 5V do ESP32.
  GND ao GND do ESP32.
  TRIG ao pino D5 do ESP32.
  ECHO ao pino D18 do ESP32.

## Conexão dos LEDs:
  Azul: Conecte o ânodo ao pino D4 (com resistor de 220Ω).
  Amarelo: Conecte o ânodo ao pino D16 (com resistor de 220Ω).
  Vermelho: Conecte o ânodo ao pino D17 (com resistor de 220Ω).
  Ciano: Conecte o ânodo ao pino D19 (com resistor de 220Ω).
  Laranja: Conecte o ânodo ao pino D21 (com resistor de 220Ω).
  Conecte todos os cátodos ao GND.

## Instalação e Execução do Código
1. Instale a biblioteca do sensor DHT:
  No Arduino IDE, vá em Ferramentas > Gerenciar Bibliotecas e procure por DHT Sensor Library, depois instale.

2. Carregue o Código no ESP32:
  Conecte o ESP32 ao seu computador.
  Copie o código fornecido e carregue-o usando o Arduino IDE.

3. Abra o Monitor Serial:
Configure a velocidade da porta Serial para 115200 baud no Monitor Serial para visualizar as leituras e mensagens de alerta.

## Explicação do Código
O código é dividido em funções que facilitam a leitura e controle dos sensores e LEDs:
  readAndPrintTemperatureHumidity(): Lê e imprime a temperatura e umidade, e aciona os LEDs Azul, Amarelo ou Vermelho com base nos valores lidos.
  readAndPrintDistance(): Lê e imprime a distância, e aciona os LEDs Ciano e Laranja dependendo da proximidade.
  controlTemperatureLEDs(): Função auxiliar para o controle de LEDs de temperatura.
  controlDistanceLEDs(): Função auxiliar para o controle de LEDs de distância e exibição de mensagem de alerta.

## Contribuição
Contribuições são bem-vindas! Sinta-se à vontade para abrir um problema ou enviar um pull request para melhorias.

## Licença
Este projeto é licenciado sob a Licença MIT - consulte o arquivo LICENSE para mais detalhes.
