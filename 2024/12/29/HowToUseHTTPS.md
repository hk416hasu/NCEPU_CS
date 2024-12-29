It's important and convenient to use HTTPS to enhance your website safety.
So How to use HTTPS on your websites **for free**?

我使用 Let’s Encrypt 获取免费 HTTPS 证书

### 1. Install Certbot
It's an auto-config tool provided by Let's Encrypt.
```bash
sudo apt update
sudo apt install certbot python3-certbot-nginx
```

### 2. Config Nginx
Certbot 需要通过 HTTP 验证域名, 保留http服务即可。

1. install nginx
```bash
sudo apt install nginx
```

2. 编辑 Nginx 配置文件 `/etc/nginx/sites-available/default`:
```nginx
server {
  listen 80 default_server;
  listen [::]:80 default_server;

  root /var/www/html;

  index index.html index.htm index.nginx-debian.html;

  server_name _;

  location / {
    try_files $uri $uri/ =404;
  }
```

3. 测试并启动 Nginx
```bash
sudo nginx -t
sudo systemctl restart nginx
```

### 3. 使用 Certbot 获取 HTTPS 证书
运行 Certbot 命令，获取证书：
```bash
sudo certbot --nginx -d hk416hasu.fun -d www.hk416hasu.fun
```
Certbot 会自动配置 Nginx 为 HTTPS。
如果成功，证书会被保存到 /etc/letsencrypt/live/hk416hasu.fun/。

### 4. 自动续订证书
Let’s Encrypt 的证书有效期为 90 天，Certbot 可以自动续订。
测试自动续订
```bash
sudo certbot renew --dry-run
```
如果没有错误，Certbot 会定期自动续订。

### 附录

这是我使用Nginx + Express的nginx配置

```nginx
# 处理 HTTP 请求
server {
    listen 80 default_server;
    listen [::]:80 default_server;

    # 重定向所有 HTTP 请求到 HTTPS
    return 301 https://$host$request_uri;
}

# 处理 HTTPS 请求
server {
    listen 443 ssl default_server;
    listen [::]:443 ssl default_server;

    # 配置 SSL 证书
    ssl_certificate /etc/letsencrypt/live/hk416hasu.fun/fullchain.pem;
    ssl_certificate_key /etc/letsencrypt/live/hk416hasu.fun/privkey.pem;

    ssl_protocols TLSv1.2 TLSv1.3;
    ssl_prefer_server_ciphers on;

    # 静态文件的根目录
    root /home/ubuntu/web/public;

    # 默认首页文件
    index index.html index.htm index.nginx-debian.html;

    # 定义服务器名称
    server_name hk416hasu.fun www.hk416hasu.fun;

    # 处理静态文件
    # location /static/ {
    #     root /home/ubuntu/web/public; # should in ~/web/public/static
    # }

    # 转发 API 请求到 Express 应用
    location /api/ {
        proxy_pass http://localhost:3000; # Express 应用监听的端口
        proxy_http_version 1.1;
        proxy_set_header Upgrade $http_upgrade;
        proxy_set_header Connection 'upgrade';
        proxy_set_header Host $host;
        proxy_cache_bypass $http_upgrade;
    }

    # 所有其他请求也转发到 Express
    location / {
        proxy_pass http://localhost:3000;
        proxy_http_version 1.1;
        proxy_set_header Upgrade $http_upgrade;
        proxy_set_header Connection 'upgrade';
        proxy_set_header Host $host;
        proxy_cache_bypass $http_upgrade;
    }
}
```
