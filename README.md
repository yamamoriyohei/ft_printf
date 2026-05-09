*This project has been created as part of the 42 curriculum by yyamamor.*

## Description
本プロジェクト「ft_printf」は、C言語の標準ライブラリ関数である `printf` の動作を再現する独自の関数を作成する課題です。
この課題のゴールは、C言語におけるVariadic Argumentsの仕組みを正しく理解し、型が実行時までわからない複数の引数を安全に取り扱えるようになることです。

## Instructions
libftprintf.aとしてコンパイルされます。

### コンパイル方法
リポジトリのルートディレクトリで以下のコマンドを実行します。
```bash
make
```
これにより `libftprintf.a` が生成されます。

### 使用方法
ご自身のCプログラム内で `ft_printf.h` をインクルードし、コンパイル時にライブラリをリンクしてください。
```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s! Number: %d\n", "42", 42);
    return (0);
}
```
```bash
cc main.c libftprintf.a
./a.out
```

## Implementation Details
本プロジェクトでは、動的なメモリ割り当て（`malloc`）によるバッファリングや構造体を用いた複雑な状態管理を避け、「文字列を1文字ずつ解析し、その場で標準出力（`write`）に書き込む」アルゴリズムを採用しました。
課題のPDFに指定されていた%c, %s, %p, %d, %i, %u, %x, %X, %%のフォーマット指定子に対応します。


## Resources
*   **公式ドキュメント**: `man 3 printf`, `man 3 stdarg`
*   **AIの活用**:
    *   **タスクと用途**: 可変長引数（`va_list`, `va_arg`）の挙動の理解、および数値出力時の再帰アルゴリズムの構築における壁打ち・メンターとしてAIを活用しました。
    *   **手法**: AIに直接答え（完成されたコード）を求めるのではなく、コードレビューによるバグ（数値出力の逆転現象など）の発見と、その解決に向けたヒントを得るためのピアラーニングの相手として使用しました。
