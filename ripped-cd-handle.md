# CD 抓轨文件标准化处理

本文将介绍如何把从互联网上收集的 EAC 无损抓轨镜像进行标准化处理。

## 需要准备

1. Windows 7 or newer OS, x64.
2. [CUETools](http://cue.tools/wiki/Main_Page) latest version.
3. [Visual Studio Code](https://code.visualstudio.com/) latest version.

## STEP 1 - 准备工作

### 准备 CD 资料
首先确定目标 CD 的标题、商品编号等，为命名做好准备。

### 检查抓轨数据准确
启动 CUETools，选择 `.cue` 文件所在文件夹，在 `Action` 一栏中选择 `Verify`，单击 `Go`。

当所有音轨均 `Accurately ripped`，允许进入下面的 **编码与压缩** 部分，否则继续本部分。

若所有音轨均未能 `Accurately ripped`，尝试通过 Log 的指导更改 `Offset` 一栏。若一个指定 `Offset` 能让除最后一个（或第一个）音轨之外的所有音轨 `Accurately ripped`，则进入 **编码与压缩** 部分，否则终止整个过程，放弃标准化。

若部分音轨 `Accurately ripped`，立即终止整个过程，放弃标准化。

若音频数据库中没有对应 CD 数据，检查 Log 文件
* 若 `Offset`（光驱偏移校正）为 0，立即终止整个过程，放弃标准化。
* 若 `Offset` 不为 0，且报告 CD 质量 >=99.6%，允许进入下面的 **编码与压缩** 部分。

### 编码与压缩

在继续之前，请确定 `Offset` 值已经被设为 0（这是由于检验音轨时可能对 `Offset` 进行了修改）。

在 CUETools 中，选择 `.cue` 文件所在文件夹。

若在 **检查抓轨数据准确** 中修改了 `Offset` 才使验证通过，则在 `Action` 一栏中选择 `fix offset`。

若抓轨时 EAC 的 `Offset` 准确（也就是检验音轨时 `Offset` 为 0 就通过了检验），则在 `Action` 一栏中选择 `encode if verified`。

在 `Mode` 一栏中选择 **Image + CUE**，在 `Audio Output` 一栏中选择 `Lossless`; `flac`; `libFLAC`。

单击 `Go`，在弹出的对话框中确定 CD 数据库的匹配信息，等待完成。

随后在 `Output` 显示的文件夹中找到输出的音频文件，删除扩展为 `.accurip` 的文件。

### CUE 文件编码标准化

使用 Visual Studio Code 打开 `.cue` 文件，点击右下角编码类型处，以合适的编码打开使得文件文字显示正确。

随后再次点击右下角编码处，用 `UTF-8 with BOM` 保存。

### 处理扫图等附加数据

将附加的 CD 扫描图片或其他文件复制到 `.cue` 所在目录的独立文件夹中。

### 命名

用合适的方式命名 `.cue` 所在文件夹名称和扫图等附带文件的名称，做到：简介明了，格式统一。

### 转移

将标准化后的文件夹转移到归档文件夹，完成整个标准化过程。
