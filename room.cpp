#include<string>
#include<iostream>
#include "textduino.h"

using std::cout;
using std::endl;

Room::Room(String description, MovementOption *exits)
{
  _description = description;
  _exits = exits;
}

String Room::getDescription()
{
  return _description;
}

String Room::parseCommand(String command)
{
  String retval = "";
  return retval;
}

void Room::addArtifact(DynamicItem *newArtifact)
{
  _artifacts.push_front(newArtifact);
}

String Room::listArtifacts()
{
  static deque< DynamicItem* >::iterator currIterator = _artifacts.begin();
  static deque< DynamicItem* >::iterator endIterator = _artifacts.end();
  if (_artifacts.empty())
  {
    return NULL;
  }
  else
  {
    do
    {
      cout<<(*currIterator)->getDescription()<<endl;
      currIterator++;
    } while (currIterator != endIterator);
  }
  return "Done iterating!";
}


