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
curl 'https://music.163.com/playlist?id=867381524' --compressed \
-H 'User-Agent: Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:130.0) Gecko/20100101 Firefox/130.0' \
-H 'Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/png,image/svg+xml,*/*;q=0.8' \
-H 'Accept-Language: zh-CN,zh;q=0.8,zh-TW;q=0.7,zh-HK;q=0.5,en-US;q=0.3,en;q=0.2' \
-H 'Accept-Encoding: gzip, deflate, br, zstd' \
-H 'Connection: keep-alive' \
-H 'Referer: https://music.163.com/' \
-H 'Cookie: NMTID=00Oc9z0o6P-z5Bmt0DbnBK5Dwlnf3MAAAGR-uDfJA; JSESSIONID-WYYY=AmIW5OavUZoM%2F5vtYkANOvDj%2FRvvRhTzF3OZNvXE6Du4g6At3D72ykqpmr%5CsiJKqXSux%2BmJvzFqQpuTpakv4x%5C3o0PIEojAzrbZXKIfAG%2BMZSgXxRw3iJ2o1VVZwPgMQoHKmbQbUs530Y6n0PBsuEeKGNIdlqjRHfh7m%5CksRwigW30j7%3A1726492727967; _iuqxldmzr_=32; _ntes_nnid=866de37cea15bab49a71fbe897d54462,1726490927994; _ntes_nuid=866de37cea15bab49a71fbe897d54462; WEVNSM=1.0.0; WNMCID=hbskni.1726490929347.01.0; __snaker__id=iHrjaVdjH1qV36F1; ntes_utid=tid._.MXIa7wPxj9NFQhERVBKHF%252F%252BNuVW%252FeyCA._.0; WM_NI=DaQTM22dYUoccZMts0b%2FWlvyVy8elc1TCCd35t%2FvDNPyMeU7xHPB3U%2F08kSPOb4YVyQMCtXzRr8DeuFxS6H2uoBz9QqxVudiFq%2FHfTSVQYVb0SLufTKCAyzFWtVCuKWcUDQ%3D; WM_NIKE=9ca17ae2e6ffcda170e2e6eebab64b939a89a6b54ab1b88bb6d85f928b8a86c74be9e987d7d469928e98b9d92af0fea7c3b92a88bf9fb5d03af2bc97b6ee69a1868395f23ca2f1998df57396a7f886ef69f38c8da4e739f7ace197c74694a78386d83dbc98a0a3b25fedf0f88cd25c8dbefcbad57393938d95db7292aef8a5e87f86a89dd7cb3ab7b18e9bbc5bb3a89a96e76386afe1a9e560918a9fbad56af48d8496e560899d8f9af94e95ac9aa4f84195bd9ba5d437e2a3; WM_TID=KDmv%2FP1Df7lFURQVVBOHUv%2BcrRC6au1y; sDeviceId=YD-aq6%2B8BtqAgREA1FEABOCU6%2BN%2FRCqPyWf; gdxidpyhxdE=NOv8%5CLTVRPWONA%5CuNDDbNYus5rHrh2IZHuQ8nagv0Vof0DJkUapCYMlqJPLDdgcSNWt%5ChRqJf6%5CAqEO7LZYdnVfWLYCfL5fRWRAsVTvzn5w6Dx5xGza8Mgk%2Bs97SP8Sgaa5qDyZVEAdbDz2HiiO5eg%2B9KU1sbXRzU%5C0fQD0jBwPIpBiE%3A1726491835759; NTES_P_UTID=2iz9mdEY6boacUG8pAfsh51X0HFy2EdJ|1726490960; NTES_SESS=yf65lMtoc3FYkLcC6e66gLDLVFAC3nKqbmZmB0jfLAlEwsISwc4gjpUVsMxqax.jgjTn4c0nV01K_tjXcq.0jmlm0KXgDnyipUN3nCGD3ixXpucx7fLUv_G5KsP5oDBKcWzE5F0Uvo.YOpc0HUZlTkS2C2W6K0s1W15vUVY12up9c4Or_ZnNU4F0K0N.RJ1FKtZD8VdZ8ajDVjmy5Sjb5vCqzMf9MrPon; S_INFO=1726490960|0|#3&80#|vbcgfh487882183@126.com; P_INFO=vbcgfh487882183@126.com|1726490960|0|music|00&99|CN&1726328817&mail126#heb&130600#10#0#0|&0|cloudmusic&mail126|vbcgfh487882183@126.com; __csrf=cfeea6117caa7fd207bb65982bb8a9da; MUSIC_U=00FC8CD375C194CC85F9B1F0698B8C08524E0E329292E7FF0977E26187D66B4EE558D610A0340B677294EA320DCAFA1CF403B2336FF9095A15F586C3BE9D5FBA8A0F9DDD037EAABB28F27AAC5105F49FF345357132B58CD4CD1490B958E10E5A0BE614E0C38FF6A4E4711F68DE16A72166C1C9464255916B652FD0FA6018BAED0C64140FE68DE04FC9343B902465824B2A52D714AFEA6BED3F289D65E07581E90D8208EB13552E42C48817E2F8A1637DA604630CA18BC567C70B4A4C129B331D9208881654EA3DDC3C7C21EFC995D238D33A37992182CF84FDAAC120E1748E791BE661B4392C3E7E9891E6132A58ED900C614D9C0F5B9ADD4A6D16CD29B4C5106C2D4BBF289F34C924412241B15E7C2BF4EB039E588FDAF53B30B2FFE999031BDC4DCEC7D8713D596C1A9D0BBF645A25E3D90809A71B3D459C6ED541B282FCC91D; __remember_me=true; ntes_kaola_ad=1' \
-H 'Upgrade-Insecure-Requests: 1' \
-H 'Sec-Fetch-Dest: iframe' \
-H 'Sec-Fetch-Mode: navigate' \
-H 'Sec-Fetch-Site: same-origin' \
-H 'Priority: u=4' \
-H 'TE: trailers' \
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
