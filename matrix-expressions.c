
#define ROW1 13
#define ROW2 12
#define ROW3 11
#define ROW4 10
#define ROW5 9
#define ROW6 8
#define ROW7 7
#define ROW8 6

#define COL1 5
#define COL2 4
#define COL3 3
#define COL4 2
#define COL5 A4
#define COL6 A3
#define COL7 A2
#define COL8 A1

String face = "";
char caractere;

const int row[] = {ROW1, ROW2, ROW3, ROW4, ROW5, ROW6, ROW7, ROW8};
const int col[] = {COL1,COL2, COL3, COL4, COL5, COL6, COL7, COL8};

int Neutral[8][8] = {{1,1,1,1,1,1,1,1},
                     {1,1,1,0,0,1,1,1},
                     {1,1,0,0,0,0,1,1},
                     {1,1,0,0,0,0,1,1},
                     {1,1,0,0,0,0,1,1},
                     {1,1,0,0,0,0,1,1},
                     {1,1,1,0,0,1,1,1},
					 {1,1,1,1,1,1,1,1}};

int Sadness[8][8] = {{1,1,1,1,1,1,1,1},
                     {1,1,1,1,1,1,1,1},
                     {1,1,1,1,0,0,0,1},
                     {1,1,0,0,0,0,1,1},
                     {1,0,0,0,0,0,1,1},
                     {1,1,0,0,0,1,1,1},
                     {1,1,1,1,1,1,1,1},
                     {1,1,1,1,1,1,1,1}};

int Happiness[8][8] = {{1,1,1,1,1,1,1,1},
                       {1,1,1,1,1,1,1,1},
                       {1,1,1,0,0,0,1,1},
                       {1,1,0,0,0,0,0,1},
                       {1,1,0,1,1,0,0,1},
                       {1,1,1,1,1,1,1,1},
                       {1,1,1,1,1,1,1,1},
                       {1,1,1,1,1,1,1,1}};

int Madness[8][8] = {{1,1,1,1,1,1,1,1},
                     {1,1,0,1,1,1,1,1},
                     {1,1,0,0,1,1,1,1},
                     {1,1,0,0,0,1,1,1},
                     {1,1,0,0,0,0,1,1},
                     {1,1,0,0,0,0,0,1},
                     {1,1,1,0,0,0,1,1},
                     {1,1,1,1,1,1,1,1}};

int Danger[8][8] = {{1,0,0,0,0,0,0,1},
                    {1,1,0,0,0,0,1,1},
                    {1,1,0,0,0,0,1,1},
                    {1,1,1,0,0,1,1,1},
                    {1,1,1,1,1,1,1,1},
                    {1,1,1,0,0,1,1,1},
                    {1,1,1,0,0,1,1,1},
                    {1,1,1,1,1,1,1,1}};

void setup() {
  Serial.begin(9600);
  for (int i = 2; i <= 13; i++) {
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }
  pinMode(A1, OUTPUT);
  digitalWrite(A1, LOW);
  pinMode(A2, OUTPUT);
  digitalWrite(A2, LOW);
  pinMode(A3, OUTPUT);
  digitalWrite(A3, LOW);
  pinMode(A4, OUTPUT);
  digitalWrite(A4, LOW);
}

void loop() {
  while(Serial.available() > 0) {
    caractere = Serial.read();
    if (caractere != '\n'){
      face.concat(caractere);
    }
    delay(10);
  }
  
  if(face == "mad") {
    expression(Madness);
  }
  if(face == "happy") {
    expression(Happiness);
  }
  if(face == "neutral") {
    expression(Neutral);
  }
  if(face == "sad") {
    expression(Sadness);
  }
  if(face == "alert") {
    expression(Danger);
  }
}

void  expression(int matrix[8][8]){
  for (int i = 0; i < 8; i++){

    digitalWrite(col[i], HIGH);
    for (int c = 0; c < 8; c++){
      digitalWrite(row[c], matrix[c][i]);
    }
    for (int c = 0; c < 8; c++){
      digitalWrite(row[c], HIGH);
    }
  
    digitalWrite(col[i], LOW);
  }
}