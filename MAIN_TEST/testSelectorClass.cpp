#include <iostream>
#include "CSSselector.h"
#include "CSSselectorprint.h"

int main (int argc, char** argv){
	CSSselector test;
	test.setSelector(0, "html");
	test.nest(1, "specialHTML");
	test.selector(1, "class");
	test.pseudo("focus");
	test.attribute("me", ">", "you");

	test.media("screen");

	CSSselectorprint print;

	std::cout << print.formatSelector(test) << std::endl;
	std::cout << "Thank you!" << std::endl;


	return 0;
}
