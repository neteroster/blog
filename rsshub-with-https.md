---
title: 搭建私人 RSSHub，配合 Caddy 2 实现 HTTPS
date: 2020-04-04 16:07:57
tags:
---

## Introduction

最近发现了个好玩的东西：[RSSHub](https://docs.rsshub.app/)。简单来说就是把一切你能想到和想不到的东西做成 RSS 订阅，方便统一管理。

## Let's Go

### 安装 RSSHub

多亏了 Docker 这个强大的工具，部署 RSSHub 异常简单。按照[官方教程](https://docs.rsshub.app/install/)使用以下命令即可（当然需要先安装好 Docker）：

```shell
$ docker pull diygod/rsshub
$ docker run -d --name rsshub -p 1200:1200 diygod/rsshub
```

搞定。试试访问 `http://your_server_ip:1200` 即可查看效果。

关闭 RSSHub：

```shell
docker stop rsshub
```

### 更新 RSSHub

首先删除旧容器。

```shell
$ docker stop rsshub
$ docker rm rsshub
```

然后重新执行安装操作即可。

### 配置 HTTPS

完成上面步骤后，会发现服务器只接受 HTTP 连接。为了实现 HTTPS，我们需要用到 Caddy。

注意：使用 HTTPS，你必须拥有一个域名。先添加一个 A 记录，指向你的 RSSHub 服务器。

本文以 Caddy 2 测试版为例。

由于 Caddy 使用 Go 编写，它的部署十分简单。只需要下载一个可执行文件即可，这里略去。

然后在 `caddy` 所在目录下创建 `Caddyfile` 文件，内容如下（示例，请根据自己需求更改）。

```YAML
https://rss.neteroster.live:2400 {
    reverse_proxy 127.0.0.1:1200
}
```

然后运行 `./caddy start` 就完成了。访问 `https://rss.neteroster.live:2400` 即可（替换成你自己的域名）。

原理是创建一个反向代理（Reverse Proxy），将 `https://rss.neteroster.live:2400` 反代到 `http://127.0.0.1:1200`，由于 Caddy 2 会帮助你全自动的（用 Let's Encrypt）签发 HTTPS 证书，所以整个部署流程显得非常流畅，行云流水。

不得不说，Caddy 2 是一个很强大的 Web 服务器，目前 Caddy 2 还处于测试（RC）阶段。留个坑，以后多多跟进开发进度。

* RSSHub 的文档在这里：https://docs.rsshub.app/
* Caddy 2 的官网在这里：https://caddyserver.com/


### 尾记 / 总结

本次部署用处非常大的三个工具是：Docker、RSSHub 和 Caddy 2。这三个工具使得部署异常流畅、稳定且简便。

配合 Telegram 的 [RSS Notice 机器人](https://t.me/RSSNoticeBot) 可以实现全平台无缝 RSS 通知。
