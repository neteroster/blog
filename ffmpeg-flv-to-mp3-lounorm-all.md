---
title: 使用 PowerShell 脚本批量将 flv 和 mp4 转换为 mp3 并统一音量
date: 2020-04-03 10:08:14
tags:
---

## Introduction

因为最近想搞个项目，把泠鸢的所有直播歌曲都下载下来并批量处理，便诞生了这个项目。

## Script

很简单，一行。

```powershell
# This script is used to convert all .flv and .mp4 files in a folder to .mp3, and automatically adjust volume to ~23 LUFS.
# Put `ffmpeg.exe` in the same folder where this PowerShell script lies in.

Get-ChildItem | Where-Object {$_.Extension -eq ".mp4" -or $_.Extension -eq ".flv"} | ForEach-Object { ./ffmpeg.exe -i $_.Name -af "loudnorm=print_format=summary" -vn -sn -dn -f mp3 -ab 192000 ($_.BaseName + ".mp3")}
```

运用了 PowerShell 的管道。不得不说管道很强大！

把这个命名为 `ConvertAll.ps1` 然后把 `ffmpeg.exe` 和所有要转换的 `.flv` 放在和这个脚本同一个文件夹，运行即可。

