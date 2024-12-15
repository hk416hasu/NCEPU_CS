#!/bin/env bash

while [[ $(nmcli r wifi) != "enabled" || $(iwgetid -r) != "zywifibot" ]]; do
  nmcli r wifi on
  echo -n "wifi status: "
  nmcli r wifi
  nmcli d wifi connect zywifibot
  sleep 1
done

unset http_proxy
mpv --profile=low-latency "http://192.168.1.1:8080?action=stream"
