---
title: 含参函数最值极值求法
mathjax: true
---

今天发一篇以前自己写的小笔记。之后笔记也会慢慢都发上来。

## Example

先来看一个例子。

*Example* **T1.** 已知函数 $f(x) = e^x - ax^2 -bx - 1$，其中，$a, b \in \mathbb{R}$，设 $g(x) = f'(x)$，求函数 $g(x)$ 在区间 $\left[0, 1\right]$ 上的最小值。

*Solution* **T1.** 根据题，易得
$$
g(x) = e^x - 2ax - b
$$
那么
$$
g'(x) = e^x - 2a
$$
当 $x \in \left[0, 1\right]$ 时，$g'(x) \in \left[ 1-2a, e-2a\right]$，也就是说当 $1-2a\ge0$，$g(x)$ 在区间内为增函数，$g(x)_{\text{min}} = g(0)$。

得当 $a \le \frac{1}{2}$ 时，$g(x)_{\text{min}} = g(0) = 1-b$

同理，当 $e-2a \le 0$ 时，$g(x)$ 在区间内为减函数，那么 $g(x)_{\text{min}} = g(1)$。

得当 $a \ge \frac{e}{2}$ 时，$g(x)_{\text{min}} = g(1) = e - 2a - b$。

那么，当 $a \in \left( \frac{1}{2}, \frac{e}{2} \right)$ 时，$g'(x)$ 的零点就在 $\left[ 0, 1 \right]$ 之内。我们现在求解其零点
$$
e^x - 2a = 0
$$
得 $x = \ln(2a)$ ，那么此时
$$
g(x)_{\text{min}} = g(\ln(2a)) = 2a - 2a\ln(2a) - b
$$
至此已经把所有情况讨论完毕。

## General Steps

这个求法的一般做法归纳如下：

1. 求目标函数（求极值的函数）的导函数 $f'(x)$。
2. 分别讨论 **导函数的零点在所给区间内**；**导函数零点在所给区间左**；**导函数零点在所给区间右**。
3. 得出结论。

如果导函数是单调函数，可以写出其值域（这里以递增为例）：在区间 $\left[a, b \right]$ 内，导数值域为 $\left[f'(a), f'(b) \right]$，再以值域边界的正负进一步讨论即可。

