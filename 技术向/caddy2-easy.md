---
title: Caddy 2 真的很方便！
date: 2020-04-30 07:55:54
tags:
---

最近发现 Caddy 2 用如下 `Caddyfile` 就能自动实现 HTTPS + SNI(不同域名都用 443 端口，反代到不同服务)。

```
https://xxx1.neteroster.live {
	reverse_proxy 127.0.0.1:1234
}

https://xxx2.neteroster.live {
	reverse_proxy 127.0.0.1:5678
}
```

这样访问 `https://xxx1.neteroster.live` 就相当于用 HTTPS 访问 `https://127.0.0.1:1234`，`xxx2` 同理。