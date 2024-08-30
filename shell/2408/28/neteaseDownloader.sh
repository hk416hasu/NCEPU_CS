#!/bin/env bash

# Wifi diagnose
if [[ $(nmcli r wifi) = "disabled" ]]; then
    nmcli radio wifi on
    sleep 6
fi

# Download the html of playlist, but just mine
# I wish it can be updated to download any playlist with its ID
if [[ -d tmp ]]; then rm -r tmp; fi
mkdir tmp && cd tmp || exit 1
# read playlistID
# test that playlistID
curl 'https://music.163.com/playlist?id=867381524' --compressed  \
-H 'User-Agent: Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:129.0) Gecko/20100101 Firefox/129.0'  \
-H 'Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/png,image/svg+xml,*/*;q=0.8'  \
-H 'Accept-Language: zh-CN,zh;q=0.8,zh-TW;q=0.7,zh-HK;q=0.5,en-US;q=0.3,en;q=0.2'  \
-H 'Accept-Encoding: gzip, deflate, br, zstd'  \
-H 'Connection: keep-alive'  \
-H 'Referer: https://music.163.com/'  \
-H 'Cookie: NMTID=00OREChodneVcoWpUtsqSBkWb_VMGQAAAGRfwDQWg; JSESSIONID-WYYY=rCmTbFS0yDd7vDHnbwIiUFbq%2BDycUdcM3eFIRV07bfRkUwOqyKvuycH%2BsvwdJDcpjEOcqJz0AGrXiyKXgXMvTxum5EEwyBNhr5M%2Fc8d5JEkxP0txgwK1cIm6elIDkIJy6A9j6tzZBiJawOfmWSxGo%2BfWXyj15I%2Fu5THVG2rS5oRTVRRK%3A1724998004160; _iuqxldmzr_=32; _ntes_nnid=b9aeef9434f0da9a2600fb6d78a52dd8,1724412646507; _ntes_nuid=b9aeef9434f0da9a2600fb6d78a52dd8; WEVNSM=1.0.0; WNMCID=ehshzf.1724412647896.01.0; __snaker__id=tZZJhZvkhBJ3Ecrb; ntes_utid=tid._.RoZSZelViQJFBlRRRUbTU3u%252FFEC80vjG._.0; WM_NI=hEpMyymQtfE%2FphptKpLmdTByUyRtQoCWBFu0dP1WinhS5%2F2DsgB4e2XJskl2%2FGHoyU%2BoGVBqZsZG2t3FzIuOYaa45RUVqPv8iRmCJTYBPDD7pDWQPLw1ANG6xkKfZMGWRmg%3D; WM_NIKE=9ca17ae2e6ffcda170e2e6ee94c96ee9ec9ad7f75cb29e8bb7d55e829b9a86d64afca89c8ae573b0a69dd4f02af0fea7c3b92aac9bc0aefc73af8fbc87c825b4b8c095ca7c90b3acb5c17397a79e95d46581898ea7f83ca890ffb8ec66ac8dfbd0b150b1b98ed5e83a9c96bd8cef3aed998890fc5fe9b189b7c17b9aad96a8b180f19ab6aaf8459bbfafd5b85a978abfb1f534ab8ea3a4c9609b9ea0a5c73db49c99b2d348b5ef8fafc63ebcb58587d94785899e8ee637e2a3; WM_TID=BLeBEB3RlMREFFVBUAfSAj%2BqRQC5m11f; sDeviceId=YD-TEet1J3UjTFFV1BUEVPSVyv6BVTojZij; gdxidpyhxdE=liuJSvkthrWMHMS8DCxUTzcbY92tcWdOGyODo7R%2FpROZds4cmwRnvPwULoee%2BbHN7u%5C5u7UR1M04%2FadcJA7yObYHNXduR%2BztAbLic6t6ipiC2r%5CoBV%2F9WTthvJJ3Wgq0bjcDm23pGfXV8xz8tuM5tW9NKBNk6J%2B0CUGjGuwogBXYouSj%3A1724413552801; NTES_P_UTID=FOY7jo4JdmXNnFFYCVrE6Uesz2Sill54|1724412677; P_INFO=vbcgfh487882183@126.com|1724412677|0|music|00&99|null&null&null#shh&null#10#0#0|&0|cloudmusic&mail126|vbcgfh487882183@126.com; __csrf=b07d62a99e5a8bf61d7d6c9868fa626a; MUSIC_U=001F91E4EBCCA0AB417E1718D71677C3A23C4489B52C6F47DA765B2D050B8D93087DF5F3F2246F0592F5022FD2002858AFF7AF164DC403015DC554F28B7A3E2B56D938E889B0931175F724F5346CA7EEC416E11371C3BF91A563BB631A0D5172E6363EDFB9DDC5998BDCD83461B01BEAC678191975B24B93818E7D4CBDEF0D895E9EA47BE3383C24595994E05B5C700DF0EC4F32AA8FDE5BD29D41D9C56E73A23291B1F1D2F872E6D294842B346447B52646D0078A42E7BDE96B5B29450852E0D453D624062EA6A8CD6DA4B4A0192613A852F14357440D0C535ECA389A4D9694B032AA02893FBE85CCB0DE9BF0C245E35E3008F5F0D935B33FC3005558E6E0948D59A504136613A884DABB0A2CF3C721A08BCE02EAD8D0BAB8C3C86B6D0BFB15EBC282FDCC1DCFB0CAE09B9F74191D3A4C; __remember_me=true; ntes_kaola_ad=1; NTES_SESS=6AaFeUqTcltonbpT2P0.X0RB4e7xC7h4JejyhHyd199315ST1ltocJyp5N_hq_acocXPtlePpe3DWgcFlhaecKxKeDFowP6QJGUojR4yZ8.cXFnu1tO1t_v9wKznSKuXl_XB9RKxswmz.xcb1p.DwOUas8liHDbh_i4DmOaWUjq_9UvD9wA_TYYiBXsuVwjOTqihUs1bsFIdLtuUbrWqVpxTa8JW2.U8U; S_INFO=1724412677|0|#3&80#|vbcgfh487882183@126.com; playerid=98867437'  \
-H 'Upgrade-Insecure-Requests: 1'  \
-H 'Sec-Fetch-Dest: iframe'  \
-H 'Sec-Fetch-Mode: navigate'  \
-H 'Sec-Fetch-Site: same-origin'  \
-H 'Priority: u=4'  \
-H 'TE: trailers'  \
-o thePlaylist.html

# Data Wrangling 1 : Get all Songs in 'thePlaylist.html'
# Get the Songs Line in that html (line 404)
sed -n '404p' thePlaylist.html > favSongs 
# make it cleaner and line-by-line
sed -E 's/<ul\ class=\"f-hide\">//g' favSongs > favSong_tmp
rm favSongs && mv favSong_tmp favSongs
sed -E 's/<\/ul>//g' favSongs > favSong_tmp
rm favSongs && mv favSong_tmp favSongs
sed -E 's/(<\/li>)/\1\n/g' favSongs > favSong_tmp
rm favSongs && mv favSong_tmp favSongs

# Data Wrangling 2 : Generate the curl.sh
sed -E 's/.*\"\/song(\?id=[0-9]+)\">(.*)<\/a><\/li>/curl\ -L\ https:\/\/music.163.com\/song\/media\/outer\/url\1\ \-o\ \"\2.mp3\"/g' favSongs > curl.sh

# Download as wish
echo "plz enter how many songs would u like to download"
read -r num
if [[ ! "$num" =~ ^[0-9]+$ ]]; then
    echo "plz enter correct num"
    exit 2
fi
head -n "$num" curl.sh > downloadList
bash downloadList

# Add metadata
for file in *.mp3; do
    ffmpeg -i "file:$file" -metadata title="${file%.mp3}" -codec copy "tmp_$file"
        # the "files:" prefix tells ffmpeg to treat the following string as a file path
        # , avoiding the protocol confusion
    # Make sure the dir exist
    if [[ ! -d "$HOME/Music/fav" ]]; then
        echo 'the ~/Music/fav does not exist!'
        exit 3
    fi
    mv "tmp_$file" "$HOME/Music/fav/$file"
done

# Clean
cd ../
rm -r tmp

exit 0
