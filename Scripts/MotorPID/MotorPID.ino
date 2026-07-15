#include<PID_v1.h>

// Pin declaration
const int M1_PWM = 25;
const int M1_dir1 = 26;
const int M1_dir2 = 27;
const int M1_encoderA = 34;
const int M1_encoderB = 35;

// PID variables
double rpmVelocity = 100;
double input = 0;
double output = 0;

// PID parameters (TODO: Adjust)
double kp = 2.0, ki = 5.0, kd = 1.0;

// PID objects
PID M1_PID(&input, &output, &rpmVelocity, kp, ki, kd, DIRECT);

// Encoder variables
volatile long encoderCount = 0;
long lastCount = 0;
unsigned long lastTime = 0;
const int PPR = 200;          // TODO: Check pulses per revolution and substitute value

void setup()
{
  Serial.begin(115200);

  // Pin setup
  pinMode(M1_PWM, OUTPUT);
  pinMode(M1_dir1, OUTPUT);
  pinMode(M1_dir2, OUTPUT);
  pinMode(M1_encoderA, OUTPUT);
  pinMode(M1_encoderB, OUTPUT);

  // Encoder interruptions
  attachInterrupt(digitalPinToInterrupt(M1_encoderA), readEncoder, CHANGE);

  // PID setup
  M1_PID.SetMode(AUTOMATIC);
  M1_PID.SetOutputLimits(-255, 255);
  M1_PID.SetSampleTime(100);

  Serial.println("Control PID inicializado");
}

void readEncoder()
{
  bool A = digitalRead(M1_encoderA);
  bool B = digitalRead(M1_encoderB);
  
  if(A == B)
  {
    encoderCount++;
  }
  else
  {
    encoderCount--;
  }
}

void calculateSpeed()
{
  unsigned long currentTime = millis();
  long currentCount = encoderCount;

  if(currentTime -lastTime >= 100)
  {
    long deltaCount = currentCount - lastCount;
    unsigned long deltaTime = currentTime - lastTime;

    // RPM 
    input = (deltaCount * 60000.0) / (PPR * deltaTime);

    lastCount = currentCount;
    lastTime = currentTime;
  }
}

void controlMotor(double pwmValue) 
{
  // Determinar dirección
  if(pwmValue > 0) 
  {
    digitalWrite(M1_dir1, HIGH);
    digitalWrite(M1_dir2, LOW);
    analogWrite(M1_PWM, abs(pwmValue));
  } 
  else if (pwmValue < 0) 
  {
    digitalWrite(M1_dir1, LOW);
    digitalWrite(M1_dir2, HIGH);
    analogWrite(M1_PWM, abs(pwmValue));
  } 
  else 
  {
    digitalWrite(M1_dir1, LOW);
    digitalWrite(M1_dir2, LOW);
    analogWrite(M1_PWM, 0);
  }
}

void loop() 
{
  // Calcular velocidad actual (RPM)
  calculateSpeed();
    
  // Ejecutar PID
  M1_PID.Compute();
    
  // Aplicar salida al motor
  controlMotor(output);
    
  // Mostrar datos cada segundo
  static unsigned long lastPrint = 0;
  if (millis() - lastPrint >= 1000) 
  {
    Serial.printf("Setpoint: %.2f | Velocidad: %.2f | Salida: %.2f\n", rpmVelocity, input, output);
    lastPrint = millis();
  }
    
  delay(10);
}