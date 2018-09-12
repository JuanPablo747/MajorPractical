// 'guards' to prevent redeclaration of Panda class
#ifndef RIVERBANK_H
#define RIVERBANK_H

#include <string>

// no namespaces in include file!!!

// Class definition
class Riverbank
{
  animal* bankName;

 public:
  //Constructors
  Riverbank();
  Riverbank(std::string name);

  //getters
  // std::string getName();

  //setters
  // void changeAge(int aAge);

  //Destructor
  ~Riverbank();
};

#endif