your_name="runoob"
# 使用双引号拼接
greeting_0="hello, "$your_name" !"
greeting_1="hello, ${your_name} !"
echo $greeting_0  $greeting_1

# 使用单引号拼接
greeting_2='hello, '$your_name' !'
greeting_3='hello, ${your_name} !'
echo $greeting_2  $greeting_3
