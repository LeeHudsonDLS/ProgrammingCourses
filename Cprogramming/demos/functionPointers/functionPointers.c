#include<stdio.h>
#include<stdlib.h>

#define BUTTON 0
#define MOUSE 1

typedef struct
{
	int eventType;
	void (*fp[2])(int); //An array of 2 pointers to functions that take an int and return a void
}Framework;
typedef void (*CALLBACK)(int);


Framework* createFramework()
{
	return (Framework*) malloc(sizeof(Framework)); // allocate some memory for a "Framework" and return a pointer to it
}

//registerCallback(Framework*, void(*pCallback)(int))// 2nd parameter is pointer to a funct that takes and int
						   // and returns a void
registerCallback(Framework*, CALLBACK, int);
void buttonPress(Framework*);
void mousePress(Framework*);
 
registerCallback(Framework* pFramework, CALLBACK pCallback, int type) 
{						    
	pFramework->fp[type] = pCallback;
	
}

void buttonPress(Framework* pFramework)
{
	pFramework->fp[BUTTON](5);
}

void mousePress(Framework* pFramework)
{
	pFramework->fp[MOUSE](1);
}


//User code below, framework code above.
void callbackA(int button)
{
	printf("Button %i pressed \n",button);	
}

void callbackB(int button)
{
	printf("Button %i pressed \n",button);	
}

int main(void)
{
	Framework* pFramework = createFramework();
	registerCallback(pFramework,callbackA,BUTTON);
	registerCallback(pFramework,callbackB,MOUSE);
	//Code here
	//Event occurs so we want a callback
	buttonPress(pFramework);
	mousePress(pFramework);
	free(pFramework);
	return 0;

}
