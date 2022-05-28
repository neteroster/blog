---
title: 使用 FFmpeg 统一音频音量
date: 2020-04-02 09:22:42
tags:
---

## 为什么要统一音量

相信大家都有遇到过这样的场景：不同音乐文件，响度（音量）差异很大，导致切歌的时候要手动调整音量，很麻烦。那么，是否有一种自动化调整的工具呢？

在查阅资料后，我发现 `FFmpeg` 有一个[名为 `loudnorm` 的音频过滤器](http://ffmpeg.org/ffmpeg-all.html#loudnorm)，能够实现要求功能。

这个过滤器按照 [EBU R 128 规范](https://en.wikipedia.org/wiki/EBU_R_128) 调整音量。具体规范可以阅读上面链接到的 Wiki。虽然我还没弄懂这份规范的具体内容和原理，我们还是可以用一用。

## Let's go!

首先，你需要[下载 `ffmpeg`](https://www.ffmpeg.org/)并安装。

然后，运行如下命令即可将你的音频统一到 -23 LUFS 左右啦！

```powershell
ffmpeg -i <input.file> -af "loudnorm=print_format=summary" -vn -sn -dn -f <outformat> <output.file>
```

其中，`<input.file>` 是输入文件，例如 `input.mp3`，`<outformat>` 是输出格式，例如 `mp3`，`<output.file>` 是输出文件名，例如 `output.mp3`。

写个脚本统一所有音频也是轻轻松松。

## Go further!

这个 `loudnorm` 过滤器还有很多参数，包括可以设定目标响度、设定动态调整还是线性调整（默认为动态，看网友推荐是线性两次效果最好）。

这里就挖一个坑，等待以后好好研究 EBU R 128 规范和这个过滤器啦！