<p align="right">
  <a href="README.md">English</a> |
  <a href="README_ja.md">日本語</a>
</p>

# 🌱 gitplant

**gitplant** は、Git のコミット数に応じて植物が育っていく、Cベースの TUI アプリケーションです。

コミットを積み重ねるほど、植物も成長していきます。

## インストール

リポジトリをクローンします。

```sh
git clone <repository-url>
cd gitplant
```

gitplant の初期設定を行います。

```sh
./gitplant init
```

その後、以下のコマンドで gitplant を起動できます。

```sh
./gitplant plant
```

### PATH への追加

gitplant のディレクトリを `PATH` に追加しておくことをおすすめします。

PATH に追加すると、どのディレクトリからでも以下のように実行できます。

```sh
gitplant plant
```

例えば:

```sh
export PATH="$PATH:/path/to/gitplant"
```

毎回設定する必要がないように、使用しているシェルの設定ファイルに追加してください。

Bash の場合:

```sh
~/.bashrc
```

Zsh の場合:

```sh
~/.zshrc
```

## 使い方

```sh
gitplant [COMMAND]
```

| コマンド             | 説明                   |
| ---------------- | -------------------- |
| `gitplant init`  | gitplant を使用するための環境設定 |
| `gitplant plant` | gitplant を起動して植物を表示   |
| `gitplant help`  | ヘルプを表示               |

### 初期設定

```sh
gitplant init
```

gitplant を使用するために必要な環境設定を行います。

インストール後に一度実行してください。

### gitplant を起動

```sh
gitplant plant
```

TUI を起動し、現在の植物を表示します。

### ヘルプ

```sh
gitplant help
```

利用可能なコマンドを表示します。

## ⚠️ Git Hooks について

gitplant は Git の `post-commit` Hook を利用してコミットを追跡します。

```sh
gitplant init
```

を実行すると、Git が gitplant 用の**グローバル Hooks ディレクトリ**を使用するように設定されます。

そのため、すでに独自の Git Hooks を使用しているリポジトリでは、既存の Hook 設定に影響する可能性があります。

既存のローカル Hooks を使用しているプロジェクトでも gitplant でコミットを追跡したい場合は、

```text
scripts/post-commit
```

の処理を、そのプロジェクトの既存の `post-commit` Hook に追加または統合してください。

その上で、そのリポジトリでは gitplant のグローバル Hooks ではなく、ローカル Hooks を使用するように設定してください。

独自の Git Hooks に依存しているリポジトリがある場合は、`gitplant init` を実行する前に Hook 設定を確認することをおすすめします。

## 仕組み

gitplant は Git のコミット活動を記録し、そのコミット数を植物の成長として表現します。

単なるコミット数ではなく、日々の開発活動をターミナル上の植物として視覚的に確認できます。

## 使用技術

* C
* Shell Script
* Git
* Git Hooks
* Terminal / TUI

## ライセンス

ライセンス情報をここに記載してください。
