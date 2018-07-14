#!/usr/bin/env bash

# Autohook
# A very, very small Git hook manager with focus on automation
# Author:   Nik Kantar <http://nkantar.com>
# Version:  2.1.1
# Website:  https://github.com/nkantar/Autohook


echo() {
    builtin echo "[Autohook] $*";
}

main() {
    calling_file=$(basename $0)

    repo_root=$(git rev-parse --show-toplevel)
    hook_type=$calling_file
    symlinks_dir="$repo_root/hooks/$hook_type"
    files=("$symlinks_dir"/*)
    number_of_symlinks="${#files[@]}"
    if [[ $number_of_symlinks == 1 ]]
    then
        if [[ "$(basename ${files[0]})" == "*" ]]
        then
            number_of_symlinks=0
        fi
    fi
    echo "Running $hook_type scripts"
    if [[ $number_of_symlinks -gt 0 ]]
    then
        hook_exit_code=0
        for file in "${files[@]}"
        do
            scriptname=$(basename "${file}")
            echo "Running $scriptname... "
            eval "${file}"
            script_exit_code=$?
            if [[ $script_exit_code != 0 ]]
            then
                echo "Script $scriptname has failed with exit code $script_exit_code."
                hook_exit_code=${script_exit_code}
            fi
            echo "... finished $scriptname."
        done
        exit $hook_exit_code
    fi
}


main "$@"
