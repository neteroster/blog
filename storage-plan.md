# 数据存储方案

经过长时间的技术选型，确定了文件存储的基本方案。示意图如下：

![data-storage](https://github.com/neteroster/blog/blob/main/neter-storage.svg)


## 简述

### 热存储

* 文件系统：NTFS / [XFS](https://xfs.org/)
* 存储器：SSD（固态硬盘）

### 归档存储

* 文件系统：[ZFS](https://openzfs.org/)
* 存储器：HDD（机械硬盘）

### 文件分享

* 文件服务：SMB (Windows) / NFS (Linux)
* 网络隧道：[WireGuard](https://www.wireguard.com/)

### 文件备份

* 备份到：OneDrive
* 备份工具：[restic](https://restic.net/)

### 其余简单补充

热存储需要快速访问，选择 SSD 和快速文件系统（NTFS / XFS）。MX500 是一款性价比较高的 SSD。热存储系统搭建在常用的 Windows 上便于交换数据。

归档存储需要确保数据完整性和安全性，采用 ZFS 文件系统（目前为单盘）和 HDD。HC530 是企业级机械硬盘，稳定安全。ZFS 文件系统具有校验和功能，能检测文件完整性，及时报告错误并且具有一定的自修复能力。定期（每 1 个月）使用 ZFS 巡检检测数据完整性。整个归档存储平台搭建在 [Arch Linux](https://www.archlinux.org/)，仅需要时进入系统手动挂载硬盘文件系统访问数据，操作完成及时弹出文件系统并退出操作系统。

Windows 文件服务采用 SMB；Linux 文件服务（暂时还没有）采用 NFS。兼容性好，性能不错。

文件分享的网络隧道采用 WireGuard。确保分享数据安全性，同时性能也非常不错（延迟低，速度快）。

文件备份采用 restic，自动加密文件，并且能验证文件完整性。备份目前存储到 OneDrive。
