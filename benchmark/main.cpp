#include <string>

#include "benchmark/benchmark.h"

#include "liblettercase/ExceptionWords.h"
#include "liblettercase/lettercase_conversions.h"

using namespace lettercase;

static void BM_ToUpperCase(benchmark::State& state) {
    std::string text = "The point is to get more experience with ranges and the STL.";

    for (auto _ : state)
        to_uppercase(text);
}
// Register the function as a benchmark
BENCHMARK(BM_ToUpperCase);

static void BM_ToUpperCaseComplexity(benchmark::State& state) {
    std::string text(state.range(0), 'a');

    for (auto _ : state)
        to_uppercase(text);

    state.SetComplexityN(state.range(0));
}
// Register the function as a benchmark
BENCHMARK(BM_ToUpperCaseComplexity)->Range(1<<10, 1<<18)->Complexity(benchmark::oAuto);

static void BM_ToLowerCase(benchmark::State& state) {
    std::string text = "The point is to get more experience with ranges and the STL.";

    for (auto _ : state)
        to_lowercase(text);
}
BENCHMARK(BM_ToLowerCase);

static void BM_ToSnakeCase(benchmark::State& state) {
    std::string text = "The point is to get more experience with ranges and the STL.";

    for (auto _ : state)
        to_snake_case(text);
}
BENCHMARK(BM_ToSnakeCase);

static void BM_ToCamelCase(benchmark::State& state) {
    std::string text = "The point is to get more experience with ranges and the STL.";

    for (auto _ : state)
        to_camelcase(text);
}
BENCHMARK(BM_ToCamelCase);

static void BM_ToStartCase(benchmark::State& state) {
    std::string text = "The point is to get more experience with ranges and the STL.";

    for (auto _ : state)
        to_startcase(text);
}
BENCHMARK(BM_ToStartCase);

static void BM_ToTitleCaseIntactAbbreviations(benchmark::State& state) {
    std::string text = "The point is to get more experience with ranges and the STL.";
    auto wordList = ExceptionWords();

    for (auto _ : state)
        to_titlecase(text, wordList, true);
}
BENCHMARK(BM_ToTitleCaseIntactAbbreviations);

static void BM_ToTitleCaseBreakAbbreviations(benchmark::State& state) {
    std::string text = "The point is to get more experience with ranges and the STL.";
    auto wordList = ExceptionWords();

    for (auto _ : state)
        to_titlecase(text, wordList, false);
}
BENCHMARK(BM_ToTitleCaseBreakAbbreviations);

BENCHMARK_MAIN();