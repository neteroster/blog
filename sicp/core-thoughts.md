# 核心思想

## Chapter 1

* 基础知识、求值、求值顺序、表达式等。
* 高阶过程、过程的组合和抽象。

## Chapter 2

* 数据表示与访问分离（通过 constructor 与 selector），进而可以在过程本身不经修改的情况下更改数据的表示。
* 数据组合与闭包性质允许用数据原语构成结构化的复杂数据。
* 符号（或引用）让我们能够在编程语言中操作符号本身，从而获得更强的表达力。
* 列表（或其它语言中的作为过程表达的可迭代结构）可以作为有效的传统接口，加强随意的合作。
* 使用过程表达数据（painter 的例子），过程作为计算模型的最基本元素具有通用接口的意义（也即接口基于过程），非常重要。
* 构建层次化抽象，不断构建低层原语并由此创建上层。每层原语都是抽象屏障。原语内部也会有依赖关系，尽量把对表示的依赖限制在少数原语中，其他原语依赖这些原语，这样修改表示时需要更改的原语最少。
* constructor 和 selector 可以进一步抽象，进而可以得到抽象的 consturctor / selector，它们通过 type tag 选择适当的具体实现。

## Chapter 3

* 通过引入 `set!`，我们得以构建行为随时间变化的可计算对象，从而可以建模过程中随时间变化的那一部分，并使之模块化。作为代价，我们失去了利用具有良好数学性质的过程应用替换模型解释对象和赋值的能力。
* 为什么替换模型无法解释 `set!`：因为替换模型无法表示先后关系[（3.1）](http://sarabander.github.io/sicp/html/3_002e1.xhtml)，本质上来看，替换模型是假定**变量是值的名称**，而引入 `set!` 后变量只能是值的容器，具体的值可以更新。
* 引入 `set!` 破坏了编程语言中的等价替代性（或引用透明性：Referential transparency），使得我们利用等价代替简化表达式变得困难，进而使得对程序的推理变得棘手。

精彩节选

> Once we forgo referential transparency, the notion of what it means for computational objects to be “the same” becomes difficult to capture in a formal way. Indeed, the meaning of “same” in the real world that our programs model is hardly clear in itself. In general, we can determine that two apparently identical objects are indeed “the same one” only by modifying one object and then observing whether the other object has changed in the same way. But how can we tell if an object has “changed” other than by observing the “same” object twice and seeing whether some property of the object differs from one observation to the next? Thus, we cannot determine “change” without some a priori notion of “sameness,” and we cannot determine sameness without observing the effects of change.
