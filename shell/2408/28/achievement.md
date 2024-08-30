the long complicated curl command can be divided to this:

curl 'https://music.163.com/playlist?id=867381524' \
--compressed \
-H 'User-Agent: Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:129.0) Gecko/20100101 Firefox/129.0' \
-H 'Referer: https://music.163.com/' \
-H 'Cookie: NMTID=00OREChodneVcoWpUtsqSBkWb_VMGQAAAGRfwDQWg' \
-H 'head4' \
... \
... \
-o playlist.html

---

u need to curl/wget this url(with heads):
    'https://music.163.com/playlist?id=867381524'
not this:
    'https://music.163.com/#/playlist?id=867381524'

---

some heads may be not necessary, u can try it in firefox F12-network-"some like console, 编辑并重发"
    and manage your heads. Or u can edit the ./neteaseDownloader.sh
Additionally, u can find the real url in that "console"

---

" view-source: " is a pretocol like http: or ftp: or file:
