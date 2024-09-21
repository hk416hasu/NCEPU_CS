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
curl 'https://music.163.com/playlist?id=867381524' --compressed -H 'User-Agent: Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:130.0) Gecko/20100101 Firefox/130.0' -H 'Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/png,image/svg+xml,*/*;q=0.8' -H 'Accept-Language: zh-CN,zh;q=0.8,zh-TW;q=0.7,zh-HK;q=0.5,en-US;q=0.3,en;q=0.2' -H 'Accept-Encoding: gzip, deflate, br, zstd' -H 'Connection: keep-alive' -H 'Referer: https://music.163.com/' -H 'Cookie: NMTID=00Oc9z0o6P-z5Bmt0DbnBK5Dwlnf3MAAAGR-uDfJA; JSESSIONID-WYYY=M2H26JHJbwwc6pohvhUNVFTRF53MqAPDQlr1CDWAoKGh6dZdmHAh%2FkR0JsrvFnBtRc%2BR8nEJeik5FSW8UVctZqMHhzGNOp%2BAhJs%2FWt6pehsYfhqb%5CfqM9E83rSp9bmZ1MMwUrPSXSgX%2BS7JAUqQf0BvnvnPfzvFk69F16Qx9%2Fh9svOOR%3A1726900469274; _iuqxldmzr_=32; _ntes_nnid=866de37cea15bab49a71fbe897d54462,1726490927994; _ntes_nuid=866de37cea15bab49a71fbe897d54462; WEVNSM=1.0.0; WNMCID=hbskni.1726490929347.01.0; __snaker__id=iHrjaVdjH1qV36F1; ntes_utid=tid._.MXIa7wPxj9NFQhERVBKHF%252F%252BNuVW%252FeyCA._.0; WM_NI=Mh8Fez2RYtNNMJwpAuLr3uumm8rZ3WJTsKz1hn9Dq5UHEwc8P8je4VD5S63bXwAoQUsIj0ICv1K3eRvSgNVVqCM04VsV7Ra%2BqJP6vOrVKWCe0OQLMkmfUCs5fjPg9EdBZkk%3D; WM_NIKE=9ca17ae2e6ffcda170e2e6eeb0c15496a9bb90bb458ca88eb7c45e828b8bb0d65d96bcafa8e53a8b9ab6ccc12af0fea7c3b92a8fb8f8a7e872f28e9795cd468f96b991c47f90aefd96f867afe8bebbb25d8a8cbdacf93bacb2f7a5f43f97988b98e23494e8a686b75e88eb9dd7b26a9ca98f90d45fb197a6d1cc49b6ef85d4e85ab68da9afd55eb39d83d1b75eb18af9b3e421b396a0d7f545b28a85b8c26ff4919fadd061afba9ba4f23fa6b6a088bc4fa89e968cea37e2a3; WM_TID=KDmv%2FP1Df7lFURQVVBOHUv%2BcrRC6au1y; sDeviceId=YD-aq6%2B8BtqAgREA1FEABOCU6%2BN%2FRCqPyWf; gdxidpyhxdE=lqSa6fuTrO6x0wdHwzRLLHx57f%5CEZRfAnM6a3w%2BZBl16KewAJrxc%2BGW%2B0L%2Fg9qmldyBcE2t%5CP7DlL39neaHQijeWt9x1ipzfiiwre5n%2FppKDDleeviuQ%5Cq6Hr33G7OK9NmNikGkVk%5C5PG98G6pXZNyM8qtkJif8%2FwHqLvIfyXiCHXJJT%3A1726899576584; NTES_P_UTID=2iz9mdEY6boacUG8pAfsh51X0HFy2EdJ|1726490960; P_INFO=vbcgfh487882183@126.com|1726490960|0|music|00&99|CN&1726328817&mail126#heb&130600#10#0#0|&0|cloudmusic&mail126|vbcgfh487882183@126.com; __csrf=e900114d3c709bb5c9966f43702e635d; MUSIC_U=00E17B54BDBAC6B49AAEDC26988C5DF2B3E5DBCB94F4607779EF238E3FD49026199669819B45FAE45784D288D8B7BC2266D55760B013CE70B0D440ACA7E744C92C1958AB720B9FED2FB57F5FE0F2A0525170217DAA1C8AC80EDDE4F438A034334E7C4589B5684E531731B0CB0F218AA6139CCDD770440F542DD1B3F7A2FB8B443FE0483EE0CC837F789BB44F9E679CBF382263525CEEA2C119E346610DF4BBD87722801B5B2AAE9F3AFF59E937EAC244A9F241C9418896D8F0E6B4A2013523DC05824E56F0B6C016A9B202E2820E1B73790280D69F430DC2191D1AF240ED81A8DCBC9BF41918E10EB08E7E71AB3BDB28DC778D4F0CF988A2E7908B4B79F8C7E58FB584273F01F6037AD0B5F77081F07ACEB5C541DE7608A373AF1A8DFCB0EE0D127482AB3D2F13CEB9095ED5C09725A97A600DA90A45FF7B9D1AE49F5F2E0D8CE7; __remember_me=true; ntes_kaola_ad=1' -H 'Upgrade-Insecure-Requests: 1' -H 'Sec-Fetch-Dest: iframe' -H 'Sec-Fetch-Mode: navigate' -H 'Sec-Fetch-Site: same-origin' -H 'Priority: u=4' -H 'TE: trailers' -o thePlaylist.html

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

 Add metadata
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
