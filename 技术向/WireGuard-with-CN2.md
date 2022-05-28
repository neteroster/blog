---
title: WireGuard & CN2
date: 2020-04-15 16:04:11
tags:
---

## WireGuard 与 CN2 线路的合体

今天试了一下在阿里云香港的云服务器（ECS）上搭建 [WireGuard](https://www.wireguard.com/) 与本地连接，发现速度出乎意料的快，任何时段均能跑满 100M。另外一个有趣的现象是，用 WireGuard 内网 Ping 服务器只需 14ms，而 ICMP 直接 Ping 服务器公网 IP 却要 15ms。使用 UDP 且集成到内核的 WireGuard 果然性能优异。

另外还是要感叹一下，阿里云的香港 CN2 线路质量太好了，世界加钱可及是没错的。

现在暂时用这个服务器搭建了一个 SMB 共享玩玩~
