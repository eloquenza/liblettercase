#! /usr/bin/env bash

repo_root=$(git rev-parse --show-toplevel)
binary_dir=$repo_root/bin
test_executable=$binary_dir/liblettercase-test

if [[ ! -f $test_executable ]]
then
    echo "No test executable could be found."
    echo "Please ensure that a $test_executable is available."
    exit 1
fi

files_changed=$(git diff --cached --name-only)
if [[ $(echo $files_changed | grep -svE "\.(cpp|h)$") ]]
then
    echo "No source file has been changed. No need to run tests."
    exit 0
fi

$test_executable

exit $?
