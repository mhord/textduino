#include "textduino.h"
#include<string>
#include<iostream>

using namespace std;

int main()
{
  string description = "A spooky chandler's workshop";
  Room room0(description, NULL);

  string name = "Big ball of wax";
  description = "This ball of wax has bugs stuck in it."; 
  string command;

  room0.addArtifact(new DynamicItem(description, name));

  name = "Brass candle snuffer";
  description = "This old, bent candle snuffer is covered in blood.";
  room0.addArtifact(new DynamicItem(description, name));
  cout<<room0.listArtifacts();



  return 0;
}

