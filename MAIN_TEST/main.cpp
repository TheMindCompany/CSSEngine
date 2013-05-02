#include <iostream>
#include "CSStag.h"
#include "CSSselectorprint.h"

int main (int argc, char **argv){
	CSStag tagValue1;
	CSStag tagValue2;
	CSStag tagValue3;
	CSStag tagValue4;
	CSStag tagValue5;

	//CSStag tag1;
	//CSStag tag2;
	//CSStag tag3;
	//CSStag tag4;
	//CSStag tag5;

	std::string cssString1;
	std::string cssString2;
	std::string cssString3;
	std::string cssString4;
	std::string cssString5;

	CSSselectorprint printTagValue;
	CSSselectorprint printTag;

	//tag1.setSelector(0, "html");
	//tagValue1.setTag(1, "class1");
	//tagValue2.setTag(2, "id1");
	//tagValue3.setTag(3, "focus");
	tagValue4.setTag(6, "media");
	tagValue5.setTag(7, "<");

	//tag1.extend(tagValue1);
	//tag1.nest(tagValue2);
	//tag1.pseudo(tagValue3);

	//tag2.attribute(tag1);

	//tag3.media(tagValue4);

	//tag4.media("screen");

	//tag5.combinator(tag1);

	//cssString1 = printTag.formatTag(tag1);
	//cssString2 = printTag.formatTag(tag2);
	//cssString3 = printTag.formatTag(tag3);
	//cssString4 = printTag.formatTag(tag4);
	//cssString5 = printTag.formatTag(tag5);

	std::cout << cssString1 << std::endl;
	std::cout << cssString2 << std::endl;
	std::cout << cssString3 << std::endl;
	std::cout << cssString4 << std::endl;
	std::cout << cssString5 << std::endl;

	return 0;
}
