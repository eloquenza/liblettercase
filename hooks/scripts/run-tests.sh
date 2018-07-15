#! /usr/bin/env bash

files_changed=$(git diff --cached --name-only)
if [[ $(echo $files_changed | grep -svE "\.(cpp|h)$") ]]
then
    echo "No source file has been changed. No need to run tests."
    exit 0
fi

repo_root=$(git rev-parse --show-toplevel)
binary_dir=$repo_root/bin
test_executable=$binary_dir/liblettercase-test

$test_executable

exit $?
