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
BENCHMARK(BM_ToUpperCase);

static void BM_ToUpperCase_Complexity(benchmark::State& state) {
    std::string text(state.range(0), 'a');

    for (auto _ : state)
        to_uppercase(text);

    state.SetComplexityN(state.range(0));
}
BENCHMARK(BM_ToUpperCase_Complexity)->RangeMultiplier(2)->Range(2, 1<<16)->Complexity(benchmark::oAuto);

static void BM_ToUpperCase_InPlace(benchmark::State& state) {
    std::string text = "The point is to get more experience with ranges and the STL.";

    for (auto _ : state)
        to_uppercase_inplace(text);
}
BENCHMARK(BM_ToUpperCase_InPlace);

static void BM_ToUpperCase_InPlace_Complexity(benchmark::State& state) {
    std::string text(state.range(0), 'a');

    for (auto _ : state)
        to_uppercase_inplace(text);

    state.SetComplexityN(state.range(0));
}
BENCHMARK(BM_ToUpperCase_InPlace_Complexity)->RangeMultiplier(2)->Range(2, 1<<16)->Complexity(benchmark::oAuto);

static void BM_ToLowerCase(benchmark::State& state) {
    std::string text = "The point is to get more experience with ranges and the STL.";

    for (auto _ : state)
        to_lowercase(text);
}
BENCHMARK(BM_ToLowerCase);

static void BM_ToLowerCase_Complexity(benchmark::State& state) {
    std::string text(state.range(0), 'a');

    for (auto _ : state)
        to_lowercase(text);

    state.SetComplexityN(state.range(0));
}
BENCHMARK(BM_ToLowerCase_Complexity)->RangeMultiplier(2)->Range(2, 1<<16)->Complexity(benchmark::oAuto);

static void BM_ToLowerCase_InPlace(benchmark::State& state) {
    std::string text = "The point is to get more experience with ranges and the STL.";

    for (auto _ : state)
        to_lowercase_inplace(text);
}
BENCHMARK(BM_ToLowerCase_InPlace);

static void BM_ToLowerCase_InPlace_Complexity(benchmark::State& state) {
    std::string text(state.range(0), 'a');

    for (auto _ : state)
        to_lowercase_inplace(text);

    state.SetComplexityN(state.range(0));
}
BENCHMARK(BM_ToLowerCase_InPlace_Complexity)->RangeMultiplier(2)->Range(2, 1<<16)->Complexity(benchmark::oAuto);

static void BM_ToSnakeCase(benchmark::State& state) {
    std::string text = "The point is to get more experience with ranges and the STL.";

    for (auto _ : state)
        to_snake_case(text);
}
BENCHMARK(BM_ToSnakeCase);

static void BM_ToSnakeCase_Complexity(benchmark::State& state) {
    std::string text(state.range(0), 'a');

    for (auto _ : state)
        to_snake_case(text);

    state.SetComplexityN(state.range(0));
}
BENCHMARK(BM_ToSnakeCase_Complexity)->RangeMultiplier(2)->Range(2, 1<<16)->Complexity(benchmark::oAuto);

static void BM_ToSnakeCase_InPlace(benchmark::State& state) {
    std::string text = "The point is to get more experience with ranges and the STL.";

    for (auto _ : state)
        to_snake_case_inplace(text);
}
BENCHMARK(BM_ToSnakeCase_InPlace);

static void BM_ToSnakeCase_InPlace_Complexity(benchmark::State& state) {
    std::string text(state.range(0), 'a');

    for (auto _ : state)
        to_snake_case_inplace(text);

    state.SetComplexityN(state.range(0));
}
BENCHMARK(BM_ToSnakeCase_InPlace_Complexity)->RangeMultiplier(2)->Range(2, 1<<16)->Complexity(benchmark::oAuto);

static void BM_ToCamelCase(benchmark::State& state) {
    std::string text = "The point is to get more experience with ranges and the STL.";

    for (auto _ : state)
        to_camelcase(text);
}
BENCHMARK(BM_ToCamelCase);

static void BM_ToCamelCase_Complexity(benchmark::State& state) {
	std::string text(state.range(0), 'a');

    for (auto _ : state)
        to_camelcase(text);

	state.SetComplexityN(state.range(0));
}
BENCHMARK(BM_ToCamelCase_Complexity)->RangeMultiplier(2)->Range(2, 1<<16)->Complexity(benchmark::oAuto);

static void BM_ToCamelCase_InPlace(benchmark::State& state) {
    std::string text = "The point is to get more experience with ranges and the STL.";

    for (auto _ : state)
        to_camelcase_inplace(text);
}
BENCHMARK(BM_ToCamelCase_InPlace);

static void BM_ToCamelCase_InPlace_Complexity(benchmark::State& state) {
	std::string text(state.range(0), 'a');

    for (auto _ : state)
        to_camelcase_inplace(text);

	state.SetComplexityN(state.range(0));
}
BENCHMARK(BM_ToCamelCase_InPlace_Complexity)->RangeMultiplier(2)->Range(2, 1<<16)->Complexity(benchmark::oAuto);

