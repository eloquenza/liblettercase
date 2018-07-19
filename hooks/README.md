# Autohook

**Autohook** is a very, _very_ small Git hook manager with focus on automation.

It consists of one script which acts as the entry point for all the hooks, and which runs scripts based on symlinks in appropriate directories.

## Example

Let's say you have a script to remove `.pyc` files that you want to run after every `git checkout` and before every `git commit`, and another script that runs your test suite that you want to run before every `git commit`.

Here's the overview of steps:

1. Put `autohook.sh` & `autohook_setup.sh` `in `hooks/`.
2. Run it with `install` parameter (e.g., `./autohook_setup.sh install`).
3. Put your scripts in `hooks/scripts/`.
4. Make sure said scripts are executable (e.g., `chmod +x hooks/scripts/delete-pyc-files`, etc.).
5. Make directories for your hook types (e.g., `mkdir -p hooks/post-checkout hooks/pre-commit`).
6. Symlink your scripts to the correct directories, using numbers in symlink names to enforce execution order (e.g., `ln -s hooks/scripts/delete-pyc-files.sh hooks/post-checkout/01-delete-pyc-files`, etc.).

The result should be a tree that looks something like this:

```
repo_root/
├── hooks/
│   ├── autohook_install.sh
│   ├── autohook.sh
│   ├── post-checkout/
│   │   └── 01-delete-pyc-files     # symlink to hooks/scripts/delete-pyc-files.sh
│   ├── pre-commit/
│   │   ├── 01-delete-pyc-files     # symlink to hooks/scripts/delete-pyc-files.sh
│   │   └── 02-run-tests            # symlink to hooks/scripts/run-tests.sh
│   └── scripts/
│       ├── delete-pyc-files.sh
│       └── run-tests.sh
├── other_dirs/
└── other_files
```

You're done!

If, for some reason, you want to remove the hooks again, you can either:

* execute `hooks/autohook_setup.sh uninstall`,
* or go to .git/hooks/ and remove all symlinks.

## Requirements

### `realpath`

You will need [`realpath`](https://linux.die.net/man/3/realpath 'realpath(3) - Linux man page').
Most Linux and BSD systems should already have it, and on macOS you should `brew install coreutils` (which comes from [here](https://github.com/Homebrew/homebrew-core/blob/master/Formula/coreutils.rb 'Homebrew/homebrew-core - homebrew-core/Formula/coreutils.rb')).
