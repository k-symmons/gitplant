<p align="left">
  <a href="README.md">English</a> |
  <a href="README_ja.md">日本語</a>
</p>

# 🌱 gitplant

**gitplant** is a C-based TUI application that grows a virtual plant based on your Git commit activity.

The more you commit, the more your plant grows.

<img width="524" height="375" alt="image" src="https://github.com/user-attachments/assets/7625aa84-3c5d-4e9f-b3a0-e4c9fa16ca20" />


## Installation

Clone the repository:

```sh
git clone <repository-url>
cd gitplant
```

Initialize gitplant:

```sh
./gitplant init
```

You can then launch gitplant with:

```sh
./gitplant plant
```

### Add gitplant to your PATH

Adding the gitplant directory to your `PATH` is recommended so you can run it from anywhere.

For example:

```sh
export PATH="$PATH:/path/to/gitplant"
```

Add the line to your shell configuration file to make it permanent.

For Bash:

```sh
~/.bashrc
```

For Zsh:

```sh
~/.zshrc
```

After that, you can simply run:

```sh
gitplant plant
```

## Usage

```sh
gitplant [COMMAND]
```

| Command          | Description                                     |
| ---------------- | ----------------------------------------------- |
| `gitplant init`  | Initialize the environment required by gitplant |
| `gitplant plant` | Start gitplant and display your plant           |
| `gitplant help`  | Display the help message                        |

### Initialize

```sh
gitplant init
```

Sets up the environment required by gitplant.

Run this once after installation.

### Start gitplant

```sh
gitplant plant
```

Starts the TUI and displays your current plant.

### Help

```sh
gitplant help
```

Displays the available commands.

## ⚠️ Git Hooks

gitplant uses Git's `post-commit` hook to track commits.

Running:

```sh
gitplant init
```

configures Git to use gitplant's **global hooks directory**.

This means that repositories that already use their own Git hooks may be affected.

If a repository already uses local hooks and you still want gitplant to track commits in that repository, add or integrate:

```text
scripts/post-commit
```

into that repository's existing `post-commit` hook, and configure the repository to use its local hooks instead of gitplant's global hook configuration.

Check your existing Git hook configuration before running `gitplant init` if you rely on custom hooks.

## How it works

gitplant tracks your Git commit activity and converts it into the growth of a virtual plant.

Instead of looking at commit counts as just numbers, gitplant gives you a simple visual representation of your development activity directly in the terminal.

## Built With

* C
* Shell Script
* Git
* Git Hooks
