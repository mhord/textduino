#include<string>
#include "textduino.h"

DynamicItem::DynamicItem(String description, String name)
{
  _description = description;
  _name = name;
}

String DynamicItem::getDescription()
{
  return _description;
}

