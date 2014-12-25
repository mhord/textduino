#ifndef __textduino_h_
#define __textduino_h_

/****************************************************************************
 * Definitions for the textduino library
 * 11 Dec 2014 - Mike Hord
 *
 * textduino implements a text adventure engine in C++. While it's intended
 * for the Arduino platform, it *should* compile against other platforms with
 * only fairly minor changes; e.g., storing strings in flash memory shouldn't
 * be necessary anymore.
 *
 * Anyway, hopefully it'll be fun for some folks. If you like it, drop me a 
 * note and let me know.
 *
 ***************************************************************************/

#ifndef ARDUINO
/* If we're not in Arduino-land, we're going to want to use the C++ native
 * string class. Sadly, the Lords of Arduino elected to make *their* string
 * class capitalized, so we'll want to use a typedef to make captial-S String
 * mean the same thing as little-s string. */
#include<string>
#include<deque>
using namespace std;
typedef string String;
#endif

class DynamicItem;
class StaticItem;
class MovementOption;

class Room
{
  public:
    Room(String description, MovementOption *exits);
    String getDescription();
    String parseCommand(String command);
    void addArtifact(DynamicItem *newArtifact);
    String listArtifacts();
  private:
    String _description;
    MovementOption *_exits;
    std::deque< DynamicItem* > _artifacts;
};

class DynamicItem
{
  public:
    DynamicItem(String description,
                String name);
    String getDescription();
  private:
    String _description;
    String _name;
};

class StaticItem
{
  public:
    StaticItem(String description,
               String name);
    String getDescription();
  private:
    String _description;
    String _name;
};

class MovementOption
{
  public:
    MovementOption(String description,
                   String name,
                   Room *nextRoom);
    String getDescription();
  private:
    String _description;
    String _name;
    Room *_nextRoom;
};

#endif

