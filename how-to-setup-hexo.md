---
title: 简单搭建 Hexo 博客教程
date: 2020-03-30 14:20:44
tags:
---

## Hexo 搭建过程及注意事项

本文简单记录一下本博客使用 `Hexo` 的搭建过程，和一些注意事项。

### Step 1. 安装 Node.js

在 [Node.js 官网](https://nodejs.org/en/) 下载好 Node.js 并安装。

### Step 2. 安装 & 初始化 Hexo

按照 [Hexo 官网](https://hexo.io/) 的步骤，操作如下。

首先，使用 `npm` 安装 Hexo。（注：以下操作均以 `powershell` 下为准。写作时在 Windows 10 1909）

```powershell
> npm install hexo-cli -g
```

然后，`cd` 到你想建立的博客主目录，然后初始化 Hexo，安装依赖。

```powershell
> hexo init
> npm install
```

然后可以试着生成一下了，执行

```powershell
> hexo clean
> hexo g
> hexo s
```

打开 `http://127.0.0.1:4000` 便可查看预览，若正常，则可以继续。

然后，可以打开主目录的 `_config.yml` 进行一些基本的设置更改。比如：

```YAML
title: NeterOster's Blog
url: http://blog.neteroster.live
```

当然，有需要可以自行更改其他设置。

### Step 3. 设定 git & 绑定域名

这里先留个坑，以后详细讲讲 `git` 和 `gpg` 签名的事情。

总之，在配置完 `git` 以后。安装 Hexo 的 `git` 部署插件。

博客主目录运行

```powershell
> npm install hexo-deployer-git --save
```

然后打开在你的博客主目录的 `_config.yml`

找到 `deploy` 部分，配置如下。（其中请自行更改项目地址）

```YAML
deploy:
  type: 'git'
  repository: https://github.com/neteroster/neteroster.github.io
  branch: master
```

接下来绑定自己的域名，这里以 `blog.neteroster.live` 为例。

首先在你的域名服务商添加一个 `CNAME` 记录，比如 `blog.neteroster.live`，值为 `neteroster.github.io` （按自己的更改）。

然后在主目录的 `source` 文件夹下，建一个 `CNAME` 文件，值为（按需要更改）

```
blog.neteroster.live
```

然后执行

```powershell
> hexo clean
> hexo g
> hexo d
```

即可立即将博客推送到 Github，过几分钟便可以通过 `blog.neteroster.live` 访问了。

### Step 4. 配置主题，打开数学公式支持

这里以 [NexT](https://github.com/theme-next/hexo-theme-next) 主题为例，其他主题大同小异。

在博客主目录，运行

```powershell
> git clone https://github.com/theme-next/hexo-theme-next themes/next
```

然后打开主目录的 `_config.yml`，找到 `theme` 部分，修改为

```YAML
theme: next
```

然后执行

```powershell
> hexo clean
> hexo g
> hexo s
```

打开 `http://127.0.0.1:4000` 便可以查看预览了。

接下来按照 [NexT 官方教程](https://github.com/theme-next/hexo-theme-next/blob/master/docs/zh-CN/MATH.md) 打开数学公式支持。

首先，下载并安装 [Pandoc](https://pandoc.org/)。

然后，在博客主目录执行：

```powershell
> npm uninstall hexo-renderer-marked
> npm install hexo-renderer-pandoc
```

然后，打开主目录中 `themes\next\_config.yml` 文件，找到 `math` 部分，更改如下。

```YAML
math:
  per_page: true

  mathjax:
    enable: true
    mhchem: false

  katex:
    enable: false
    copy_tex: false
```

这样便成功打开了数学公式支持（LaTeX）。需要注意的是，需要渲染的 `post` 开头必须要有 `mathjax: true` 才能渲染公式，例如。

```
---
title: how-to-setup-hexo
date: 2020-03-30 14:20:44
tags:
mathjax: true
---
```

接下来可以在 `themes\next\_config.yml` 进行一些基本设置。例如设置社交链接

```YAML
social:
  GitHub: https://github.com/neteroster || github
  E-Mail: mailto:neteroster@gmail.com || envelope
```

CC 授权信息：

```YAML
creative_commons:
  license: by-nc-sa
  sidebar: true
  post: true
  language:
```

等。

完成后，推送更改至 Github。

```powershell
> hexo clean
> hexo g
> hexo d
```

等待几分钟，打开网页即可。

### Step 5. 配置 SiteMap 便于收录

通过实现 `sitemap`，可以让你的博客更容易被搜索引擎收录。

在博客主目录执行

```powershell
> npm install hexo-generator-sitemap --save
```

然后重新部署

```powershell
> hexo clean
> hexo g
> hexo d
```

访问 `https://blog.neteroster.live/sitemap.xml` 即可验证（需要换为自己的地址）。

至此，你的博客基本配置完毕，Enjoy!

## 常用命令

* `hexo new post <NAME>` 新文章，以 `<NAME>` 为题。