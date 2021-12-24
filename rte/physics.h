//
// Created by peter on 6/13/20.
//

#ifndef BRUX_GDK_PHYISICS_H
#define BRUX_GDK_PHYISICS_H
#include <chipmunk.h>
#include <vector>

class Phyisics
{
public:
	Phyisics();
	static int ChipMonkHelloWorld();
	void sceneStep();
	~Phyisics();
private:
	cpVect gravity;
	cpSpace *space;
	cpFloat timeStep;
	std::vector<cpBody*>  bodylist;
	std::vector<cpShape*> shapelist;
};

#endif //BRUX_GDK_PHYISICS_H
