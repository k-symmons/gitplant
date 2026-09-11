#!/bin/sh

mkdir -p ~/.config/git/hooks && touch ~/.config/git/hooks/post-commit

echo "echo "hello world" " > ~/.config/git/hooks/post-commit


git config --global core.hooksPath ~/.config/git/hooks

chmod u=wrx ~/.config/git/hooks/post-commit

~/.config/git/hooks/post-commit
