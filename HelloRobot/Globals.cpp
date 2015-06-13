#include "Globals.h"

Globals*  Globals::myGlobal=0;
Globals* Globals::getInstance()
{
	if(!myGlobal){

				myGlobal=new Globals();
			}
			return myGlobal;
}
