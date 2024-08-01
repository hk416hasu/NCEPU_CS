#!/bin/bash

#initial=( `cat "$startfile" | sed -e '/#/d' | tr -d '\n' |\
# 删除所有带'#'注释符号的行
#sed -e 's/\./\. /g' -e 's/_/_ /g'` )
# 摘录自脚本 life.sh


echo "The # here does not begin a comment."
echo 'The # here does not begin a comment.'
echo The \# here does not begin a comment.
echo The # here begins a comment.

echo ${PATH#*:}       # 参数替换而非注释
echo $(( 2#101010 ))  # 进制转换而非注释

echo "there is no whitespace."# may be okay too # not okay in fact!!!
echo "there is a whitespace." # this is okay

# 感谢S.C.
