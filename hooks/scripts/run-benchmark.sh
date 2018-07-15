#! /usr/bin/env bash

case "$2,$3" in
    merge,)
        ;;
    *) echo "Not a merge commit. Exiting."; exit 0; ;;
esac

date=$(date +%Y-%m-%d)
commit=$(git describe --dirty)

repo_root=$(git rev-parse --show-toplevel)
data_dir=$repo_root/data/benchmarks
benchmark_file=$data_dir/$date-bench-$commit.json
best_benchmark=$(find "$data_dir" -maxdepth 1 -type f -iname "best-bench*")
binary_dir=$repo_root/bin
benchmark_executable=$binary_dir/liblettercase-benchmarking

$benchmark_executable --benchmark_out_format=json --benchmark_out="$benchmark_file"
benchmark_exit_code=$?
if [[ $? != 0 ]]
then
    echo "Something went wrong during benchmarking. Exiting (code: ${benchmark_exit_code}) now..."
    exit $benchmark_exit_code
fi

echo ""

if [[ -e "$best_benchmark" ]]
then
    echo "Let's see if we can beat the currently best benchmark."
    output="$($repo_root/scripts/compare_bench.py "$benchmark_file" "$best_benchmark")"
    better_benchmark=$(echo "$output" | tail -1)
    echo "$output"
    echo ""
    if [[ "$better_benchmark" != "$best_benchmark" ]]
    then
        echo "Yay, we could beat it!"
        filename=$(basename "$best_benchmark")
        mv "$best_benchmark" "$data_dir/$date-old-$filename"
        mv "$better_benchmark" "$data_dir/best-bench-$commit.json"
        echo "Renamed old best benchmark to $data_dir/$date-old-$filename"
        echo "Renamed newly created benchmark to $data_dir/best-bench-$commit.json"
    else
        calculated_change=$(echo "$output" | tail -3 | head -1)
        if [[ $(echo "$calculated_change > 0.05" | bc -l) ]]
        then
            echo "Woah, what happened here? The performance is dropping off!"
            echo "You better sort this out, before merging"
            exit 1
        fi
        echo "We could not beat it, better luck next time."
    fi
else
    echo "No best benchmark file exists, newly created one is best one for now."
    mv "$benchmark_file" "$data_dir/best-bench-$commit.json"
    echo "Created $data_dir/best-bench-$commit.json"
fi
exit 0
