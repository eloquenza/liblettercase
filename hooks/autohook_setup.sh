echo() {
    builtin echo "[Autohook] $*";
}

hook_types=(
    "applypatch-msg"
    "commit-msg"
    "post-applypatch"
    "post-checkout"
    "post-commit"
    "post-merge"
    "post-receive"
    "post-rewrite"
    "post-update"
    "pre-applypatch"
    "pre-auto-gc"
    "pre-commit"
    "pre-push"
    "pre-rebase"
    "pre-receive"
    "prepare-commit-msg"
    "update"
)

repo_root=$(git rev-parse --show-toplevel)
hooks_dir="$repo_root/.git/hooks"
autohook_filename="$repo_root/hooks/autohook.sh"
autohook_path=$(realpath $autohook_filename)

uninstall() {
    for hook_type in "${hook_types[@]}"
    do
        hook_symlink="$hooks_dir/$hook_type"
        unlink $hook_symlink
    done
}

install() {
    for hook_type in "${hook_types[@]}"
    do
        hook_symlink="$hooks_dir/$hook_type"
        ln -s $autohook_path $hook_symlink
    done
}

command=$1
if [[ $command == "install" ]]
then
    echo "Installing autohooks"
    install
fi
if [[ $command == "uninstall" ]]
then
    echo "Removing autohooks"
    uninstall
fi
