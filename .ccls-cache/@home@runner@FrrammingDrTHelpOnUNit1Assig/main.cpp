//Dr. T help on Unit 1 Assignment COSC-1437 Dr. Tyson McMillan, code
//Student: Linda Salazar
#include <iostream>
#include <iomanip>
#include <string>
#include "Input_Validation_Extended-2.h"
using namespace std; 

void showMenu(); 
void calcVelocity(); 
void calcAcceleration();
void calcMotion(); 
void calcNewton();
void calcWeight();
void calcMomentum();

double validateDouble(double &);


int main() 
{
  int choice = 0;
  do
  {
      showMenu(); // call the show menu function
      cin >> choice; 
      if(choice == 1)
      {
        calcVelocity(); //call the calcVelocity() function
      }
      else if(choice == 2)
      {
        calcAcceleration(); //call the calcAcceleration() function
      }
      else if(choice == 3)
      {
        calcMotion(); //call the calcMotion() function
      }
      else if(choice == 4)
      {
        calcNewton(); //call the calcNewton() function
      }
      else if(choice == 5)
      {
        calcWeight(); //call the calcWeight() function
      }
      else if(choice == 6)
      {
        calcMomentum(); //call the calcMomentum() function
      }
      else if(choice == 7)
      {
        cout << "\nGoodbye" << endl;
      }
      else // default clause
      {
        string reset = "\x1b[0m";
        cout << reset; 
        cout << "\033[2J\033[1;1H";
      }
  } while(choice != 7);
  
  
  return 0; 
}

void showMenu()
{
  cout << "Menu\n";
  cout << "1. calc velocity\n";
  cout << "2. calc acceleration\n";
  cout << "3. calc motion\n";
  cout << "4. calc newton's 2nd law\n";
  cout << "5. calc weight\n";
  cout << "6. calc momentum\n";
  cout << "7. Exit\n";
  cout << "8. clear screen\n";
  cout << "Enter your choice: ";
}

void calcVelocity()
{
  double ds = 0.0, dt = 0.0; // ds = ds (distance)
  cout << "Velocity Calculator\n";
  cout << "Enter ds (d = ds): ";
  ds = validateDouble(ds); // validate and accept ds 
  cout << "Enter dt (d = dt): ";
  dt = validateDouble(dt);
  cout << "Velocity = " << fixed << setprecision(4) << ds / dt << endl;
  
}
void calcAcceleration()
{
  double dv = 0.0, dt = 0.0;
  cout << "Acceleration Calculator\n";
  cout << "Enter dv (d = dv): ";
  dv = validateDouble(dv); // validate and accept dv
  cout << "Enter dt (d = dt): ";
  dt = validateDouble(dt);
  cout << "Acceleration = " << fixed << setprecision(4) << dv / dt << endl;
}

void calcMotion()
{
  char motionChoice = '\0';
  double Ma = 0.0, v0 = 0.0, a = 0.0, t = 0.0, v = 0.0, s = 0.0, s0 = 0.0;
  cout << "\nMotion Calculator Menu\n";
  cout << "A. Ma = solve for v" << endl;
  cout << "B. Ms = solve for s" << endl;
  cout << "C. Mv2 = solve for v^2" << endl;
  cout << "D. Mv = solve for v_bar" << endl;
  cout << "Option: ";
  cin >> motionChoice; 

  if(motionChoice == 'A' || motionChoice == 'a')
  {
    cout << "\nPlease enter v0: ";
    v0 = validateDouble(v0); 
    cout << "\nPlease enter a: ";
    a = validateDouble(a);
    cout << "\nPlease enter t: ";
    t = validateDouble(t); 
    v = v0 + (a * t); 
    cout << "\nVelocity = " << fixed << setprecision(4) << v << endl;
  }
  else if(motionChoice == 'b' || motionChoice == 'B')
  {
    cout << "\nPlease enter s0: ";
    s0 = validateDouble(s0);
    cout << "\nPlease enter v0: ";
    v0 = validateDouble(v0);
    cout << "\nPlease enter a: ";
    a = validateDouble(a);
    cout << "\nPlease enter t: ";
    t = validateDouble(t);
    s = s0 + v0 * t + (0.5 * a * t *t); //solve for Ms 
    cout << "\nDistance = " << fixed << setprecision(4) << s << endl;
  }
  else if(motionChoice == 'c' || motionChoice == 'C')
  {
    cout << "\nPlease enter v0: ";
    v0 = validateDouble(v0);
    cout << "\nPlease enter a: ";
    a = validateDouble(a);
    cout << "\nPlease enter s: ";
    s = validateDouble(s);
    cout << "\nPlease enter s0: ";
    s0 = validateDouble(s0);
    v = v0 * v0 + 2 * a * (s - s0); //solve for v^2
    cout << "\nSquared Velocity = " << fixed << setprecision(4) << v << endl;
  }
  else if(motionChoice == 'd' || motionChoice == 'D')
  {
    cout << "\nPlease enter v: ";
    v = validateDouble(v);
    cout << "\nPlease enter v0: ";
    v0 = validateDouble(v0);
    v = 0.5 * (v + v0);
    cout << "\nAverage Velocity = " << fixed << setprecision(4) << v << endl;
  }
  else
  {
    cout << "\nInvalid Input\n";
  }
}
void calcNewton()
{
  double m = 0.0, a = 0.0;
  cout << "\nNewton's 2nd law Calculator\n";
  cout << "Enter m: ";
  m = validateDouble(m);
  cout << "Enter a: ";
  a = validateDouble(a);
  cout << "Force = " << fixed << setprecision(4) << m * a << endl;
}
void calcWeight()
{
  double m = 0.0, g = 0.0;
  cout << "\nWeight Calculator\n";
  cout << "Enter m: ";
  m = validateDouble(m);
  cout << "Enter g: ";
  g = validateDouble(g);
  cout << "Weight = " << fixed << setprecision(4) << m * g << endl;
}
void calcMomentum()
{
  double m = 0.0, v = 0.0;
  cout << "\nMomentum Calculator\n";
  cout << "Enter m: ";
  m = validateDouble(m);
  cout << "Enter v: ";
  v = validateDouble(v);
  cout << "Momentum = " << fixed << setprecision(4) << m * v << endl;
}
