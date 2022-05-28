---
title: Arch Linux + XFS 文件系统踩坑记
date: 2020-05-16 09:06:36
tags:
---

最近心血来潮，虚拟机安装了一下 Arch Linux，并且尝试了 [XFS 文件系统](https://xfs.org/index.php/Main_Page)。这里记录一下主要的坑。

首先，务必不要忘记在系统内安装 `xfsprogs` 包。否则会导致 `fsck.xfs` 无法找到，进而引起奇奇怪怪的问题。

* 以 xfs 格式化分区：`mkfs.xfs /dev/target_partition` 直接这样格式化便能获得最佳性能。
* 增大 xfs 空间只需要：`xfs_growfs /path/to/mnt/point`

注：操作完毕后最好执行以下操作。

1. 确保 `xfsprogs` 包已经安装，若没有，需要：`sudo pacman -S xfsprogs`。
2. 重建 initrd：`mkinitcpio -p linux`。
3. 重启系统 `reboot`。


XFS 也许是下一代 Linux 文件系统，目前在 Linux 内核主线被维护。它比 Ext4 性能更好，安全性更强，已经在 CentOS 7 得到默认使用。

一些关于 XFS 文件系统的资源：

* [XFS 官网 xfs.org](https://xfs.org/index.php/Main_Page)
* [XFS 在 Linux 内核主线的源码](https://git.kernel.org/pub/scm/fs/xfs/xfs-linux.git/)
* [ArchWiki - XFS](https://wiki.archlinux.org/index.php/XFS)