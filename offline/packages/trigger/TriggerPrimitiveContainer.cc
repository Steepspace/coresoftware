
#include "TriggerPrimitiveContainer.h"

#include <cmath>
#include <iostream>

ClassImp(TriggerPrimitiveContainer)

TriggerPrimitiveContainer::TriggerPrimitiveContainer()
{
}
TriggerPrimitiveContainer::~TriggerPrimitiveContainer()
{

}

//______________________________________
void TriggerPrimitiveContainer::Reset()
{

}


//______________________________________
void TriggerPrimitiveContainer::identify(std::ostream& out) const
{
  out << "identify yourself: I am a TriggerPrimitiveContainer object" << std::endl;

}

int TriggerPrimitiveContainer::isValid() const
{
  return 1;
}
