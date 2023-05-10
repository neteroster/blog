* `cond` 是一个 special form。`if` 也是一个 special form，而且是 `cond` 的特殊形式。 
* `and, or` 都是 special form，而不是过程（对于 `cond` 同理），因为他们不一定对所有后续表达式求值。`not` 是普通的过程。
