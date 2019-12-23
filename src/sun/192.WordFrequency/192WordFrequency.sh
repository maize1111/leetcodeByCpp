# Read from the file words.txt and output the word frequency list to stdout.
# cat 显示一个已有文件
#xargs 将换行和空格都转换为空格， -n 为每行指定列数
# awk 文本处理
# 桶排序
# sort -rn 将数字倒序排列
cat words.txt | xargs -n 1 | awk '{
    if($1 in data)
        data[$1] = data[$1] + 1
    else
        data[$1] = 1
 } END {for(str in data) print data[str],str}' | sort -rn | awk '{print $2, $1}'

