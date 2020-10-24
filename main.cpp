#include <simdjson.h>
#include "serialize_json.h"

int main(int argc, char *argv[])
{
	simdjson::dom::parser parser;
	simdjson::dom::element tweets = parser.load("twitter.json");
	std::string string = serialize_json(tweets);
	std::cout << string << "\n";
	return 0;
}