static void BM_ToStartCase(benchmark::State& state) {
    std::string text = "The point is to get more experience with ranges and the STL.";

    for (auto _ : state)
        to_startcase(text);
}
BENCHMARK(BM_ToStartCase);

static void BM_ToStartCase_Complexity(benchmark::State& state) {
	std::string text(state.range(0), 'a');

    for (auto _ : state)
        to_startcase(text);

	state.SetComplexityN(state.range(0));
}
BENCHMARK(BM_ToStartCase_Complexity)->RangeMultiplier(2)->Range(2, 1<<16)->Complexity(benchmark::oAuto);

static void BM_ToStartCase_InPlace(benchmark::State& state) {
    std::string text = "The point is to get more experience with ranges and the STL.";

    for (auto _ : state)
        to_startcase_inplace(text);
}
BENCHMARK(BM_ToStartCase_InPlace);

static void BM_ToStartCase_InPlace_Complexity(benchmark::State& state) {
	std::string text(state.range(0), 'a');

    for (auto _ : state)
        to_startcase_inplace(text);

	state.SetComplexityN(state.range(0));
}
BENCHMARK(BM_ToStartCase_InPlace_Complexity)->RangeMultiplier(2)->Range(2, 1<<16)->Complexity(benchmark::oAuto);

static void BM_ToTitleCaseIntactAbbreviations(benchmark::State& state) {
    std::string text = "The point is to get more experience with ranges and the STL.";
    auto wordList = ExceptionWords();

    for (auto _ : state)
        to_titlecase(text, wordList, true);
}
BENCHMARK(BM_ToTitleCaseIntactAbbreviations);

static void BM_ToTitleCaseIntactAbbreviations_Complexity(benchmark::State& state) {
	std::string text(state.range(0), 'a');
    auto wordList = ExceptionWords();

    for (auto _ : state)
        to_titlecase(text, wordList, true);

	state.SetComplexityN(state.range(0));
}
BENCHMARK(BM_ToTitleCaseIntactAbbreviations_Complexity)->RangeMultiplier(2)->Range(2, 1<<16)->Complexity(benchmark::oAuto);

static void BM_ToTitleCaseBreakAbbreviations(benchmark::State& state) {
    std::string text = "The point is to get more experience with ranges and the STL.";
    auto wordList = ExceptionWords();

    for (auto _ : state)
        to_titlecase(text, wordList, false);
}
BENCHMARK(BM_ToTitleCaseBreakAbbreviations);

static void BM_ToTitleCaseBreakAbbreviations_Complexity(benchmark::State& state) {
	std::string text(state.range(0), 'a');
    auto wordList = ExceptionWords();

    for (auto _ : state)
        to_titlecase(text, wordList, false);

	state.SetComplexityN(state.range(0));
}
BENCHMARK(BM_ToTitleCaseBreakAbbreviations_Complexity)->RangeMultiplier(2)->Range(2, 1<<16)->Complexity(benchmark::oAuto);

static void BM_ToTitleCaseIntactAbbreviations_InPlace(benchmark::State& state) {
    std::string text = "The point is to get more experience with ranges and the STL.";
    auto wordList = ExceptionWords();

    for (auto _ : state)
        to_titlecase_inplace(text, wordList, true);
}
BENCHMARK(BM_ToTitleCaseIntactAbbreviations_InPlace);

static void BM_ToTitleCaseIntactAbbreviations_InPlace_Complexity(benchmark::State& state) {
	std::string text(state.range(0), 'a');
    auto wordList = ExceptionWords();

    for (auto _ : state)
        to_titlecase_inplace(text, wordList, true);

	state.SetComplexityN(state.range(0));
}
BENCHMARK(BM_ToTitleCaseIntactAbbreviations_InPlace_Complexity)->RangeMultiplier(2)->Range(2, 1<<16)->Complexity(benchmark::oAuto);

static void BM_ToTitleCaseBreakAbbreviations_InPlace(benchmark::State& state) {
    std::string text = "The point is to get more experience with ranges and the STL.";
    auto wordList = ExceptionWords();

    for (auto _ : state)
        to_titlecase_inplace(text, wordList, false);
}
BENCHMARK(BM_ToTitleCaseBreakAbbreviations_InPlace);

static void BM_ToTitleCaseBreakAbbreviations_InPlace_Complexity(benchmark::State& state) {
	std::string text(state.range(0), 'a');
    auto wordList = ExceptionWords();

    for (auto _ : state)
        to_titlecase_inplace(text, wordList, false);

	state.SetComplexityN(state.range(0));
}
BENCHMARK(BM_ToTitleCaseBreakAbbreviations_InPlace_Complexity)->RangeMultiplier(2)->Range(2, 1<<16)->Complexity(benchmark::oAuto);

BENCHMARK_MAIN();