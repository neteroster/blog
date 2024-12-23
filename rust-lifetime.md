# 有关 rust 的生命周期标记

## Introduction

本文将为读者提供一种易懂的 rust 生命周期标记的理解方法。具体来说，我们将严格把生命周期标记视作变量的一种类型，并基于此进行逻辑推演，以帮助读者理解生命周期标记。

## 声明

本文的内容仅限于帮助读者在语法层面理解生命周期标记。具体的生命周期标记的底层实现方法可能和本文所述有巨大差别，请特别留意。

## 一种类型——生命周期标记

我们在下面的讨论中将全程将生命周期标记作为一种类型进行讨论。

首先抛出一个假设：每一个引用变量都有一个生命周期，例如

```rust
let s1 = String::from("example");
let s2: &str = s1.as_str();
```

我希望你在头脑中将这段程序自动转换成

```rust
let s1 = String::from("example");
let s2: &'a str = s1.as_str();
```

也就是 `s2` 的生命周期是 `'a`。当然，生命周期是该由变量在程序中的使用情况确定的，这里 `'a` 只是一个记号，而不是去指定 `s2` 的生命周期的方式。

接下来我们看看那个经典的 `longest` 函数：

```rust
fn longest<'a>(x: &'a str, y: &'a str) -> &'a str {
    if x.len() > y.len() {
        x
    } else {
        y
    }
}

fn main() {
    let s1 = String::from("test");
    let s2 = String::from("example");

    let result = max(s1.as_str(), s2.as_str());

    println!("bigger one: {}", result); // bigger one: example
}
```

别急！这里有很多知识点，请等我慢慢陈述。

首先我们先澄清一些概念：

1. `x: &'a str` 的意思**不完全是**函数接受一个 `&str` 的变量 `x`，它的生命周期是 `'a`. 为什么不是？因为这里我们用到了「**类型兼容性规则**」。事实上，`x: &'a str` 的意思是，函数接收一个 `&str` 变量 `x`，它的生命周期类型**属于** `'a`（换句话说，要求 `x` 的生命周期类型是 `'a` 的**子类型**）。你可以这么想：对于生命周期标记类型来说，如果 `'a` 是 `'b` 的子类型，那么 `'a` 要比 `'b` 长，你可以思考一下为什么这样是合理的。（答案：因为只有这样才能让我们的「类型兼容性规则」与「防止悬垂引用」配合起来。）
2. 同理，表面上我们的返回值类型是 `'a`，但是这并不是指 `result` 的返回值生命周期就是 `'a`。事实上，`result` 的生命周期是 `main()` 函数里已经决定的客观存在，我们之所以在返回值写 `&'a str`，是因为我们希望编译器检查：「`result` 的实际生命周期类型**包含了** `'a` 这个类型」，换句话说，希望检查「`result` 的生命周期小于 `'a`」，进而根据 1.，会小于 `x` 和 `y` 的生命周期，保证不出现悬垂引用。

下面，我们正式跟着编译器的视角走一遍检查流程：

1. 首先确定好 `s1, s2, result` 的生命周期，分别记为 `[s1], [s2], [result]`.
2. 让我看看 `max` 函数的调用！好的，`x` 实际的生命周期是 `[s1]`，`y` 的实际生命周期是 `[s2]`。
3. 已经可以确定 `'a` 了！立即确定 `'a = min{[s1], [s2]}`. 至此，已经完成了该函数模板（如果你学过 C++）的实例化（因为我们的泛型 `'a` 得到了确定）
4. 让我检查一下返回值的生命周期 `[result]`. 我发现，的确，`[result]` 要短于 `'a`，所以 `'a` 是 `[result]` 的子类型，将返回值绑定到 `result` 上是合理的。
5. 结束任务，编译通过！
