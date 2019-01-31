const int r = 3;      //Declarando o pino red do led rgb
const int g = 4;      //Declarando o pino green do led rgb
const int b = 5;      //Declarando o pino blue do led rgb
int pinosensor = 2;   //Ligado ao pino "coletor" do sensor �ptico
int leitura;          //Armazena informa��es sobre a leitura do sensor
int count = 0;        //Declara o contador
void setup()
{

  //definindo saida 
  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(g, OUTPUT);

  //Definindo entrada
  pinMode(pinosensor, INPUT);   //Define o pino do sensor como entrada
  Serial.begin(9600);
}

void loop()
{
  //Le as informa��es do pino do sensor
  leitura = digitalRead(pinosensor);
  if (leitura != 1) {

    //Condi��o para led = vermelho
    if (count == 1) {
      digitalWrite(r, 1);
      digitalWrite(g, 0);
      digitalWrite(b, 0);
    }
    //Cond�ao para led = verde
    if (count == 2) {
      digitalWrite(r, 0);
      digitalWrite(g, 1);
      digitalWrite(b, 0);
    }
    //Condi��o para led = azul
    if (count == 3) {
      
      count = 0;              //Zerando o contador

      digitalWrite(r, 0);
      digitalWrite(g, 0);
      digitalWrite(b, 1);
    }

    count++;                  //Soma + 1 ao contador
    Serial.println(count);    //Imprime contador

    delay(300);               //Espera
  }
}