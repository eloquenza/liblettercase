#! /usr/bin/env bash

repo_root=$(git rev-parse --show-toplevel)
binary_dir=$repo_root/bin
test_executable=$binary_dir/liblettercase-test

$test_executable

exit $?
