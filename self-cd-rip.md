# 自行进行 CD 抓轨与扫图

本文将介绍如何用光驱自行对 CD 进行抓轨。

## 需要准备

1. Windows 7 or newer OS, x64.
2. A modern CD drive, **with fixed read offset and *Accurate Stream* feature.**
3. [Exact Audio Copy](https://www.exactaudiocopy.de/) latest version.
4. [Visual Studio Code](https://code.visualstudio.com/) latest version.
5. (*Optional*) A scanner, usually can be a printer.

## 开始操作

### 安装 Visual Studio Code

请从上面链接自行下载安装，安装时设置遵守默认即可。

### 安装 Exact Audio Copy

**(*Optional*)** 如果你以前安装过 EAC，请彻底卸载之，并运行 `dBpoweramp-Reset.exe`（附在本文文件夹中），并点击 `Begin Reset`，这样做是为了彻底清除以前 CD 的偏移数据，以便重新测试之。

打开 EAC 的安装程序，并按默认选项安装之，安装成功后**不要**选择 **立即启动 Exact Audio Copy**。

打开注册表编辑器（`Win + R: regedit`），在左侧定位 `计算机\HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows NT\CurrentVersion\AppCompatFlags\Layers`

在右侧空白区域右键，点击 `新建(N) -> 字符串值(S)`，命名其名称为 EAC 安装路径（通常来说是 `C:\Program Files (x86)\Exact Audio Copy\EAC.exe`），然后右键该值，选择 `修改(M)`，确定 `数值名称(N)` 为 EAC 安装路径，并在 `数值数据(V)` 中填写 `~ DISABLETHEMES`，然后确定。最终应如图所示。

![1](https://github.com/neteroster/blog/blob/main/self-cd-rip-img/1.png)

确认后关闭注册表编辑器。

右键桌面 `Exact Audio Copy` 的快捷方式，点击 `属性(R)`，选择 `兼容性` 一栏，选择 `以管理员身份运行此程序`，然后点击 `确定`。

### 配置驱动器

将 CD 驱动器用 USB 数据线连接到电脑 USB 接口（若是台式机，应连接背部接口，以确保稳定性）。准备好一张较为热门的 CD（不需要是目标 CD，只要数据库中存在即可，用于校正光盘读取偏移，当然也可以选择目标 CD）。

启动 Exact Audio Copy，首先会弹出下图提升，选择 `否` 即可。

![2](https://github.com/neteroster/blog/blob/main/self-cd-rip-img/2.png)

然后会弹出 EAC 配置向导，首先选择 `下一页(N) >`。

如图所示，确定自己的 CD 驱动器已经被选中。

![3](https://github.com/neteroster/blog/blob/main/self-cd-rip-img/3.png)

选择 `下一页(N) >`。

如图，选择 `我更希望得到精确的结果`。

![4](https://github.com/neteroster/blog/blob/main/self-cd-rip-img/4.png)

选择 `下一页(N) >`。

插入 CD 后，将会立即弹出 AccurateRip 的配置指导，只需根据指引点击配置按钮即可。

*请注意：如果你的 CD 在插入后立即弹出，请参见文末 **问题解决** 章节。请在完成修复操作并重新插入 CD 后再点击 AccruateRip 的配置按钮。*

若弹出如下窗口，则说明 AccurateRip 配置正确。

![5](https://github.com/neteroster/blog/blob/main/self-cd-rip-img/5.png)

如下图，随后选择 `下一页(N) >`。

![6](https://github.com/neteroster/blog/blob/main/self-cd-rip-img/6.png)

EAC 将自动测试你的驱动器特性，请稍等片刻。

如图，确保“精确流”为“是”即可。

![7](https://github.com/neteroster/blog/blob/main/self-cd-rip-img/7.png)

随后选择 `下一页(N) >`。再次选择 `下一页(N) >`。再次选择 `下一页(N) >` 跳过编码器介绍。

如下图，选择 `FLAC` 格式。

![8](https://github.com/neteroster/blog/blob/main/self-cd-rip-img/8.png)

随后选择 `下一页(N) >`。再次选择 `下一页(N) >`。再次选择 `下一页(N) >`。如图填写邮箱地址后再次选择 `下一页(N) >`。

![9](https://github.com/neteroster/blog/blob/main/self-cd-rip-img/9.png)

命名方案保持默认并选择 `下一页(N) >`。

如图，选择“我是老手，让我使用 EAC 所有潜在特性”。完成配置。

![10](https://github.com/neteroster/blog/blob/main/self-cd-rip-img/10.png)

在菜单栏中选择 `EAC -> EAC 选项(E)`。

将 `抓取和压缩的优先级` 与 `纠错品质` 都设为 `高` ，如图。

![11](https://github.com/neteroster/blog/blob/main/self-cd-rip-img/11.png)

点击菜单栏 `常规`，勾选 `总是用英语创建日志文件`。

![12](https://github.com/neteroster/blog/blob/main/self-cd-rip-img/12.png)

点击菜单栏 `工具`，勾选 `抓取完毕后自动生成状态报告` 和 `增加校验至状态报告`。

![13](https://github.com/neteroster/blog/blob/main/self-cd-rip-img/13.png)

随后点击 `确定` 保存设置。

在菜单栏选择 `EAC -> 驱动器选项(D)`，选择 `驱动器` 一栏，选中 `抓取之前先转动驱动器`（如图）。

![14](https://github.com/neteroster/blog/blob/main/self-cd-rip-img/14.png)

在 `偏移/速度` 一栏中，确定已经设置偏移数据。

打开 `间隙检测` 一栏，`检测精确度` 选择 `安全`（如图）。

![15](https://github.com/neteroster/blog/blob/main/self-cd-rip-img/15.png)

随后单击 `确定` 保存设置。

### 开始抓取

本次以 `VTCL-35257` 为例。

![16](https://github.com/neteroster/blog/blob/main/self-cd-rip-img/16.png)

取出 CD 时，请用力按住 CD 中间的插入位置（如图红框）取出 CD，防止损坏 CD。

随后先启动 Exact Audio Copy，然后在驱动器中放入 CD。EAC 中将马上出现读取结果。

在菜单栏选择 `数据库(D) -> 获取 CD 信息(G) -> 从远程元数据源`，如图。

![17](https://github.com/neteroster/blog/blob/main/self-cd-rip-img/17.png)

选择一个元数据，然后确定即可。

随后选择 `操作(A) -> 检测间隙(D)`，如图。

完成后即可开始正式抓取。

选择 `操作(A) -> 测试并抓取镜像及创建 CUE 目录文件 -> 已压缩`。如图。

![18](https://github.com/neteroster/blog/blob/main/self-cd-rip-img/18.png)

选择点击左侧 `桌面`，选择 **桌面上的文件夹（请提前建立好）** 点击 `保存(S)`。请不要点击 `此电脑`，否则将闪退！

随后 EAC 将开始测试并抓取，等待。
