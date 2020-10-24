#include <benchmark/benchmark.h>
#include <simdjson.h>
#include "serialize_json.h"

static void Serialize(benchmark::State& state)
{
	simdjson::dom::parser parser;
	simdjson::dom::element tweets = parser.load("twitter.json");
	for (auto _ : state)
	{
		std::string string = serialize_json(tweets);
	}
}
BENCHMARK(Serialize);

BENCHMARK_MAIN();
